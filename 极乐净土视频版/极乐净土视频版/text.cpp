#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<mmsystem.h>

using namespace std;

#pragma comment(lib ,"winmm.lib")

//1.�����ܷ���--�Ӵ���ֱ�Ӽ����ļ�ÿ���ļ���������ʱ��
//int main() {
//
//	//�����ַ����鴢��ͼƬ·��
//	char FileName[1024] ;
//
//	initgraph(800, 450);
//
//	mciSendString(_T("play D:\\c++����֮·\\��ţcode\\���־�����Ƶ��\\���־���.mp3  repeat"), 0, 0, 0);
//
//	while (1) {
//
//		for (int i = 0; i <= 148; i++) {
//			sprintf( FileName,
//				    "D:\\c++����֮·\\��ţcode\\���־�����Ƶ��\\���־���ͼƬ\\_%04d_ͼ��-%d.jpg", 
//				    i ,148-i);
//			loadimage(0, FileName);
//			Sleep(25); //  1000/50
//		}
//	}
//
//	system("pause");
//
//	closegraph();
//	return 0;
//}


//������:Ԥ����

#define COUNT 148

int main() {
	//���ڴ洢ͼƬ�Ķ���
	IMAGE image[COUNT];
	//�����ַ����鴢��ͼƬ·��
	char FileName[1024] ;

	cout << "���ڼ���....." << endl;

	initgraph(800, 450);

	mciSendString(_T("play D:\\c++����֮·\\��ţcode\\���־�����Ƶ��\\���־���.mp3  repeat"), 0, 0, 0);


	//Ԥ����ͼƬ
	for (int i = 0; i < COUNT; i++) {
		sprintf(FileName,
				"D:\\c++����֮·\\��ţcode\\���־�����Ƶ��\\���־���ͼƬ\\_%04d_ͼ��-%d.jpg", 
				i ,148-i);
		loadimage(&image[i], FileName);
	}

	
	while (1) {
		for (int i = 0; i < 148; i++) {
			putimage(0, 0, &image[i]);
			Sleep(25);
		}
			 //  1000/50
		}

	system("pause");

	closegraph();
	return 0;
}