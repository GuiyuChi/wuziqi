#include "WinComputerLayer.h"



bool WinComputerLayer::init() {
	Size winsize = Director::getInstance()->getWinSize();
	Sprite * blackWinBackGround = Sprite::create("res/human_win.png");
	blackWinBackGround->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	this->addChild(blackWinBackGround);

	Button * again = Button::create();
	again->setTouchEnabled(true);
	again->loadTextures("res/again_1.png", "res/again_1.png", "");
	again->setPosition(Vec2(winsize.width / 2 - 138, winsize.height / 2 - 26.5));
	again->addTouchEventListener(this, toucheventselector(WinComputerLayer::ButtentouchEvent_1));
	again->setVisible(true);
	again->setPressedActionEnabled(true);
	this->addChild(again);


	Button * backMenu = Button::create();
	backMenu->setTouchEnabled(true);
	backMenu->loadTextures("res/back_menu_1.png", "res/back_menu_1.png", "");
	backMenu->setPosition(Vec2(winsize.width / 2 + 153, winsize.height / 2 - 24.5));
	backMenu->addTouchEventListener(this, toucheventselector(WinComputerLayer::ButtentouchEvent_2));
	backMenu->setVisible(true);
	backMenu->setPressedActionEnabled(true);
	this->addChild(backMenu);
	return true;
}

void WinComputerLayer::ButtentouchEvent_1(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(WinComputerLayer::onScheduleOnce_1), 0.2);
		break;
	}
}
void WinComputerLayer::ButtentouchEvent_2(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(WinComputerLayer::onScheduleOnce_2), 0.2);
		break;
	}
}
void WinComputerLayer::onScheduleOnce_1(float dt)
{
	clearBoard();
	tsm->goOnePlayerGameScene();
}

void WinComputerLayer::onScheduleOnce_2(float dt)
{
	clearBoard();
	tsm->goOpenScene();
}