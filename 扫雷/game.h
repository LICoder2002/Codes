#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 80
//��ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//չʾ
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//������
void SetMine(char board[ROWS][COLS], int row, int col);
//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//��չ��Χ�����׵�����
void broad(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
//���
int Flagmine(char show[ROWS][COLS], int row, int col, int flag_count);
//ȡ�����
int CancelFlag(char show[ROWS][COLS], int row, int col, int flag_count);



