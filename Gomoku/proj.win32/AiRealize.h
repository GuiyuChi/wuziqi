#include<iostream>
#include "res.h"
struct AiPoint
{
	float aiX;
	float aiY;
};
void initArray();//�����з�������
void getAdverseScore();//���Է�ÿ��λ�÷�����¼����
void getOwnScore();
void getScore();
AiPoint getMaxPoint();
int judgeHorizontal(int col, int row, int shape);
int judgeVertical(int col, int row, int shape);
int judgeHyperphoria(int col, int row, int shape);
int judgeHypophoria(int col, int row, int shape);