#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

//给出一串字符，按相应的规则匹配出数据
/*解析函数（2个分割标识）
* @param str 含有数据的字符串
* @param flag1 分割字符串1
* @param flag2 分割字符串2
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
/*解析函数（三个分割标识）
* @param str 含有数据的字符串
* @param flag1 分割字符串1
* @param flag2 分割字符串2
* @param flag 分割字符串3
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

/*解析函数（四个分割标识）
* @param str 含有数据的字符串
* @param flag1 分割字符串1
* @param flag2 分割字符串2
* @param flag3 分割字符串3
* @param flag 分割字符串4
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

//从string转换成相应类型的数据，此处在使用的时候要自己编写转换函数，将string类型转换成其它类型

/*
* @param Src 长度数据vector
* @param p1 点id号
* @param s1 新坐标x
* @param s2 新坐标y
* @param s3 旧坐标x
* @param s4 旧坐标y
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
* @param Src 长度数据vector
* @param p1 点id号
* @param s3 旧坐标x
* @param s4 旧坐标y
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
* @param Src 数据vector
* @param p1 点id号指针
* @param s2 旧坐标x
* @param s3 旧坐标y
* @param s4 旧坐标z
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
* @param p 待查找字符串头指针
* @param num 待查找字符串长度
* @param x 比对字符串
*/
bool findiftrue(string* p, int num,string x) {
	for (int i = 0; i < num; i++, p++) {
		if (*p == x)return true;
	}
	return false;
}

/*
* @param Src 数据vector
* @param p1 点id号指针
* @param d 点x坐标指针
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