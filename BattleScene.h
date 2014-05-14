#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Giant.h"
#include "Bullet.h"
#include "string.h"
#include "stdlib.h"
#include "ErenAttack.h"
#include "GameOverScene.h"
#include "VictoryScene.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;
using namespace std;

class BattleScene :public CCLayer
{
public:
	BattleScene(void);
	~BattleScene(void);
	virtual bool init();
	void updateGame(float dt);
	static CCScene* scene();
	void addGiant(float dt);
	void addBullet(float dt);
	void gameLogic();
	void updateAnimate1(float dt);
	void updateAnimate2(float dt);
	void updateAnimate3(float dt);
	void hitParticle(float positionX, float PositionY);
	void explodingParticle(float positionX,float positionY);
	void turnToGameOverScene();
	void updateScore(Giant *giant);
	bool updateGiantHP(Giant *giant);
    void SpecialAttackCallBack1(CCObject* pScender);
	void SpecialAttackCallBack2(CCObject* pScender);
	void SpecialAttackCallBack3(CCObject* pScender);
	void Alldamage();
	CREATE_FUNC(BattleScene);
private:
	CCSize size;
    CCSprite *sp1;
	CCArray* _Giant;
	CCArray* _Bullet;
	CCProgressTimer *HPBar;
	CCLabelAtlas *score;
	ErenAttack *attack1;
	CCSprite *animate1;
	CCSprite *animate2;
	CCSprite *animate3;
	int count;

};

