#pragma once
#include "cocos2d.h"
#include "string.h"

using namespace cocos2d;
using namespace std;
class Giant : public CCNode//���캯��û�е��ã���Ϊ����ǿ������ת�������˸����
{
public:
	Giant();
	~Giant();
     int getScore();
	 int getHP();
	 void setHP(int hp);

private:
	int HP;
    int score;
	int giantKindTag;
};

