#include "TwoPlayersGameLayer.h"

void TwoPlayersGameLayer::init_point() {
	for (int j = 0;j < 15;j++) {
		for (int i = 0;i < 15;i++) {
			a[j][i] = ccp(200 + 40 * j, (40 + 40 * i));
		}
	}


}

bool TwoPlayersGameLayer::init() {
	init_point();//初始化定位点
	Size winsize = Director::getInstance()->getWinSize();


	Sprite * backSky = Sprite::create("res/back_sky.png");//加入星空背景
	backSky->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	this->addChild(backSky);

	Sprite * backGround = Sprite::create("res/board.png");
	backGround->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	this->addChild(backGround);
	this->setTouchEnabled(true);
	return true;
}

void TwoPlayersGameLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event * unused_event) {




	CCPoint locInView = touches[0]->getLocationInView();
	CCPoint loc = CCDirector::sharedDirector()->convertToGL(locInView);
	count++;

	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();
	if (count % 2 == 1) {
		CCSprite *bullet = CCSprite::create("res/black.png");

		int flag = 0;
		for (int i = 0;i < 15;i++) {
			for (int j = 0;j < 15;j++) {
				if (ccpDistance(a[i][j], loc) <= 15 && isHave[i][j] == 0) {
					bullet->setPosition(a[i][j].x, a[i][j].y);
					isHave[i][j] = 1;//黑棋标为1
					flag = 1;
					int blackWin = 0;
					blackWin = judge(i, j, 1);
					if (blackWin == 1)
					{
						tsm->goBlackWinScene();
					}
				}

			}
		}
		if (flag == 0) { count--; }
		this->addChild(bullet);
		bullets.pushBack(bullet);
	}
	else
	{
		CCSprite *bullet = CCSprite::create("res/white.png");

		int flag = 0;
		for (int i = 0;i < 15;i++) {
			for (int j = 0;j < 15;j++) {
				if (ccpDistance(a[i][j], loc) <= 15 && isHave[i][j] == 0) {
					bullet->setPosition(a[i][j].x, a[i][j].y);
					isHave[i][j] = 2;//白棋标为2
					flag = 1;
					int whiteWin = judge(i, j, 2);
					if (whiteWin == 1)
					{
						tsm->goWhiteWinScene();
					}
				}

			}
		}
		if (flag == 0) { count--; }
		this->addChild(bullet);
		bullets.pushBack(bullet);
	}
}

int TwoPlayersGameLayer::judge(int cow, int row, int shape)
{

	//计数器，用来记录连续相同的棋子个数
	int nCount = 0;
	//横向
	nCount = judgeHorizontal(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//竖向
	nCount = judgeVertical(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//向上斜
	nCount = judgeHyperphoria(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//向下斜
	nCount = judgeHypophoria(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//和棋
	if (judgeDraw() == 1)
	{
		return 2;
	}

	return 0;
}

int TwoPlayersGameLayer::judgeHorizontal(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//横向
	//col 列 row 行
	j = col - 1;
	i = row;
	while (j >= 0)
	{
		if (isHave[j--][i] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	j = col + 1;
	while (j <= 14)
	{
		if (isHave[j++][i] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

//判断是否是竖向胜利
int TwoPlayersGameLayer::judgeVertical(int col, int row, int shape)
{
	int i, j;
	int counter = 1;
	//竖向
	j = col;
	i = row - 1;
	while (i >= 0)
	{
		if (isHave[j][i--] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	i = row + 1;
	while (i <= 14)
	{
		if (isHave[j][i++] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}
//判断是否是向左上斜胜利
int TwoPlayersGameLayer::judgeHyperphoria(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//向左上斜
	i = row + 1;
	j = col - 1;
	while (i <= 14 && j >= 0)
	{
		if (isHave[j--][i++] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	i = row - 1;
	j = col + 1;
	while (i >= 0 && j <= 14)
	{
		if (isHave[j++][i--] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

//判断是否是向右上斜胜利
int TwoPlayersGameLayer::judgeHypophoria(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//向右上斜
	i = row + 1;
	j = col + 1;
	while (i <= 14 && j <= 14)
	{
		if (isHave[j++][i++] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	i = row - 1;
	j = col - 1;
	while (i >= 0 && j >= 0)
	{
		if (isHave[j--][i--] == shape)
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	return counter;
}

//判断是否和棋
int TwoPlayersGameLayer::judgeDraw()
{
	int i, j;
	for (i = 0;i < 15;i++)
	{
		for (j = 0;j < 15;j++)
		{
			if (isHave[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}