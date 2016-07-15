#include "AiRealize.h"


void initArray() {

	for (int i = 0;i < 15;i++) {
		for (int j = 0;j < 15;j++) {
			whiteScore[i][j] = 0;
			blackScore[i][j] = 0;
			score[i][j] = 0;

		}

	}




}

void getAdverseScore() {
	int count[4] = { 0 };
	for (int i = 0;i < 15;i++)
		for (int j = 0;j < 15;j++)
		{
			//�յ�
			if (isHave[i][j] == 0) {
				for (int k = 0;k < 4;k++)
				{
					count[k] = 0;
				}
				count[0] = judgeHorizontal(i, j, 1);
				count[1] = judgeVertical(i, j, 1);
				count[2] = judgeHyperphoria(i, j, 1);
				count[3] = judgeHypophoria(i, j, 1);
				for (int k = 0;k < 4;k++)
				{
					if (count[k] == 1) blackScore[i][j] += 0;
					else if (count[k] == 2) blackScore[i][j] += 5;
					else if (count[k] == 3) blackScore[i][j] += 50;
					else if (count[k] == 4) blackScore[i][j] += 180;
					else if (count[k] == 5)blackScore[i][j] += 400;
				}
			}
			else {
				blackScore[i][j] = -1;
			}
		}





}
void getOwnScore()
{
	int count[4] = { 0 };
	for (int i = 0;i < 15;i++)
		for (int j = 0;j < 15;j++)
		{
			//�յ�
			if (isHave[i][j] == 0) {
				for (int k = 0;k < 4;k++)
				{
					count[k] = 0;
				}
				count[0] = judgeHorizontal(i, j, 2);
				count[1] = judgeVertical(i, j, 2);
				count[2] = judgeHyperphoria(i, j, 2);
				count[3] = judgeHypophoria(i, j, 2);
				for (int k = 0;k < 4;k++)
				{
					if (count[k] == 1) whiteScore[i][j] += 0;
					else if (count[k] == 2) whiteScore[i][j] += 5;
					else if (count[k] == 3) whiteScore[i][j] += 50;
					else if (count[k] == 4) whiteScore[i][j] += 180;
					else if (count[k] == 5) whiteScore[i][j] += 400;
				}
			}
			else {
				whiteScore[i][j] = -1;
			}
		}

}
void getScore()
{
	for (int i = 0;i < 15;i++)
		for (int j = 0;j < 15;j++)
		{
			score[i][j] = blackScore[i][j] + whiteScore[i][j];
		}
}
AiPoint getMaxPoint()
{
	int max = 0;
	AiPoint result;
	result.aiX = 0;
	result.aiY = 0;
	for (int i = 0;i < 15;i++)
		for (int j = 0;j < 15;j++)
		{
			if (score[i][j] >max)
			{
				max = score[i][j];
				result.aiX = i;
				result.aiY = j;
			}
		}
	return result;
}



//col �� row ��  �����λ�ú����м�������
int judgeHorizontal(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//����
	//col �� row ��
	j = col - 1;
	i = row;
	while (j >= 0)
	{
		if (isHave[j--][i] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	j = col + 1;
	while (j <= 14)
	{
		if (isHave[j++][i] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

// �����λ�������м�������
int judgeVertical(int col, int row, int shape)
{
	int i, j;
	int counter = 1;
	//����
	j = col;
	i = row - 1;
	while (i >= 0)
	{
		if (isHave[j][i--] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	i = row + 1;
	while (i <= 14)
	{
		if (isHave[j][i++] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

//�������б�ж�������
int judgeHyperphoria(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//������б
	i = row + 1;
	j = col - 1;
	while (i <= 14 && j >= 0)
	{
		if (isHave[j--][i++] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	i = row - 1;
	j = col + 1;
	while (i >= 0 && j <= 14)
	{
		if (isHave[j++][i--] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

//�������б�ж�������
int judgeHypophoria(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//������б
	i = row + 1;
	j = col + 1;
	while (i <= 14 && j <= 14)
	{
		if (isHave[j++][i++] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	i = row - 1;
	j = col - 1;
	while (i >= 0 && j >= 0)
	{
		if (isHave[j--][i--] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}
