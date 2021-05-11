#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<graphics.h>
#include <conio.h>//����ͷ�ļ�_getch [�޻��ԵĻ�ȡһ���ַ�]

using namespace std;

//���崰�ڵĴ�С
#define SCREEN_LENGTH 960
#define SCREEN_WIDTH  708

//�����ͼ��������
#define LINE 9
#define COLUMN 12

//�����ʼ�߿�
#define START_X 100
#define START_Y 70

//����һ��ͼƬ�Ĵ�С
#define RATIO 61 

//���巽���
#define KEY_UP    'w'
#define KEY_DOWN  's'
#define KEY_LEFT  'a'
#define KEY_RIGHT 'd'
#define OVER      'q'


//����һ���������ö������
//������Ӧ����Ԫ����ͼƬ�Ĺ�ϵ
enum TOOLS{
	WALL,
	FLOOR,
	DES,
	MAN,
	BOX,
	DES_BOX,
	ALL
};

//����һ���ṹ�崢���˵���Ϣ
//��Щ��Ϣ�����˵ĺ�������
typedef struct {
	int x;
	int y;
}MAN_POS;


//����һ��ȫ��map����
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

//����һ��ȫ��ͼƬ����
IMAGE image[ALL];

//����С���ƶ�
void MOVE_UP(MAN_POS& man_pos);
void MOVE_DOWN(MAN_POS& man_pos);
void MOVE_LEFT(MAN_POS& man_pos);
void MOVE_RIGHT(MAN_POS& man_pos);

//�ж���Ϸ�Ƿ����
bool IsGameOver();

//��ʼ���˵�λ����Ϣ
void InitPos(MAN_POS* man_pos);

void ChangeImage(MAN_POS* pos,enum TOOLS tool_type );