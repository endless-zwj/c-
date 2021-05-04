#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<windows.h>
#include<cmath>
#include<string>

using namespace std;

//����һ����ֵ,���ڼ�����(���������ֵ����������Ϊ�����¼�)
#define THRESHOLD 1.5 

//���㳤/��ʱ�䴰�ڵ�����ֵ
double power_window(double sensor[], int pos, int TypeWindow);

int main() {
	string filename;
	ifstream fin;

	cout << "please enter the filename: ";
	cin >> filename;
	
	//num �������ݵĸ��� long_window �����ڵĴ�С short_window �̴��ڴ�С
	int num = 0 ,long_window = 0 , short_window = 0;
	//sensor���ڴ�Ŵ�������  tine_period ʱ����  ratio ����  
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