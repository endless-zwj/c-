#define _CRT_SECURE_NO_WARNINGS
#include"man_box.h"



int main() {

	initgraph(SCREEN_LENGTH, SCREEN_WIDTH);

	IMAGE bg_tmp;
	loadimage(&bg_tmp, _T("blackground.tmp"), SCREEN_LENGTH, SCREEN_WIDTH, true);
	putimage(0, 0, &bg_tmp);

	//����һ��ͼƬ,�洢������Ϣ
	loadimage(&image[WALL], _T("wall_right.bmp"), RATIO, RATIO, true);
	loadimage(&image[FLOOR], _T("floor.bmp"), RATIO, RATIO, true);
	loadimage(&image[DES], _T("des.bmp"), RATIO, RATIO, true);
	loadimage(&image[MAN], _T("man.bmp"), RATIO, RATIO, true);
	loadimage(&image[BOX], _T("box.bmp"), RATIO, RATIO, true);
	loadimage(&image[DES_BOX], _T("box.bmp"), RATIO, RATIO, true);


	//�����������ͼƬ
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			putimage(START_X+ j*RATIO ,START_Y+i*RATIO,&image[map[i][j]]);
		}
	}

	//����һ���˵�λ�ýṹ��,����ʼ���˵�λ����Ϣ
	MAN_POS man_pos;
	InitPos(&man_pos);

	//��ȡ�ȼ�
	bool Quit = true;
	do {
		if (_kbhit()) {
			char ch = _getch();

			switch (ch) {
			case KEY_UP:
				MOVE_UP(man_pos);
				break;
			case KEY_DOWN:
				MOVE_DOWN(man_pos);
				break;
			case KEY_LEFT:
				MOVE_LEFT(man_pos);
				break;
			case KEY_RIGHT:
				MOVE_RIGHT(man_pos);
				break;
			case OVER:
				Quit = false;
				break;
			default:
				;
			}

			//ÿ��ȡһ������,�ж�һ���Ƿ���Ϸ����
			if (IsGameOver()) {

			}

			//������ȡ�ȼ����ٶ�,��ȡ�ȼ���Ҫ����cpu
			Sleep(200);
		}
	} while (Quit);


	system("pause");
	closegraph();
	return 0;
}


/***********************************
		    InitPos
    �ҵ�MAN��map�����е�λ��,
	��ֵ��man_pos��x,y
************************************/
void InitPos(MAN_POS* man_pos) {
	for (int i = 0; i < LINE; i++)
	for (int j = 0; j < COLUMN; j++)
	if (map[i][j] == MAN) {
		man_pos->x = i;
		man_pos->y = j;
	}
}

/***********************************
			IsGameOver
		�ж���Ϸ���޽���
	����map����,���map������û��des
	���ʶ��Ϸ����,����true
************************************/
bool IsGameOver() {
	for (int i = 0; i < LINE; i++)
	for (int j = 0; j < COLUMN; j++)
	if (map[i][j] == DES)
		return false;
	return true;
}

/*****************************************
		   ChangeImage
	�ı�map�����е�ֵ,��������ͼ
******************************************/
void ChangeImage(MAN_POS*pos,enum TOOLS tool_type) {
	map[pos->x][pos->y] = tool_type ;
	putimage(START_X + pos->y * RATIO, START_Y + pos->x * RATIO, &image[tool_type]);
}

void MOVE_UP(MAN_POS& man_pos) {
	MAN_POS man_next_pos = man_pos;
	man_next_pos.x = man_pos.x;
	man_next_pos.y = man_pos.y - 1;
	//�˵���һ��λ��Խ��(�����˵���һ��λ���Ƿ�Ϊǽ),����һ����Ч,ֱ�ӷ���
	if (man_next_pos.y < 0 || map[man_next_pos.x][man_next_pos.y] == WALL) {
		return; 
	}//�˵���һ��Ϊ�ذ�,��������ذ��ͼƬ,ʵ���������ߵ�Ч��,���ı��˵�λ����Ϣ.
	else if (map[man_next_pos.x][man_next_pos.y] == FLOOR) {
		ChangeImage( &man_pos , FLOOR);
		ChangeImage(&man_next_pos, MAN);
		man_pos = man_next_pos;
	}
}
void MOVE_DOWN(MAN_POS& man_pos) {


}
void MOVE_LEFT(MAN_POS& man_pos) {

}
void MOVE_RIGHT(MAN_POS& man_pos) {

}
