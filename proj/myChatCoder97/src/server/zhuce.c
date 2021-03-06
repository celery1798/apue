
int create_table_for_user()
{
	char *sql

	ret = sqlite3_open(,&db);
	if()
	{

	}

	sql = "create table if not exists user(no integer primery key autoincrement not null , uname text not null,password text not null)";
	
	ret = sqlite3_exec(db,sql,NULL,NULL,NULL); //适用于创建,删除,不适合用于查询
	if(ret != SQLITE_OK)
	{
		
	}
	
	sqlite3_close(db);
	return 0;
}

int sqlite_chkmsgzhuce(struct zhuce_st *zc)
{
	
	ret = sqlite3_open("./mychat.sqlite",&db);	
	if(ret != SQLITE_OK)
	{
		fprintf(stderr,"sqlite3_open() failed.\n");
		return -2;
	}	

	sql = "select * from user where uname = ?";

	ret = sqlite3_prepare_v2(db,sql,-1, &stmt, NULL);
	if(ret != SQLITE_OK)
		return -3;

	sqlite3_bind_text(stmt,1,zc->uname, -1, NULL);

	ret = sqlite3_step(stmt);	
	if(ret == SQLITE_ROW)
	{//在user表中找到了同名的记录,注册失败,因为同名用户已存在
		return -1;		
	}
	else	//无同名用户,可以实现注册,将新用户的信息写数据库
	{

/*
		char *sql;
		sql = "insert into user(uname,password) values ( ?, ? )";
	
		ret = sqlite3_prepare_v2(db,sql,-1, &stmt, NULL);
    if(ret != SQLITE_OK)
        return -3;
	
	sqlite3_bind_text(stmt,1,zc->uname, -1, NULL);
	sqlite3_bind_text(stmt,2,zc->password, -1, NULL);		
	
	ret = sqlite3_step(stmt);
    if(ret != SQLITE_ROW)
	{

	}
*/

	char *sql = malloc(1024);

	sprintf(sql,"insert into user(uname,password) values ( '%s', '%s' )",zc->uname,zc->password);

	sqlite3_exec(  sql   );

	}


}


int main()
{
	struct zhuce_st zc;

	// 搭建socket


	// 创建用户表
	create_table_for_user();

	while(1)
	{
	// 收注册包
		zc;

	//检查信息的真伪,并将注册的用户信息存放到数据库中
	sqlite_chkmsgzhuce(&zc);

	// 回复注册状态
	
	}


	exit(0);
}













