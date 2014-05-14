#include "VictoryScene.h"


VictoryScene::VictoryScene(void)
{

}


VictoryScene::~VictoryScene(void)
{

}


CCScene* VictoryScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	
	// 'layer' is an autorelease object
	VictoryScene *layer = VictoryScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	
	return scene;
}


bool VictoryScene::init()
{
	size = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *winBg = CCSprite::create("shengliditu.png");
	winBg->setScaleY(0.8);
	winBg->setScaleX(0.6);
	winBg->setPosition(ccp(size.width/2,size.height/2));
	addChild(winBg);
	CCSprite *sp = CCSprite::create("chengqubaoweizhan.png");
	sp->setPosition(ccp(size.width/2,size.height/2));
	sp->setScale(0.3);
	addChild(sp);
	return true;

}
