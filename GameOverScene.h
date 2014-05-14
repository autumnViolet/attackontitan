#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"


using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;
class GameOverScene : public CCLayer
{
public:
	GameOverScene(void);
	~GameOverScene(void);
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(GameOverScene);
private:
	CCSize size;
};

