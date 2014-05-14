#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;


class GameMainScene : public CCLayer
{
public:
	GameMainScene(void);
	~GameMainScene(void);
	virtual bool init();
	static CCScene* scene();
	void fun();
	void menuCallBack(CCObject* pScender);
	void scheCallBack(float dt);
	void update(float dt);
	void turnToScene(); //Ìø×ª³¡¾°
	void loadingCallBack(CCObject* pScender);
	CREATE_FUNC(GameMainScene);
private:
	CCSize size;

};