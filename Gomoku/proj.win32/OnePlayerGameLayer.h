#pragma once


#include <iostream>
#include"cocos2d.h"
#include"SceneManager.h"
#include "res.h"
USING_NS_CC;



class OnePlayerGameLayer :public Layer
{
public:

	CCPoint a[15][15];
	void init_point();
	int count = 0;/*��¼��������ɫ*/
	Vector<CCSprite*> bullets;
	CREATE_FUNC(OnePlayerGameLayer);
	virtual bool init();
	void onTouchesEnded(const std::vector<Touch*>& touches, Event * unused_event);
	int judgeHorizontal(int cow, int row, int shape);//�ж��Ƿ��Ǻ���ʤ��
	int judgeVertical(int cow, int row, int shape);//�ж��Ƿ�������ʤ��
	int judgeHyperphoria(int cow, int row, int shape);//�ж��Ƿ�������бʤ��
	int judgeHypophoria(int cow, int row, int shape);//�ж��Ƿ�������бʤ��
	int judgeDraw();//�ж��Ƿ����
	int judge(int cow, int row, int shape);
public:
	SceneManager * tsm;
};