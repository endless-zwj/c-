
#include  <stdio.h>
#include  <time.h>
#include  <stdlib.h>
#include <windows.h>

//�������̵�  �� �� ��
#define ROW  3 
#define COL  3 
 
void Initboard(char board[ROW][COL], int row, int col);

void Displayboard(char board[ROW][COL], int row, int col);

void Playermove(char board[ROW][COL], int row, int col);

void Computermove(char board[ROW][COL]);

char checkWin(char board[ROW][COL], int row, int col);