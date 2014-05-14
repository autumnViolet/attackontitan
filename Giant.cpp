#include "Giant.h"


Giant::Giant()
{
	//CCLOG("hello");
	HP = 2;
	score = 10000;
}

Giant::~Giant()
{
	CCLOG("destroy");
	this->release();
}

int Giant::getScore()
{ 
	return score;
}

int Giant::getHP()
{
    return HP;
}

void Giant::setHP(int hp)
{
	HP = hp;
}


