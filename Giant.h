#pragma once
#include "cocos2d.h"
#include "string.h"

using namespace cocos2d;
using namespace std;
class Giant : public CCNode//构造函数没有调用，因为用了强制类型转换而用了父类的
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

