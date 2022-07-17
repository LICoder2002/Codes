#pragma once

#include<stdio.h>

#define ROW 3//��
#define COL 3//��

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
//�ҵ�û�������λ�������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
//1�����Ӯ�˷���*
//2������Ӯ�˷���#
//3��ƽ�ַ���Q
//4����Ϸ��������C
char isWin(char board[ROW][COL], int row, int col);

//����������˷���1��û������0
int isFull(char board[ROW][COL], int row, int col);

