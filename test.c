#define _CRT_SECURE_NO_WARNINGS 1

//测试游戏的逻辑

#include "game.h"//已有头文件用<>，自定义的头文件用“”

void menu()
{
	printf("**************************************\n");
	printf("*************   1.play   *************\n");
	printf("*************   0.exit   *************\n");
	printf("**************************************\n");
}
void game()
{
	//存储数据 - 二维数组
	char board[ROW][COL];
	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);
	//打印一下棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接受游戏状态
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑走
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if(ret=='#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}