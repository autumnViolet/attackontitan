#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class VictoryScene : public CCLayer
{
public:
	VictoryScene(void);
	~VictoryScene(void);
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(VictoryScene);
private:
	CCSize size;
};

