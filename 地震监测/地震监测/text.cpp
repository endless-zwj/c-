#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<windows.h>
#include<cmath>
#include<string>

using namespace std;

//定义一个阀值,用于检测地震(高于这个阀值则则发生地震为可能事件)
#define THRESHOLD 1.5 

//计算长/短时间窗口的能量值
double power_window(double sensor[], int pos, int TypeWindow);

int main() {
	string filename;
	ifstream fin;

	cout << "please enter the filename: ";
	cin >> filename;
	
	//num 传感数据的个数 long_window 长窗口的大小 short_window 短窗口大小
	int num = 0 ,long_window = 0 , short_window = 0;
	//sensor用于存放传感数据  tine_period 时间间隔  ratio 比例  
	double *sensor = NULL , time_period = 0 , ratio = 0 , short_power = 0 , long_power = 0;
	
	fin.open(filename.c_str());

	if (fin.fail()) {
		cerr << "open file fail !" << endl;
		exit(-1);
	}
	else {
		cout << "please enter the num of sensor :" << endl;
		fin >> num;
		cout << "please enter the time_period :" << endl;
		fin >> time_period;

		cout << "num : " << num << " time_period : " << time_period << endl;

		if (num >= 0) {
			sensor = new double[num];

			for (int i = 0; i < num; i++)
				fin >> sensor[i];
			cout << "please enter the long_window: ";
			cin >> long_window; 
			cout << "please enter the short_window: ";
			cin >> short_window;

			for (int i = long_window - 1; i < num; i++) {
				short_power = power_window(sensor, i, short_window);
				long_power = power_window(sensor, i ,long_window);
				ratio = short_power / long_power ;
				if (ratio > THRESHOLD) {
					cout << "the possible event is at " << time_period * i << "seconds\n";
 				}
			}
			delete[] sensor;
		}
		fin.close();
	}

	system("pause");
	return 0;
}

double power_window(double sensor[], int pos, int TypeWindow) {
	double total = 0;
	for (int i = pos - TypeWindow + 1; i <= pos; i++) {
		total += pow(sensor[i], 2);
	}
	total /= TypeWindow ;
	return total; 
}