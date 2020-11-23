#include <iostream>
#include <fstream>
using namespace std;

class angle {
public:
	angle(double);//转换构造函数
	operator double();//类型转换函数
	angle(int flag=1,int degree=0, int minute=0, double second=0);

	void set(int,int,int,double);
	double second_count();
	void to_angle(double);

	friend angle operator +(angle&, angle&);
	friend angle operator -(angle&, angle&);
	friend angle operator *(angle&, double);
	friend angle operator /(angle&, double);
	friend bool operator >(angle&, angle&);


	void display();

private:
	int flag;//角度正负标记
	int degree;
	int minute;
	double second;
	static double PI ;
	static double rad;
};


