#define _CRT_SECURE_NO_WARNINGS
#include"man_box.h"



int main() {

	initgraph(SCREEN_LENGTH, SCREEN_WIDTH);

	IMAGE bg_tmp;
	loadimage(&bg_tmp, _T("blackground.tmp"), SCREEN_LENGTH, SCREEN_WIDTH, true);
	putimage(0, 0, &bg_tmp);

	//创建一组图片,存储工具信息
	loadimage(&image[WALL], _T("wall_right.bmp"), RATIO, RATIO, true);
	loadimage(&image[FLOOR], _T("floor.bmp"), RATIO, RATIO, true);
	loadimage(&image[DES], _T("des.bmp"), RATIO, RATIO, true);
	loadimage(&image[MAN], _T("man.bmp"), RATIO, RATIO, true);
	loadimage(&image[BOX], _T("box.bmp"), RATIO, RATIO, true);
	loadimage(&image[DES_BOX], _T("box.bmp"), RATIO, RATIO, true);


	//利用数组加载图片
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			putimage(START_X+ j*RATIO ,START_Y+i*RATIO,&image[map[i][j]]);
		}
	}

	//定义一个人的位置结构体,并初始化人的位置信息
	MAN_POS man_pos;
	InitPos(&man_pos);

	//获取热键
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

			//每获取一个按键,判断一次是否游戏结束
			if (IsGameOver()) {

			}

			//减慢获取热键的速度,获取热键需要消耗cpu
			Sleep(200);
		}
	} while (Quit);


	system("pause");
	closegraph();
	return 0;
}


/***********************************
		    InitPos
    找到MAN在map数组中的位置,
	赋值给man_pos的x,y
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
		判断游戏有无结束
	遍历map数组,如果map数组中没有des
	则标识游戏结束,返回true
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
	改变map数组中的值,并重新贴图
******************************************/
void ChangeImage(MAN_POS*pos,enum TOOLS tool_type) {
	map[pos->x][pos->y] = tool_type ;
	putimage(START_X + pos->y * RATIO, START_Y + pos->x * RATIO, &image[tool_type]);
}

void MOVE_UP(MAN_POS& man_pos) {
	MAN_POS man_next_pos = man_pos;
	man_next_pos.x = man_pos.x;
	man_next_pos.y = man_pos.y - 1;
	//人的下一个位置越界(或者人的下一个位置是否为墙),则这一步无效,直接返回
	if (man_next_pos.y < 0 || map[man_next_pos.x][man_next_pos.y] == WALL) {
		return; 
	}//人的下一步为地板,交换人与地板的图片,实现人向上走的效果,并改变人的位置信息.
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
