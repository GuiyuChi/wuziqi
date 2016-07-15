#include "OnePlayerGameLayer.h"
#include"AI.h"


void OnePlayerGameLayer::init_point() {
	for (int j = 0;j < 15;j++) {
		for (int i = 0;i < 15;i++) {
			a[j][i] = ccp(200 + 40 * j, (40 + 40 * i));
		}
	}


}
bool OnePlayerGameLayer::init() {
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
void OnePlayerGameLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event * unused_event)
{


	CCPoint locInView = touches[0]->getLocationInView();
	CCPoint loc = CCDirector::sharedDirector()->convertToGL(locInView);
	//count++;//����
	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();

	//����º���
	int flag_black = 0;
	//while (flag_black == 0)
	//{
		CCSprite * blackChess = CCSprite::create("res/black.png");
		//������ʧ���޷����£�������Ϊ����ʧ��
		for (int i = 0;i < 15;i++) {
			for (int j = 0;j < 15;j++) {
				if (ccpDistance(a[i][j], loc) <= 20 && isHave[i][j] == 0) {
					blackChess->setPosition(a[i][j].x, a[i][j].y);
					isHave[i][j] = 1;//�����Ϊ1
					flag_black = 1;
					int blackWin = 0;
					blackWin = judge(i, j, 1);

					this->addChild(blackChess);
					bullets.pushBack(blackChess);

					if (blackWin == 1)
					{
						tsm->goWinComputerScene();
					}
				}

			}
		}
		if (flag_black == 0)
		{
			goto end;
		}

	//}

	//�����°���
	int flag_white = 0;
	while (flag_white == 0) 
	{
		CCSprite * whiteChess = CCSprite::create("res/white.png");
		float aiX, aiY;
		aiX = 200 + 40 * (Ai().resultX);
		aiY = 40 + 40 * (Ai().resultY);
		//����Ϊʵ������
		for (int i = 0;i < 15;i++) {
			for (int j = 0;j < 15;j++) {
				if (ccpDistance(a[i][j], ccp(aiX, aiY)) <= 15 && isHave[i][j] == 0) {
					whiteChess->setPosition(a[i][j].x, a[i][j].y);

					this->addChild(whiteChess);
					bullets.pushBack(whiteChess);

					isHave[i][j] = 2;//�����Ϊ2
					flag_white = 1;
					int whiteWin = judge(i, j, 2);
					if (whiteWin == 1)
					{
						tsm->goLostComputerScene();
					}
				}

			}
		}
	}
end:return;
}






int OnePlayerGameLayer::judge(int cow, int row, int shape)
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

int OnePlayerGameLayer::judgeHorizontal(int col, int row, int shape)
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
int OnePlayerGameLayer::judgeVertical(int col, int row, int shape)
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
int OnePlayerGameLayer::judgeHyperphoria(int col, int row, int shape)
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
int OnePlayerGameLayer::judgeHypophoria(int col, int row, int shape)
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
int OnePlayerGameLayer::judgeDraw()
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