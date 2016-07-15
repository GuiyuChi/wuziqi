#include<iostream>
#include "res.h"
struct AiPoint
{
	float aiX;
	float aiY;
};
void initArray();//将所有分数清零
void getAdverseScore();//将对方每个位置分数记录下来
void getOwnScore();
void getScore();
AiPoint getMaxPoint();
int judgeHorizontal(int col, int row, int shape);
int judgeVertical(int col, int row, int shape);
int judgeHyperphoria(int col, int row, int shape);
int judgeHypophoria(int col, int row, int shape);