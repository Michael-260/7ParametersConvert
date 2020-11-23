#include <iostream>
#include <fstream>
using namespace std;

class angle {
public:
	angle(double);//ת�����캯��
	operator double();//����ת������
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
	int flag;//�Ƕ��������
	int degree;
	int minute;
	double second;
	static double PI ;
	static double rad;
};


