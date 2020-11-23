#include "head4.h"


angle::angle(int fl,int d, int m, double s) :flag(fl),degree(d),minute(m),second(s){
	//�����ִ˾���ʱ��˵����ֵ�����˴�λ���Ƕȵķ�Χһ���Ǵ���0���
	if(fl!=1&&fl!=-1){ cerr << "�Ƕȳ�ʼ�����Ŵ���" << endl; return; }
	if (degree < 0 ) { cerr << "�Ƕȳ�ʼ������" << endl; return; }
	if (minute < 0 || minute >= 60) { cerr << "�Ƕȳ�ʼ������" << endl; return; }
	if (second < 0 || second >= 60) { cerr << "�Ƕȳ�ʼ������" << endl; return; }
}

double angle::PI = 3.1415926;
double angle::rad = 648000;
  angle::operator double() {
	  double k;
	  k = second_count();
	  k = (PI * k) / rad;
	  return k*flag;
}
  //ת�����캯��������޵��еؽ���һ�������������г�Ա��Ҫ��ʼ��
  //���飺���캯��������ǰ��д�������Լ�
  angle::angle(double x) {
	  double w = (x / PI) * rad;
	  to_angle(w);
  }

  void angle::set(int f,int d,int m,double s) {
	  flag = f; degree = d; minute = m; second = s;
  }

angle operator+(angle& a, angle& b) {
	angle c;
	double x; x = a.flag * a.second_count() + b.flag * b.second_count();
	c.to_angle(x);
	return c;
}
angle operator-(angle& a, angle& b) {
	angle c; 
		c.to_angle(a.flag*a.second_count() - b.flag*b.second_count());
	return c;
}
angle operator *(angle& a, double p) {
	angle c; double q;
	q = p * a.second_count();
	c.to_angle(q);
	return c;
}
angle operator /(angle& a, double p) {
	angle c; double q;
	q = a.second_count() / p;
	c.to_angle(q);
	return c;
}
bool operator>(angle& a, angle& b) {
	if (a.flag*double(a) > b.flag*double(b))return true;
	else return false;
}



double angle::second_count() {
	return (double(degree) * 3600 + double(minute) * 60 +second );
}
//��ת�Ƕ�
void angle::to_angle(double x) {
	if (x < 0) { flag = -1; x = flag*x; }
	else flag = 1;//���������һ�У���Ϊ���캯��Ҫ��
	degree = int(x / 3600); x = x - double(degree) * 3600;
	minute = int(x / 60); x = x - double(minute) * 60;
	second = x;
}

void angle::display() {
	if (degree != 0)
		cout << flag * degree << "��" << minute << "��" << second << "��" << endl;
	else if (minute != 0)
	{
		cout << "0��" << flag * minute << "��" << second << "��" << endl;
	}
	else cout << "0��0��" << flag * second << "��" << endl;
}
