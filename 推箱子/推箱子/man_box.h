#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<graphics.h>
#include <conio.h>//包含头文件_getch [无回显的获取一个字符]

using namespace std;

//定义窗口的大小
#define SCREEN_LENGTH 960
#define SCREEN_WIDTH  708

//定义地图的行与列
#define LINE 9
#define COLUMN 12

//定义初始边框
#define START_X 100
#define START_Y 70

//定义一张图片的大小
#define RATIO 61 

//定义方向键
#define KEY_UP    'w'
#define KEY_DOWN  's'
#define KEY_LEFT  'a'
#define KEY_RIGHT 'd'
#define OVER      'q'


//定义一个工具类的枚举类型
//用来对应数组元素与图片的关系
enum TOOLS{
	WALL,
	FLOOR,
	DES,
	MAN,
	BOX,
	DES_BOX,
	ALL
};

//定义一个结构体储存人的信息
//这些信息包括人的横纵坐标
typedef struct {
	int x;
	int y;
}MAN_POS;


//定义一个全局map数组
int map[LINE][COLUMN] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
	{ 0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0 },
	{ 0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//定义一个全局图片数组
IMAGE image[ALL];

//控制小人移动
void MOVE_UP(MAN_POS& man_pos);
void MOVE_DOWN(MAN_POS& man_pos);
void MOVE_LEFT(MAN_POS& man_pos);
void MOVE_RIGHT(MAN_POS& man_pos);

//判断游戏是否结束
bool IsGameOver();

//初始化人的位置信息
void InitPos(MAN_POS* man_pos);

void ChangeImage(MAN_POS* pos,enum TOOLS tool_type );