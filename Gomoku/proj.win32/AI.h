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
	//����Ϊ���壬����
	//����Ϊ1������Ϊ2
	initArray();
	getAdverseScore();
	getOwnScore();
	getScore();
	r.resultX = getMaxPoint().aiX;
	r.resultY = getMaxPoint().aiY;
	return r;
}
