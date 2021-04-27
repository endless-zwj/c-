#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<mmsystem.h>

using namespace std;

#pragma comment(lib ,"winmm.lib")

//1.低性能方法--从磁盘直接加载文件每张文件都需消耗时间
//int main() {
//
//	//定义字符数组储存图片路径
//	char FileName[1024] ;
//
//	initgraph(800, 450);
//
//	mciSendString(_T("play D:\\c++进阶之路\\奇牛code\\极乐净土视频版\\极乐净土.mp3  repeat"), 0, 0, 0);
//
//	while (1) {
//
//		for (int i = 0; i <= 148; i++) {
//			sprintf( FileName,
//				    "D:\\c++进阶之路\\奇牛code\\极乐净土视频版\\极乐净土图片\\_%04d_图层-%d.jpg", 
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


//方法二:预加载

#define COUNT 148

int main() {
	//用于存储图片的对象
	IMAGE image[COUNT];
	//定义字符数组储存图片路径
	char FileName[1024] ;

	cout << "正在加载....." << endl;

	initgraph(800, 450);

	mciSendString(_T("play D:\\c++进阶之路\\奇牛code\\极乐净土视频版\\极乐净土.mp3  repeat"), 0, 0, 0);


	//预加载图片
	for (int i = 0; i < COUNT; i++) {
		sprintf(FileName,
				"D:\\c++进阶之路\\奇牛code\\极乐净土视频版\\极乐净土图片\\_%04d_图层-%d.jpg", 
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