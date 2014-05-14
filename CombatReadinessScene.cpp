#include "CombatReadinessScene.h"
#include "BattleScene.h"

CombatReadinessScene::CombatReadinessScene(void)
{
}


CombatReadinessScene::~CombatReadinessScene(void)
{
}

CCScene* CombatReadinessScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	
	// 'layer' is an autorelease objecj
	CombatReadinessScene *layer = CombatReadinessScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	
	return scene;
}


bool CombatReadinessScene::init()
{
	size = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *zhunbeiBg = CCSprite::create("zhujiem_beij.jpg");
    zhunbeiBg->setPosition(ccp(size.width/2,size.height/2));
	zhunbeiBg->setScaleY(0.5);
	addChild(zhunbeiBg);
	CCMenuItemImage *juqingItem1 = CCMenuItemImage::create("anniu_01_still.png","anniu_01_over.png",this,menu_selector(CombatReadinessScene::TitanAttackCallBack)); 
	CCMenuItemImage *juqingItem2 = CCMenuItemImage::create("anniu_01_still.png","anniu_01_over.png",this,menu_selector(CombatReadinessScene::CityDefenceCallBack));  
	CCMenuItemImage *juqingItem3 = CCMenuItemImage::create("anniu_01_still.png","anniu_01_over.png",this,menu_selector(CombatReadinessScene::WomenTitanCallBack));
	CCMenu *juqingMenu = CCMenu::create(juqingItem1,juqingItem2,juqingItem3,NULL);
	CCSprite *jurenlaixi = CCSprite::create("jurenlaixi.png");
	jurenlaixi->setPosition(ccp(size.width/2,size.height/1.3));
	jurenlaixi->setScale(0.7);
	jurenlaixi->setZOrder(10);
	addChild(jurenlaixi);
	CCSprite *chengshifangyu = CCSprite::create("chengqubaoweizhan.png");
	chengshifangyu->setPosition(ccp(size.width/2,size.height/1.78));
	chengshifangyu->setScale(0.7);
	chengshifangyu->setZOrder(10);
	addChild(chengshifangyu);
	CCSprite *nvjuren = CCSprite::create("nvjuren.png");
	nvjuren->setPosition(ccp(size.width/2,size.height/2.8));
	nvjuren->setScale(0.7);
	nvjuren->setZOrder(10);
	addChild(nvjuren);
	juqingItem1->setPosition(ccp(size.width/2,size.height/1.3));
	juqingItem2->setPosition(ccp(size.width/2,size.height/1.78));
	juqingItem3->setPosition(ccp(size.width/2,size.height/2.8));
	juqingMenu->setPosition(CCPointZero);
	this->addChild(juqingMenu);
	CCMenuItemImage *Item1 = CCMenuItemImage::create("jingji_still.png","jingji_over.png",this,menu_selector(CombatReadinessScene::TitanAttackCallBack)); 
	CCMenuItemImage *Item2 = CCMenuItemImage::create("tubiao_zhz_still.png","tubiao_zhz_over.png",this,menu_selector(CombatReadinessScene::CityDefenceCallBack));  
	CCMenuItemImage *Item3 = CCMenuItemImage::create("tubiao_sy_still.png","tubiao_sy_over.png",this,menu_selector(CombatReadinessScene::WomenTitanCallBack));
	CCMenuItemImage *Item4 = CCMenuItemImage::create("tubiao_sz_still.png","tubiao_sz_over.png",this,menu_selector(CombatReadinessScene::WomenTitanCallBack));
	CCMenu *Menu = CCMenu::create(Item1,Item2,Item3,Item4,NULL);
	Item1->setPosition(ccp(0,0));
	Item1->setAnchorPoint(CCPointZero);
	Item1->setScale(0.5);
	Item2->setPosition(ccp(90,0));
	Item2->setAnchorPoint(CCPointZero);
	Item2->setScale(0.5);
	Item3->setPosition(ccp(180,0));
	Item3->setAnchorPoint(CCPointZero);
	Item3->setScale(0.5);
	Item4->setPosition(ccp(270,0));
	Item4->setAnchorPoint(CCPointZero);
	Item4->setScale(0.5);
	Menu->setPosition(CCPointZero);
	this->addChild(Menu);
	CCSprite *backBt = CCSprite::create("backbutton.png");
	backBt->setAnchorPoint(CCPointZero);
	backBt->setScale(0.5);
	backBt->setPosition(ccp(0,size.height-backBt->getContentSize().height*0.5));
	addChild(backBt);
	return true;
}

void CombatReadinessScene::TitanAttackCallBack(CCObject* pScender)
{
    
	 CCSprite *sp = CCSprite::create("female_type_sign.png");
	 sp->setPosition(ccp(size.width/2,size.height/2));
	 sp->setZOrder(30);
	 CCActionInterval *rotation= CCRotateTo::create(3.0f,0,720);
	 sp->runAction(rotation);
	 addChild(sp);
	 CCScene *scene = BattleScene::scene();
	 CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(5.0f,scene));

}

void CombatReadinessScene::CityDefenceCallBack(CCObject* pScender)
{

}

void CombatReadinessScene::WomenTitanCallBack(CCObject* pScender)
{

}


