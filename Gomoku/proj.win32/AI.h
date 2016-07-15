#include<iostream>
#include "AiRealize.h"
#include "res.h"
struct result
{
	float resultX;
	float resultY;
};
result Ai()
{
	result r;
	//电脑为白棋，后手
	//黑棋为1，白棋为2
	initArray();
	getAdverseScore();
	getOwnScore();
	getScore();
	r.resultX = getMaxPoint().aiX;
	r.resultY = getMaxPoint().aiY;
	return r;
}
