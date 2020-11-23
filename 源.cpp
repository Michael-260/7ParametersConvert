#include<iostream>
#include<fstream>
#include<Eigen/Dense>
#include<iomanip>
#include"dataAnalyse.h"
#include"head4.h"

using namespace std;
using namespace Eigen;

static string DATATXT = "data.txt";
static string DATATXT7_ol = "oldata7.txt";
static string DATATXT7_ne = "nedata7.txt";

int DATANUMBER = 15;

int main() {
	int choice;
	string data,wait;
	vector<string> data_vec;
	string *point_id=new string[15],*tem_point=point_id,*tem_point1;
	double ol[15][2], ne[15][2];//二维坐标
	double xigama = 0;



	cout << "请选择二维/三维坐标转换：\n";
	cin >> choice;
	if (choice == 2) {
		//读取数据并存储在数组中
		fstream file;
		file.open(DATATXT, ios::in);//打开文件
		if (!file) { cerr << "文件不存在！\n"; exit(0); }
		int* line_add = new int(0);//行计数器
		while (!file.eof() && *line_add <= 15)
		{
			(*line_add)++;
			getline(file, data);
			data_vec = analyse(data, " ", " ", " ", " ");//数据格式：T037 4203300.1396 502195.8775 4203296.4290 502080.0166
			int tem = *line_add - 1;
			my_convert(data_vec, tem_point, ne[tem][0], ne[tem][1], ol[tem][0], ol[tem][1]); tem_point++;

		}
		//释放空间
		delete line_add;

		//测试代码
		tem_point = point_id;
		for (int i = 0; i < 15; i++, tem_point++) {
			cout << *tem_point << endl <<
				" old:" << ol[i][0] << " , " << ol[i][1] << endl <<
				" new:" << ne[i][0] << " , " << ne[i][1] << endl;
		}

		//初始化矩阵
		MatrixXd b(20, 4), x(4, 1), l(20, 1), v, m_xigama;
		//初始化b矩阵 x,y,x,y......
		for (int i = 0; i < 10; i++) {
			int tem = i * 2;
			b(tem, 0) = 1;
			b(tem, 1) = 0;
			b(tem, 2) = -1 * ol[i][1];
			b(tem, 3) = ol[i][0];
			tem++;
			b(tem, 0) = 0;
			b(tem, 1) = 1;
			b(tem, 2) = ol[i][0];
			b(tem, 3) = ol[i][1];
		}
		//初始化l矩阵
		for (int i = 0; i < 10; i++) {
			int tem = i * 2;
			l(tem, 0) = ne[i][0] - ol[i][0];
			tem++;
			l(tem, 0) = ne[i][1] - ol[i][1];
		}

		//测试代码
		cout << "b:\n" << b << endl << "l:\n" << l << endl;

		//计算参数（旧坐标系到新坐标系）
		x = (b.transpose() * b).inverse() * b.transpose() * l;//角度单位为弧度（double方便保存）
		//x(3, 0) *= 1000000;//单位转化成ppm

		//测试代码
		cout << "x:\n" << x << endl;

		//计算中误差
		v = b * x - l;
		m_xigama = v.transpose() * v;
		xigama = sqrt(m_xigama(0, 0) / 16);//计算参数中误差xigama

		//测试代码
		cout << m_xigama << endl << xigama << endl;
		cout << "v:\n" << v << endl;

		//计算1-15坐标转换值
		MatrixXd b_ne(30, 4), ne_data(30, 1);//15个点的b矩阵，新坐标x、y按点的顺序排列
		//赋值15个点的b矩阵
		for (int i = 0; i < 15; i++) {
			int tem = i * 2;
			b_ne(tem, 0) = 1;
			b_ne(tem, 1) = 0;
			b_ne(tem, 2) = -1 * ol[i][1];
			b_ne(tem, 3) = ol[i][0];
			tem++;
			b_ne(tem, 0) = 0;
			b_ne(tem, 1) = 1;
			b_ne(tem, 2) = ol[i][0];
			b_ne(tem, 3) = ol[i][1];
		}

		//赋值15个点的旧坐标矩阵
		MatrixXd m_ol(30, 1);//x、y按点的顺序排列
		for (int i = 0; i < 15; i++) {
			int tem = i * 2;
			m_ol(tem, 0) = ol[i][0];
			tem++;
			m_ol(tem, 0) = ol[i][1];
		}

		//计算新坐标矩阵
		MatrixXd m_ne(30, 1);//x、y按点的顺序排列
		m_ne = m_ol + b_ne * x;

		//测试代码
		cout << "b:\n" << b_ne << endl;
		for (int i = 0; i < 15; i++) {
			int tem = i * 2;
			cout << point_id[i] << " : (" << setprecision(9) << m_ne(tem++, 0) << " , " <<
				setprecision(9) << m_ne(tem, 0) << ")\n";
		}
		file.close();
	}
	else if(choice==3)//七参数坐标变换
	{
//读取旧坐标文件

DATANUMBER = 12;
int datanumber = DATANUMBER * 3;
double* ol_7 = new double[datanumber];           //用一维数组代替二维数组，其行列对应关系为：i行j列(均从0开始计数)--->i*3+j
string* ol_pointID = new string[DATANUMBER];
tem_point = ol_pointID;                            //将临时指针指向旧坐标id首地址
fstream file;
file.open(DATATXT7_ol, ios::in);
if (!file) { cerr << "找不到文件！"; exit(0); }
		int* line_add = new int(0);                        //行计数器
		while (!file.eof())
		{   
			(*line_add)++;
			getline(file, data);
			data_vec = analyse(data, " ", " ", " ");
			int index = *line_add * 3 - 3, index1 = index + 1, index2 = index + 2;
			my_convert(data_vec, tem_point, ol_7[index], ol_7[index1], ol_7[index2]);
			tem_point++;
			if (*line_add == DATANUMBER)break;
		}
file.close();
//读取新坐标文件
		DATANUMBER = 7;
		datanumber = DATANUMBER * 3;
		double* ne_7 = new double[datanumber];           //用一维数组代替二维数组，其行列对应关系为：i行j列(均从0开始计数)--->i*3+j
		string* ne_pointID = new string[DATANUMBER];
		tem_point = ne_pointID;                            //将临时指针指向新坐标id首地址
		file.open(DATATXT7_ne, ios::in);
		if (!file) { cerr << "文件不存在！\n"; exit(0); }
		* line_add = 0;                                    //行计数器
		while (!file.eof())
		{
			(*line_add)++;
			getline(file, data);
			data_vec = analyse(data, " ", " ", " ");
			int index = *line_add * 3 - 3, index1 = index + 1, index2 = index + 2;
			my_convert(data_vec, tem_point,ne_7[index],ne_7[index1],ne_7[index2]);
			tem_point++;
			if (*line_add == DATANUMBER)break;
		}
//
		//测试代码
		/*tem_point = ol_pointID;
		for (int i = 0; i < 12; i++, tem_point++) {
			cout << *tem_point << endl <<
				" old:" <<*(ol_7+i*3) << " , " << *(ol_7 + i * 3 + 1) << " , " << *(ol_7 + i * 3 + 2) << endl;
		}
		tem_point = ne_pointID;
		for (int i = 0; i < 7; i++, tem_point++) {
			cout << *tem_point << endl <<
				" new:" << *(ne_7+i*3) << " , " << *(ne_7 + i * 3 + 1) << " , " << *(ne_7 + i * 3 + 2) <<endl;
		}*/
		file.close();

//找新旧对应坐标，赋值矩阵
		MatrixXd m_b(21,7);
		double* tem_7;
		for (int i = 0; i < 7; i++) {
			int index =i*3, index1 = i*3 + 1, index2 = i*3 + 2;
			m_b(index, 0) = 1; m_b(index, 1) = 0; m_b(index, 2) = 0; m_b(index, 3) = 0; m_b(index, 4) = -1*ol_7[index2]; m_b(index, 5) = ol_7[index1]; m_b(index, 6) = ol_7[index];
			m_b(index1, 0) = 0; m_b(index1, 1) = 1; m_b(index1, 2) = 0; m_b(index1, 3) =  ol_7[index2]; m_b(index1, 4) = 0; m_b(index1, 5) = -1*ol_7[index]; m_b(index1, 6) = ol_7[index1];
			m_b(index2, 0) = 0; m_b(index2, 1) = 0; m_b(index2, 2) = 1; m_b(index2, 3) =  -1 *ol_7[index1]; m_b(index2, 4) = ol_7[index]; m_b(index2, 5) = 0; m_b(index2, 6) = ol_7[index2];
		}
		//cout <<"m_b:\n"<< m_b << endl;
		MatrixXd m_l(21, 1);
		for (int i = 0; i < 7; i++) {
			int index = i * 3, index1 = i*3 + 1, index2 = i*3 + 2;
			m_l(index, 0) = ne_7[index] - ol_7[index];
			m_l(index1, 0) = ne_7[index1] - ol_7[index1];
			m_l(index2, 0) = ne_7[index2] - ol_7[index2];
		}
		//cout << "m_l:\n" <<m_l<< endl;

		MatrixXd x,v,m_xigama;
		x = (m_b.transpose() * m_b).inverse() * m_b.transpose() * m_l;
		//cout << "x:\n" << x << endl;
		v = m_b * x - m_l;
		m_xigama = v.transpose() * v;
		double xigama = m_xigama(0, 0);
		xigama = sqrt(xigama / 14);
		cout << "xigama:\n" <<xigama<< endl;
	}
	return 0;
}