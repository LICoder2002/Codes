#pragma once

#include<stdio.h>

#define ROW 3//行
#define COL 3//列

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
//找到没有下棋的位置随机下
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
//1、玩家赢了返回*
//2、电脑赢了返回#
//3、平局返回Q
//4、游戏继续返回C
char isWin(char board[ROW][COL], int row, int col);

//如果棋盘满了返回1，没满返回0
int isFull(char board[ROW][COL], int row, int col);

