
sqlite_chkmsgzhuce(struct zhuce_st zc)
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

}

int main()
{
	// 搭建socket

	while(1)
	{
	// 收注册包

	//检查信息的真伪,并将注册的用户信息存放到数据库中
	sqlite_chkmsgzhuce();

	// 回复注册状态
	
	}


	exit(0);
}













