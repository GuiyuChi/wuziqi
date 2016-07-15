#pragma once



#include <iostream>
#include"cocos2d.h"
#include"SceneManager.h"
USING_NS_CC;
class WhiteWinLayer :public Layer {
public:
	CREATE_FUNC(WhiteWinLayer);
	virtual bool init();

public:
	SceneManager * tsm;
};

