#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

//����һ���ַ�������Ӧ�Ĺ���ƥ�������
/*����������2���ָ��ʶ��
* @param str �������ݵ��ַ���
* @param flag1 �ָ��ַ���1
* @param flag2 �ָ��ַ���2
*/
vector<string> analyse(string str, string flag1, string flag2) {
	size_t pos = 0, i = 0; vector<string> result; size_t size = str.size();

	pos = str.find_first_of(flag1, i);
	if (pos < size) {
		string s = str.substr(i, pos);
		result.push_back(s);
		i = pos + flag1.size();
	}
	pos = str.find_first_of(flag2, i);
	if (pos < size) {
		string s = str.substr(i, pos - i);
		result.push_back(s);
		i = pos + flag2.size();
	}
	string s = str.substr(i,size-i);
	result.push_back(s);

	return result;
}
/*���������������ָ��ʶ��
* @param str �������ݵ��ַ���
* @param flag1 �ָ��ַ���1
* @param flag2 �ָ��ַ���2
* @param flag �ָ��ַ���3
*/
vector<string> analyse(string str, string flag1, string flag2, string flag) {
	size_t pos = 0, i = 0; vector<string> result; size_t size = str.size();

	pos = str.find_first_of(flag1, i);
	if (pos < size && pos != 0) {
		string s = str.substr(i, pos);
		result.push_back(s);
	}
	i = pos + flag1.size();

	//......
	pos = str.find_first_of(flag2, i);
	if (pos < size) {
		string s = str.substr(i, pos - i);
		result.push_back(s);
		i = pos + flag2.size();
	}

	pos = str.find_first_of(flag, i);
	if (pos < size) {
		string s = str.substr(i, pos - i);
		result.push_back(s);
		i = pos + flag.size();
	}

	string s = str.substr(i);
	result.push_back(s);

	return result;
}

/*�����������ĸ��ָ��ʶ��
* @param str �������ݵ��ַ���
* @param flag1 �ָ��ַ���1
* @param flag2 �ָ��ַ���2
* @param flag3 �ָ��ַ���3
* @param flag �ָ��ַ���4
*/
vector<string> analyse(string str, string flag1, string flag2, string flag3,string flag) {
	size_t pos = 0, i = 0; vector<string> result; size_t size = str.size();

	pos = str.find_first_of(flag1, i);
	if (pos < size&&pos!=0) {
		string s = str.substr(i, pos);
		result.push_back(s);
	}
	i = pos + flag1.size();

	pos = str.find_first_of(flag2, i);
	if (pos < size) {
		string s = str.substr(i, pos - i);
		result.push_back(s);
		i = pos + flag2.size();
	}

	pos = str.find_first_of(flag3, i);
	if (pos < size) {
		string s = str.substr(i, pos-i);
		result.push_back(s);
		i = pos + flag3.size();
	}

	pos = str.find_first_of(flag, i);
	if (pos < size) {
		string s = str.substr(i, pos - i);
		result.push_back(s);
		i = pos + flag.size();
	}

	string s = str.substr(i);
	result.push_back(s);

	return result;
}

//��stringת������Ӧ���͵����ݣ��˴���ʹ�õ�ʱ��Ҫ�Լ���дת����������string����ת������������

/*
* @param Src ��������vector
* @param p1 ��id��
* @param s1 ������x
* @param s2 ������y
* @param s3 ������x
* @param s4 ������y
*/
void my_convert(vector<string> Src,string* p1, double& s1,double& s2,double& s3,double& s4) {
	stringstream len_convert;

    len_convert<<Src[0];
	len_convert >> *p1; len_convert.clear();

	len_convert << Src[1];
	len_convert >> s1; len_convert.clear();

	len_convert << Src[2];
	len_convert >> s2; len_convert.clear();

	len_convert << Src[3];
	len_convert >> s3; len_convert.clear();

	len_convert << Src[4];
	len_convert >> s4; len_convert.clear();
}
/*
* @param Src ��������vector
* @param p1 ��id��
* @param s3 ������x
* @param s4 ������y
*/
void my_convert(vector<string> Src, string* p1, double& s3, double& s4) {
	stringstream len_convert;

	len_convert << Src[0];
	len_convert >> *p1; len_convert.clear();

	len_convert << Src[1];
	len_convert >> s3; len_convert.clear();

	len_convert << Src[2];
	len_convert >> s4; len_convert.clear();
}

/*
* @param Src ����vector
* @param p1 ��id��ָ��
* @param s2 ������x
* @param s3 ������y
* @param s4 ������z
*/
void my_convert(vector<string> Src, string* p1,double &s2, double& s3, double& s4) {
	stringstream len_convert;

	len_convert << Src[0];
	len_convert >> *p1; len_convert.clear();

	len_convert << Src[1];
	len_convert >> s2; len_convert.clear();

	len_convert << Src[2];
	len_convert >> s3; len_convert.clear();

	len_convert << Src[3];
	len_convert >> s4; len_convert.clear();
}
/*
* @param p �������ַ���ͷָ��
* @param num �������ַ�������
* @param x �ȶ��ַ���
*/
bool findiftrue(string* p, int num,string x) {
	for (int i = 0; i < num; i++, p++) {
		if (*p == x)return true;
	}
	return false;
}

/*
* @param Src ����vector
* @param p1 ��id��ָ��
* @param d ��x����ָ��
*/
//void my_convert(vector<string> Src, string* p1, double* d) {
//	stringstream len_convert;
//
//	len_convert << Src[0];
//	len_convert >> *p1; len_convert.clear();
//
//	len_convert << Src[1];//x
//	len_convert >> *d; len_convert.clear(); cout << *d << endl;
//	d++;
//	len_convert << Src[2];//y
//	len_convert >> *d; len_convert.clear(); cout << *d << endl;
//	d++;
//	len_convert << Src[3];//z
//	len_convert >> *d; len_convert.clear(); cout << *d << endl;
//}