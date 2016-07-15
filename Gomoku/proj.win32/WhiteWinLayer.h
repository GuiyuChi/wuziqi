#pragma once



#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"SceneManager.h"
#include "boardClear.h"
using namespace ui;
USING_NS_CC;
class WhiteWinLayer :public Layer {
public:
	CREATE_FUNC(WhiteWinLayer);
	virtual bool init();
	void ButtentouchEvent_1(Object *pSender, TouchEventType type);
	void ButtentouchEvent_2(Object *pSender, TouchEventType type);
	void onScheduleOnce_1(float dt);
	void onScheduleOnce_2(float dt);
public:
	SceneManager * tsm;
};

