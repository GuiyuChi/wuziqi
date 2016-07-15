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
	int count = 0;/*记录下哪种颜色*/
	Vector<CCSprite*> bullets;
	CREATE_FUNC(OnePlayerGameLayer);
	virtual bool init();
	void onTouchesEnded(const std::vector<Touch*>& touches, Event * unused_event);
	int judgeHorizontal(int cow, int row, int shape);//判断是否是横向胜利
	int judgeVertical(int cow, int row, int shape);//判断是否是竖向胜利
	int judgeHyperphoria(int cow, int row, int shape);//判断是否是向上斜胜利
	int judgeHypophoria(int cow, int row, int shape);//判断是否是向下斜胜利
	int judgeDraw();//判断是否和棋
	int judge(int cow, int row, int shape);
public:
	SceneManager * tsm;
};