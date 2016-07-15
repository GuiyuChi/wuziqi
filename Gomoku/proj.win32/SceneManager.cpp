#include "SceneManager.h"
#include"LoadLayer.h"
#include"OpenLayer.h"
#include "TwoPlayersGameLayer.h"
#include "BlackWinLayer.h"
#include"WhiteWinLayer.h"
#include "OnePlayerGameLayer.h"
#include "LostComputerLayer.h"
#include "WinComputerLayer.h"
USING_NS_CC;






void SceneManager::CreateLoadScene() {
	loadScene = Scene::create();
	LoadLayer * layer = LoadLayer::create();
	layer->tsm = this;
	loadScene->addChild(layer);

}
void SceneManager::goOpenScene() {
	openScene = Scene::create();
	OpenLayer * layer = OpenLayer::create();
	layer->tsm = this;
	openScene->addChild(layer);

	Director::getInstance()->replaceScene(openScene);
}
void SceneManager::goTwoPlayersGameScene() {
	twoPlayersGameScene = Scene::create();
	TwoPlayersGameLayer * layer = TwoPlayersGameLayer::create();
	layer->tsm = this;
	twoPlayersGameScene->addChild(layer);

	Director::getInstance()->replaceScene(twoPlayersGameScene);
}
void  SceneManager::goBlackWinScene() {
	blackWinScene = Scene::create();
	BlackWinLayer * layer = BlackWinLayer::create();
	layer->tsm = this;
	blackWinScene->addChild(layer);
	Director::getInstance()->replaceScene(blackWinScene);
}
void  SceneManager::goWhiteWinScene() {
	whiteWinScene = Scene::create();
	WhiteWinLayer * layer = WhiteWinLayer::create();
	layer->tsm = this;
	whiteWinScene->addChild(layer);
	Director::getInstance()->replaceScene(whiteWinScene);
}
void SceneManager::goOnePlayerGameScene() {
	onePlayerGameScene = Scene::create();
	OnePlayerGameLayer * layer = OnePlayerGameLayer::create();
	layer->tsm = this;
	onePlayerGameScene->addChild(layer);
	Director::getInstance()->replaceScene(onePlayerGameScene);
}
void SceneManager::goWinComputerScene()
{
	winComputerScene = Scene::create();
	WinComputerLayer * layer = WinComputerLayer::create();
	layer->tsm = this;
	winComputerScene->addChild(layer);
	Director::getInstance()->replaceScene(winComputerScene);
}
void SceneManager::goLostComputerScene()
{
	lostComputerScene = Scene::create();
	LostComputerLayer * layer = LostComputerLayer::create();
	layer->tsm = this;
	lostComputerScene->addChild(layer);
	Director::getInstance()->replaceScene(lostComputerScene);
}
