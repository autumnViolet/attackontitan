#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class SpecialAttack : public CCNode
{
public:
	SpecialAttack();
	~SpecialAttack();
	virtual	int getDamageValue();
    virtual	int getLevel();
	virtual int getDamagePerson();
	virtual void setDamageValue(int dv);
	virtual void setLevel(int level);
	virtual void setDamagePerson(int dp);
private:
	int damageValue;
	int level;
	int damagePerson;
};

