#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 80
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//展示
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//设置雷
void SetMine(char board[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//拓展周围不是雷的区域
void broad(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
//标记
int Flagmine(char show[ROWS][COLS], int row, int col, int flag_count);
//取消标记
int CancelFlag(char show[ROWS][COLS], int row, int col, int flag_count);



