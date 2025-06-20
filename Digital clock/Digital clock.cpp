#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
struct  stClock 
{
	int Hours=0;
	short Minute = 0;
	short Second = 0;
};
int ReadHours()
{
	int H;
	cout << "Hours : ";
	cin >> H;
	while (H<0||cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "You Should A Enter Number ^_^ \n";
		cin >> H;
	}
	return H;
}
int ReadMinute()
{
	int M;
	cout << "Minute : ";
	cin >> M;
	while (M<0||cin.fail()||M>59)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "You Should Enter A Number ^_^\n";
		cin >> M;
	}
	return M;
}
int ReadSecond()
{
	int S;
	cout << "Seconds : ";
	cin >> S;
	while (S<0||cin.fail()||S>59)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "You Should Enter A Number  ^_^\n";
		cin >> S;
	}
	return S;
}
stClock EditHours_Minute_Second(stClock c) 
{
	if (c.Second==60)
	{
		c.Second = 0;
		c.Minute++;
	}
	if (c.Minute ==60)
	{
		c.Minute = 0;
		c.Hours++;
	}
	return c;
}
void PrintClock(stClock c)
{
	cout << c.Hours << " : " << c.Minute << " : " << c.Second<<"\n";
	this_thread::sleep_for(chrono::seconds(1));
	system("cls");
}
void SmartCalculator()
{
	stClock Clock;
	Clock.Hours = ReadHours();
	Clock.Minute = ReadMinute();
	Clock.Second = ReadSecond();
	while (true)
	{
		PrintClock(Clock);
		Clock.Second++;
		Clock = EditHours_Minute_Second(Clock);
	}

}
int main()
{
		SmartCalculator();
		  return 0;
}
