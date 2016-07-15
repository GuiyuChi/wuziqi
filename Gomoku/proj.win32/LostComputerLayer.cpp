#include "LostComputerLayer.h"



bool LostComputerLayer::init() {
	Size winsize = Director::getInstance()->getWinSize();
	Sprite * blackWinBackGround = Sprite::create("res/ai_win.png");
	blackWinBackGround->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	this->addChild(blackWinBackGround);

	Button * again = Button::create();
	again->setTouchEnabled(true);
	again->loadTextures("res/again_1.png", "res/again_1.png", "");
	again->setPosition(Vec2(winsize.width / 2 - 138, winsize.height / 2 - 26.5));
	again->addTouchEventListener(this, toucheventselector(LostComputerLayer::ButtentouchEvent_1));
	again->setVisible(true);
	again->setPressedActionEnabled(true);
	this->addChild(again);


	Button * backMenu = Button::create();
	backMenu->setTouchEnabled(true);
	backMenu->loadTextures("res/back_menu_1.png", "res/back_menu_1.png", "");
	backMenu->setPosition(Vec2(winsize.width / 2 + 153, winsize.height / 2 - 24.5));
	backMenu->addTouchEventListener(this, toucheventselector(LostComputerLayer::ButtentouchEvent_2));
	backMenu->setVisible(true);
	backMenu->setPressedActionEnabled(true);
	this->addChild(backMenu);
	return true;
}

void LostComputerLayer::ButtentouchEvent_1(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(LostComputerLayer::onScheduleOnce_1), 0.2);
		break;
	}
}
void LostComputerLayer::ButtentouchEvent_2(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(LostComputerLayer::onScheduleOnce_2), 0.2);
		break;
	}
}
void LostComputerLayer::onScheduleOnce_1(float dt)
{
	clearBoard();
	tsm->goOnePlayerGameScene();
}

void LostComputerLayer::onScheduleOnce_2(float dt)
{
	clearBoard();
	tsm->goOpenScene();
}