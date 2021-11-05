#define _CRT_SECURE_NO_WARNINGS 1

//游戏相关函数的实现

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				putchar('|');
		}
		putchar('\n');
		if (i < row - 1)
		{
			//printf("---|---|---");
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					putchar('|');
			}
			putchar('\n');
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//下棋
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走:>\n");
	while (1)
	{
		//随机生成坐标
		int x = rand() % row;
		int y = rand() % col;
		//下棋
		//判断坐标是否被占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//在游戏进行的过程中
//1.玩家赢了 - 返回‘*’
//2.电脑赢了 - 返回‘#’
//3.平局     - 返回‘Q’
//4.游戏继续 - 返回‘C’
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	////判断行
	////i代表行，j代表列
	//for (i = 0; i < row; i++)
	//{
	//	//判断三行
	//	//if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
	//	//当不止三列时
	//	for (j = 0; j < col; j++)
	//	{
	//		if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 1] != ' ')
	//		{
	//			return board[i][j + 1];
	//		}
	//	}
	//}
	//判断列
	//i代表列,j代表行
	//上下的循环中i与j代表的量不同，意义相反
	//for (i = 0; i < col; i++)
	//{
	//	//判断三列
	//	//if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
	//	//当不止三行时
	//	for (j = 0; j < row; j++)
	//	{
	//		if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j + 1][i] != ' ')
	//		{
	//			return board[j + 1][i];
	//		}
	//	}
	//}
	//尝试合并
	//默认row和col为相同的值
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 1] != ' ')
			{
				return board[i][j + 1];
			}
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j + 1][i] != ' ')
			{
				return board[j + 1][i];
			}
		}
	}
	//判断对角线
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}
	//if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i + 1][i + 1] != ' ')
		{
			return board[i + 1][i + 1];
		}
		if (board[i][col - 1 - i] == board[i + 1][col - 2 - i] && board[i + 1][col - 2 - i] == board[i + 2][col - 3 - i] && board[i + 1][col - 2 - i] != ' ')
		{
			return board[i + 1][col - 2 - i];
		}
	}
	//判断平局
	//判断棋盘是否满
	//如果棋盘满了返回1，不满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//以上都没有结果，继续游戏
	return 'C';
}