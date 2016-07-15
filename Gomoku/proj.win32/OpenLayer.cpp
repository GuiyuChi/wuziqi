#include "OpenLayer.h"



bool OpenLayer::init() {


	Size winsize = Director::getInstance()->getWinSize();
	Sprite * backGround = Sprite::create("res/title.png");
	//Label *label = Label::create();
	backGround->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	this->addChild(backGround);


	Button * button_1 = Button::create();
	button_1->setTouchEnabled(true);
	button_1->loadTextures("res/start_4.png", "res/start_4.png", "");
	button_1->setPosition(Vec2(winsize.width / 2 - 200, winsize.height*0.30));
	button_1->addTouchEventListener(this, toucheventselector(OpenLayer::ButtentouchEvent_1));
	button_1->setVisible(true);
	button_1->setPressedActionEnabled(true);
	this->addChild(button_1);

	Button * button_2 = Button::create();
	button_2->setTouchEnabled(true);
	button_2->loadTextures("res/start_3.png", "res/start_3.png", "");
	button_2->setPosition(Vec2(winsize.width / 2, winsize.height*0.30));
	button_2->addTouchEventListener(this, toucheventselector(OpenLayer::ButtentouchEvent_2));
	button_2->setVisible(true);
	button_2->setPressedActionEnabled(true);
	this->addChild(button_2);

	/*enuItemLabel * menuItem_2 = MenuItemLabel::create(Label::createWithSystemFont("Exit", "", 30), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem_2->setTag(102);
	menuItem_2->setPosition(Vec2(winsize.width / 2+150, winsize.height*0.3));
	*/

	Button * button_3 = Button::create();
	button_3->setTouchEnabled(true);
	button_3->loadTextures("res/exit.png", "res/exit.png", "");
	button_3->setPosition(Vec2(winsize.width / 2 + 200, winsize.height*0.30));
	button_3->addTouchEventListener(this, toucheventselector(OpenLayer::ButtentouchEvent_3));
	button_3->setVisible(true);
	button_3->setPressedActionEnabled(true);
	this->addChild(button_3);


	return true;
}

void OpenLayer::menuCallBack(Ref *pSender) {

	switch (((MenuItem*)pSender)->getTag()) {
	case 101:
	{
		tsm->goTwoPlayersGameScene();
	}
	break;
	case 102:
	{
		Director::getInstance()->end();
		exit(0);
	}
	break;
	case 103:
	{
		tsm->goOnePlayerGameScene();
	}
	break;


	}




}

void OpenLayer::menuItemStartCallback(Ref *pSender) {

	Director::getInstance()->end();
	tsm->goTwoPlayersGameScene();
}
void OpenLayer::ButtentouchEvent_1(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(OpenLayer::onScheduleOnce_1), 0.2);
		break;
	}
}
void OpenLayer::ButtentouchEvent_2(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(OpenLayer::onScheduleOnce_2), 0.2);
		break;
	}
}
void OpenLayer::ButtentouchEvent_3(Object *pSender, TouchEventType type)
{
	Button * butten = (Button *)pSender;
	unsigned int tag = butten->getTag();
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		scheduleOnce(CC_SCHEDULE_SELECTOR(OpenLayer::onScheduleOnce_3), 0.2);
		break;
	}
}
void OpenLayer::onScheduleOnce_1(float dt)
{
	tsm->goTwoPlayersGameScene();
}
void OpenLayer::onScheduleOnce_2(float dt)
{
	
	tsm->goOnePlayerGameScene();
}
void OpenLayer::onScheduleOnce_3(float dt)
{
	
	Director::getInstance()->end();
}