#include "LoadLayer.h"


bool LoadLayer::init() {

	Label * label = Label::createWithTTF("loading...", "fonts/consola.ttf", 32);
	label->setPosition(Vec2(480, 320));
	this->addChild(label);
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 1.0);
	return true;
}
void LoadLayer::onScheduleOnce(float dt) {

	tsm->goOpenScene();

}