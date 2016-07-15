

#pragma once


#include<iostream>
#include"cocos2d.h"

USING_NS_CC;


class SceneManager
{
public:
	Scene * loadScene;
	Scene * openScene;
	Scene * twoPlayersGameScene;
	Scene * onePlayerGameScene;
	Scene * blackWinScene;
	Scene * whiteWinScene;
	Scene * winComputerScene;
	Scene * lostComputerScene;
	Scene * onePlayerGameSceneWhite;
	void CreateLoadScene();
	void goOpenScene();
	void goTwoPlayersGameScene();
	void goBlackWinScene();
	void goWhiteWinScene();
	void goOnePlayerGameScene();
	void goWinComputerScene();
	void goLostComputerScene();

};

