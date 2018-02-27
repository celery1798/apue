#include <iostream>
using namespace std;

class Time
{
public:
	Time();	//构造函数(初始化),实例化一个对象时默认隐式被调用的	
	Time(int h,int m,int s);		// 构造函数
	void SetTime(int ,int ,int);
	void ShowTime();
	~Time();	//析构函数,一个对象即将消亡时被默认调用的
private:
	int hour,minute,second;
};

Time::Time()
{
	cout << "Time()" << endl;
	hour =  minute = second = 0;
}

Time::Time(int h,int m,int s)
{
	cout << "Time(3*int)" << endl;
	hour = h;
    minute = m;
    second = s;
}

Time::~Time()
{
	cout << "~Time" << endl;
}

void Time::SetTime(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::ShowTime()
{
	cout << hour << ":" << minute << ":" << second << endl;	
}

int main()
{
	Time t1;

	t1.ShowTime();

	t1.SetTime(10,10,10);	
	t1.ShowTime();


	return 0;
}




