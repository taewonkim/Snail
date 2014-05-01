#include "stdafx.h"

typedef int* IntPtr;

enum DIRECTION { RT_MOVE = 0, DN_MOVE, LT_MOVE, UP_MOVE };

size_t SizeOfSnailMatrix(IntPtr* Matrix, int nRows)
{
	size_t TOTAL = 0;
	TOTAL = (_msize(Matrix) / sizeof(int)) * nRows;
	return TOTAL;
}

void MakeSnail2Matrix(IntPtr* Matrix, int nRows, int nCols)
{
	enum DIRECTION direction = RT_MOVE;
	int xPos = 0, yPos = 0;
	int LIMIT = 0;
	int VALUE = 0;

	size_t MatrixSize = 0;

	if (Matrix == NULL)
		return;
	if (nRows < 0 || nRows > 20)
		return;
	if (nCols < 0 || nCols > 20)
		return; 

	MatrixSize = SizeOfSnailMatrix(Matrix, nRows);
	if (MatrixSize > (size_t)(nRows * nCols))
		return;

	while (VALUE < (nRows * nCols))
	{
		Matrix[xPos][yPos] = ++VALUE;

		switch (direction)
		{
		case RT_MOVE:
			if (yPos < ((nCols - 1) - LIMIT))
				yPos++;
			else
				xPos++, direction = DN_MOVE;
			break;
		case DN_MOVE:
			if (xPos < ((nRows - 1) - LIMIT))
				xPos++;
			else
				yPos--, direction = LT_MOVE;
			break;
		case LT_MOVE:
			if (LIMIT < yPos)
				yPos--;
			else
				xPos--, LIMIT++, direction = UP_MOVE;
			break;
		case UP_MOVE:
			if (LIMIT < xPos)
				xPos--;
			else
				yPos++, direction = RT_MOVE;
			break;
		}
	}
}

void Disp2ScreenBySnailMatrix(IntPtr* Matrix, int nRows, int nCols)
{
	size_t MatrixSize = 0;

	if (Matrix == NULL)
		return;
	if (nRows < 0 || nRows > 20)
		return;
	if (nCols < 0 || nCols > 20)
		return;

	MatrixSize = SizeOfSnailMatrix(Matrix, nRows);
	if (MatrixSize > (size_t)(nRows * nCols))
		return;

	for (int X = 0; X < nRows; X++)
	{
		for (int Y = 0; Y < nCols; Y++)
			printf("%4d", Matrix[X][Y]);
		printf("\n");
	}
}

void CreateSnailMatrix(IntPtr* Matrix, int nRows, int nCols)
{
	if (nRows < 0 || nRows > 20)
		return;
	if (nCols < 0 || nCols > 20)
		return;
	for (int i = 0; i < nRows; i++)
		Matrix[i] = new int[nCols];
}

void DeleteSnailMatrix(IntPtr* Matrix, int nRows)
{
	if (Matrix == NULL)
		return;
	for (int i = 0; i < nRows; i++)
		delete[] Matrix[i];
	delete[] Matrix;
}

int _tmain(int argc, _TCHAR* argv[])
{
	IntPtr *Matrix = NULL;

	int Rows = 15, 
		Cols = 15;

	Matrix = new IntPtr[Rows];

	CreateSnailMatrix(Matrix, Rows, Cols);
	MakeSnail2Matrix(Matrix, Rows, Cols);
	Disp2ScreenBySnailMatrix(Matrix, Rows, Cols);
	DeleteSnailMatrix(Matrix, Rows);

	return 0;
}