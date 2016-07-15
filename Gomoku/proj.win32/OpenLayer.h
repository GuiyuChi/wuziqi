#pragma once

#include <iostream>
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"SceneManager.h"
using namespace ui;
USING_NS_CC;



class OpenLayer : public Layer
{
public:
	CREATE_FUNC(OpenLayer);
	virtual bool init();
	void menuCallBack(Ref *pSender);
	void menuItemStartCallback(Ref *pSender);
	void ButtentouchEvent_1(Object *pSender, TouchEventType type);
	void ButtentouchEvent_2(Object *pSender, TouchEventType type);
	void ButtentouchEvent_3(Object *pSender, TouchEventType type);
	void onScheduleOnce_1(float dt);
	void onScheduleOnce_2(float dt);
	void onScheduleOnce_3(float dt);
public:
	SceneManager * tsm;

};

