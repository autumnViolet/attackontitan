#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class CombatReadinessScene : public CCLayer
{
public:
	CombatReadinessScene(void);
	~CombatReadinessScene(void);
    virtual bool init();
	static CCScene* scene();
	void TitanAttackCallBack(CCObject* pScender);
	void CityDefenceCallBack(CCObject* pScender);
	void WomenTitanCallBack(CCObject* pScender);
    CREATE_FUNC(CombatReadinessScene);
private:
	CCSize size;

};

