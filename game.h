#define _CRT_SECURE_NO_WARNINGS 1

//关于游戏相关的函数声明，符号声明，头文件的包含

//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//符号的定义
#define ROW 5
#define COL 5

//函数的声明
//初始化棋盘的函数
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//判断游戏是否有输赢或平局
char IsWin(char board[ROW][COL], int row, int col);