#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <sqlite3.h>

#include <proto.h>


int create_table_for_onlineuser()
{
	ret = sqlite3_open("./mychat.sqlite",&db);
    if(   )
    {

    }

    sql = "create table if not exists onlineuser(no integer primery key autoincrement not null , uname text not null, addr blob";   // alive text;

    ret = sqlite3_exec(db,sql,NULL,NULL,NULL); //适用于创建,删除,不适合用于查询
    if(ret != SQLITE_OK)
    {

    }

    sqlite3_close(db);
	return 0;
}

save_addrtotable(struct sockaddr_in *raddr)
{

	sqlite3_open();
	if()
	{

	}

	//在onlineuser表中找本用户是否存在
	// 1 用户存在 update 


	







	// 2用户不存在,insert

	char *sql;
	sql = "insert into onlineuser(uname,addr) values ( ?, ? )";
	
		ret = sqlite3_prepare_v2(db,sql,-1, &stmt, NULL);
    if(ret != SQLITE_OK)
        return -3;
	
	sqlite3_bind_text(stmt,1,   ->uname, -1, NULL);
	sqlite3_bind_blob(stmt,2,raddr,sizeof(raddr),NULL);	
	
	ret = sqlite3_step(stmt);
    if(ret != SQLITE_ROW)
	{

	}





}


int sqlite_chkckdenglu(struct denglu_st *dl)
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	char *sql;
	int ret;

//	printf("%s %s\n",dl->uname,dl->password);

	ret = sqlite3_open("./mychat.sqlite",&db);	
	if(ret != SQLITE_OK)
	{
		fprintf(stderr,"sqlite3_open() failed.\n");
		return -2;
	}	

	sql = "select * from user where uname = ? and password = ?";

	ret = sqlite3_prepare_v2(db,sql,-1, &stmt, NULL);
	if(ret != SQLITE_OK)
		return -3;

	sqlite3_bind_text(stmt,1,dl->uname, -1, NULL);
	sqlite3_bind_text(stmt,2,dl->password, -1 , NULL);

	ret = sqlite3_step(stmt);	
	if(ret != SQLITE_ROW)
	{
		return -1;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

//	printf("Check over.\n");	

	return  0;
}

int main(int argc,char **argv)
{
    int sd;
    struct sockaddr_in laddr,raddr;
	socklen_t raddr_len;
    struct denglu_st dl;
	int ret;

    sd = socket(AF_INET,SOCK_DGRAM,0);
    if(sd < 0)
    {
        perror("socket()");
        exit(1);
    }

	laddr.sin_family = AF_INET;
    laddr.sin_port = htons(DENGLU_SERVER_PORT);
    inet_pton(AF_INET,DEFAULT_SERVER_IP,&laddr.sin_addr);
    if(bind(sd,(void *)&laddr,sizeof(laddr)) < 0)
    {
        perror("bind()");
        exit(1);
    }
	
	//创建数据库
	create_table_for_onlineuser();


	raddr_len = sizeof(raddr);

	while(1)
	{
		// 接收请求登陆的包
		if(recvfrom(sd,&dl,sizeof(dl),0,(void *)&raddr,&raddr_len) < 0)
		{
			perror("recvfrom()");
			exit(1);
		}

		// 去往数据库,验证登陆信息
		ret = sqlite_chkckdenglu(&dl);
		if(ret == 0)
		{
			dl.status = DENGLU_STATUS_OK;

			//将当前用户的地址信息写入数据库的onlineuser表中
			save_addrtotable(&raddr);
		

		}
		else if(ret == -1)
				dl.status = DENGLU_STATUS_ERROR;
		else
		{
				//数据库出现问题,请及时解决
			fprintf(stderr,"sqlite_chkckdenglu() failed.\n");
			exit(1);
		}
		
		//给客户端回复登陆结果
		if(sendto(sd,&dl,sizeof(dl),0,(void *)&raddr,sizeof(raddr)) < 0)
		{
			perror("sendto()");
			exit(1);
		}

		puts("ok!");

	}


	close(sd);

	exit(0);

}

