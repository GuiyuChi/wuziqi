#include "TwoPlayersGameLayer.h"

void TwoPlayersGameLayer::init_point() {
	for (int j = 0;j < 15;j++) {
		for (int i = 0;i < 15;i++) {
			a[j][i] = ccp(200 + 40 * j, (40 + 40 * i));
		}
	}


}

bool TwoPlayersGameLayer::init() {
	init_point();//��ʼ����λ��
	Size winsize = Director::getInstance()->getWinSize();


	Sprite * backSky = Sprite::create("res/back_sky.png");//�����ǿձ���
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
					isHave[i][j] = 1;//�����Ϊ1
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
					isHave[i][j] = 2;//�����Ϊ2
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

	//��������������¼������ͬ�����Ӹ���
	int nCount = 0;
	//����
	nCount = judgeHorizontal(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//����
	nCount = judgeVertical(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//����б
	nCount = judgeHyperphoria(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//����б
	nCount = judgeHypophoria(cow, row, shape);
	if (nCount >= 5)
	{
		return 1;
	}

	//����
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


	//����
	//col �� row ��
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

//�ж��Ƿ�������ʤ��
int TwoPlayersGameLayer::judgeVertical(int col, int row, int shape)
{
	int i, j;
	int counter = 1;
	//����
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
//�ж��Ƿ���������бʤ��
int TwoPlayersGameLayer::judgeHyperphoria(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//������б
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

//�ж��Ƿ���������бʤ��
int TwoPlayersGameLayer::judgeHypophoria(int col, int row, int shape)
{
	int i, j;
	int counter = 1;


	//������б
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

//�ж��Ƿ����
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