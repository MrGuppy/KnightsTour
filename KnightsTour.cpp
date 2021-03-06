// KnightsTour.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define N 8

using namespace std;

int SolveTourRecurs(int nStartPosX, int nStartPosY, int nMoveCount, int nChessBoard[N][N], int nMoveX[N], int nMoveY[N]);

bool isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 &&
		y < N && sol[x][y] == -1);
}

void ShowSol(int sol[N][N])
{
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			cout << sol[x][y] << endl;

}

bool KnightsTour()
{
	//creating the board array
	int m_nChessBoard[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			m_nChessBoard[i][j] = -1;

	//possible moves of our knight being 8 different variations
	const int m_nPosMoves = 8;

	//gives the knight moveability
	int m_nMoveRow[m_nPosMoves] = { 1, -1, 2,  2, -2, -2,  1, -1 };
	int m_nMoveCol[m_nPosMoves] = { 2,  2, 1, -1,  1, -1, -2, -2 };

	m_nChessBoard[0][0] = 0;

	if (SolveTourRecurs(0, 0, 1, m_nChessBoard, m_nMoveRow, m_nMoveCol) == false)
		cout << "no possible solution is correct" << endl;
	else
	ShowSol(m_nChessBoard);

	return true;
}

int SolveTourRecurs(int nStartPosX, int nStartPosY, int nMoveCount, int nChessBoard[N][N], int nMoveX[N], int nMoveY[N])
{
	int nK;
	int nNextKnightX;
	int nNextKnightY;

	if (nMoveCount == N * N)
		return true;

	for (nK = 0; nK < 8; ++nK)
	{
		nNextKnightX = nStartPosX + nMoveX[nK];
		nNextKnightY = nStartPosY + nMoveY[nK];

		if (isSafe(nNextKnightX, nNextKnightY, nChessBoard))
		{
			nChessBoard[nNextKnightX][nNextKnightY] = nMoveCount;
			if (SolveTourRecurs(nNextKnightX, nNextKnightY, nMoveCount + 1, nChessBoard, nMoveX, nMoveY) == true)
				return true;
			else
				nChessBoard[nNextKnightX][nNextKnightY] = -1;

		}
	}
	return false;
}


int main()
{
	KnightsTour();
	system("pause");
    return 0;
}
