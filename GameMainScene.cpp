#include "GameMainScene.h"
#include "BattleScene.h"
#include "HelloWorldScene.h"
#include "CombatReadinessScene.h"

GameMainScene::GameMainScene(void)
{
}


GameMainScene::~GameMainScene(void)
{
}

bool GameMainScene::init()
{
	 size = CCDirector::sharedDirector()->getVisibleSize();
	 CCLOG("width:%f,height:%f",size.width,size.height);
	 CCSprite *sp1 = CCSprite::create("denglu_bj.jpg");
	 sp1->setPosition(ccp(size.width/2,size.height/2));
	 sp1->setScale(0.5);
	 this->addChild(sp1);
	 CCPoint point = CCDirector::sharedDirector()->convertToUI(sp1->getPosition());
	 CCLOG("x:%f,y:%f",point.x,point.y);
	 CCMenuItemImage *item1 = CCMenuItemImage::create("anniu_01_still.png","anniu_01_over.png",this,menu_selector(GameMainScene::menuCallBack)); 
	 CCMenuItemImage *item2 = CCMenuItemImage::create("anniu_01_still.png","anniu_01_over.png",this,menu_selector(GameMainScene::menuCallBack));   
	 CCSprite *juqingimage = CCSprite::create("juqingmoshi_anniu.png");
	 CCSprite *tiaozhanimage = CCSprite::create("tiaozhanmoshi_anniu.png");
	 juqingimage->setPosition(ccp(size.width/2,size.height/1.8));
	 juqingimage->setScale(0.4);
	 juqingimage->setZOrder(20);
	 tiaozhanimage->setPosition(ccp(size.width/2,size.height/2.1));
	 tiaozhanimage->setScale(0.4);
	 tiaozhanimage ->setZOrder(20);
	 addChild(juqingimage);
	 addChild(tiaozhanimage);
	 item1->setPosition(ccp(size.width/2,size.height/1.8));
	 item1->setScale(0.4);
	 item2->setPosition(ccp(size.width/2,size.height/2.1));
	 item2->setScale(0.4);
	 CCMenu *menu = CCMenu::create(item1,item2,NULL);
	 menu->setPosition(CCPointZero);
	 this->addChild(menu);
	 //ding shi qi
   	 return true;
}

CCScene* GameMainScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	
	// 'layer' is an autorelease object
	GameMainScene *layer = GameMainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	
	return scene;
}

void GameMainScene::fun()
{
	CCSprite *sp1 =(CCSprite* )this->getChildByTag(3);
	sp1->setScale(3);
}
void GameMainScene::menuCallBack(CCObject* pScender)
{
	CCScene *scene = HelloWorld::scene();
	turnToScene();
}
void GameMainScene::scheCallBack(float dt)
{

	CCScene *scene = CombatReadinessScene::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,scene));
}
void GameMainScene::update(float dt)
{

}
void GameMainScene::turnToScene()
{
	CCSprite *sp = CCSprite::create("waiting.png");
	sp->setPosition(ccp(size.width/2,size.height/2));
	sp->setZOrder(30);
	CCActionInterval *rotation= CCRotateTo::create(3.0f,0,720);
	sp->runAction(rotation);
    scheduleOnce(schedule_selector(GameMainScene::scheCallBack),3.0f);
	addChild(sp);
}
