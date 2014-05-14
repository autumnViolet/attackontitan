#include "BattleScene.h"



BattleScene::BattleScene(void)
{
	_Giant = CCArray::create();
	_Giant->retain();
	_Bullet = CCArray::create();
	_Bullet->retain();
}


BattleScene::~BattleScene(void)
{
}
bool BattleScene::init()
{
	count = 0;
	size = CCDirector::sharedDirector()->getVisibleSize();
	//bg
	sp1= CCSprite::create("Scenetest.png");
	sp1->setScaleX(0.4);
	sp1->setScaleY(0.8);
	sp1->setPosition(ccp(size.width/2,size.height/2));
	//血条
	CCSprite *sp2 = CCSprite::create("zhujiemian_zhd.png");
	sp2->setPosition(ccp(size.width/2,440));
	sp2->setScaleX(0.5);
	sp2->setScaleY(0.4);
	sp2->setZOrder(10);
	addChild(sp1);
	addChild(sp2);
	CCSprite *HPBarBg = CCSprite::create("tili_tiao_white.png"); //底图
	CCSprite *HPBarFg = CCSprite::create("tili_tiao.png");
	HPBar = CCProgressTimer::create(HPBarFg);	
	HPBar->setType(kCCProgressTimerTypeBar);
	HPBar->setPercentage(100);
	HPBar->setBarChangeRate(ccp(1,0));//设置横向
	HPBar->setMidpoint(ccp(0,1));//设置从右往左
	HPBar->setZOrder(15);
	float HPPositionX = sp2->getPositionX()+65;
	float HPPositionY = 105;
	HPBar->setPosition(ccp(HPPositionX,HPPositionY));
	HPBarBg->setPosition(ccp(HPPositionX,HPPositionY));
	sp2->addChild(HPBar);
	sp2->addChild(HPBarBg);
	//得分
	float scorePositionX = sp2->getPositionX()+300;
	float scorePositionY = 100;
	score = CCLabelAtlas::create("0","labelatlasimg.png",24,32,'0');
	score->setPosition(ccp(scorePositionX,scorePositionY));
	sp2->addChild(score);
	//特殊攻击
	CCMenuItemImage *item1= CCMenuItemImage::create("tx_H130021.png","tx_H130021.png",this,menu_selector(BattleScene::SpecialAttackCallBack1));
	CCMenuItemImage *item2= CCMenuItemImage::create("tx_H130002.png","tx_H130002.png",this,menu_selector(BattleScene::SpecialAttackCallBack2)); 
	CCMenuItemImage *item3= CCMenuItemImage::create("tx_H130014.png","tx_H130014.png",this,menu_selector(BattleScene::SpecialAttackCallBack3)); 
	item1->setPosition(ccp(60,size.height-10));
	item1->setScale(0.25);
	item2->setPosition(ccp(90,size.height-10));
	item2->setScale(0.25);
	item3->setPosition(ccp(120,size.height-10));
	item3->setScale(0.25);
	CCMenu *menu = CCMenu::create(item1,item2,item3,NULL);
    menu->setPosition(CCPointZero);
	menu->setZOrder(20);
	addChild(menu);
	schedule(schedule_selector(BattleScene::addGiant),2.0f);
	schedule(schedule_selector(BattleScene::addBullet),3.0f);
	schedule(schedule_selector(BattleScene::updateGame));
	CCComAudio *pAudio = CCComAudio::create();
    pAudio->setFile("BattleBGM.mp3");
    pAudio->playBackgroundMusic("BattleBGM.mp3",true);
	return true;
}
CCScene* BattleScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	BattleScene *layer = BattleScene::create();

	// add layer as a child to scene
	scene->addChild(layer);


	return scene;
}

void BattleScene::updateGame(float dt)
{
	CCArray *giantToDelete = new CCArray;
	CCObject* it = NULL;
	CCObject* jt = NULL;
	CCARRAY_FOREACH(_Giant,it)
	{
		Giant *giant = (Giant*)(it);
		//judge collision
		CCRect giantRect = giant->boundingBox();
		float x = giantRect.origin.x+giantRect.size.width *0.3;
		float y = giantRect.origin.y+giantRect.size.height*0.5;
		float width = giantRect.size.width * 0.3;
		float height = giantRect.size.height * 0.6;
		CCRect final_Giant_Rect = CCRectMake(x,y,width,height);
		CCArray *bulletToDelete = new CCArray;
		CCARRAY_FOREACH(_Bullet,jt)
		{
			Bullet *bullet = (Bullet*)(jt);
			CCRect bulletRect = CCRectMake(
				bullet->getPosition().x - (bullet->getContentSize().width/2),
				bullet->getPosition().y - (bullet->getContentSize().height/2),
				bullet->getContentSize().width,
				bullet->getContentSize().height);
			if(final_Giant_Rect.intersectsRect(bulletRect))
			{
				bulletToDelete->addObject(bullet);
				hitParticle(giantRect.origin.x+giantRect.size.width*0.5,giantRect.origin.y);
			if(updateGiantHP(giant))
			{
				explodingParticle(giantRect.origin.x+giantRect.size.width*0.5,giantRect.origin.y);
				updateScore(giant);
				giantToDelete->addObject(giant);
			}
			}
		}
		CCARRAY_FOREACH(bulletToDelete,jt)
		{
			Bullet *bullet = (Bullet*)(jt);
			_Bullet->removeObject(bullet);
			this->removeChild(bullet,true);
		}
		bulletToDelete->release();
	}
	CCARRAY_FOREACH(giantToDelete, it)
	{
		Giant* giant = (Giant*)(it);
		_Giant->removeObject(giant);
		this->removeChild(giant, true);
	}
	giantToDelete->release();
	//判断血条
	gameLogic();

}
void BattleScene::addGiant(float dt)
{
	Giant *g = new Giant;
	CCSprite *bg = CCSprite::create("giant.png");
	g->addChild(bg);
	Giant *temp = NULL;
	g->setPosition(ccp(30,480));
	g->setScale(0.3);
	g->setTag(1);
	CCActionInterval *moveto = CCMoveTo::create(15,ccp(30,-100));
	g->runAction(moveto);
	this->addChild(g);
	//add to container
	_Giant->addObject(g);
}

void BattleScene::addBullet(float dt)
{
	Bullet *b= (Bullet *)CCSprite::create("paodan.png");
	b->setPosition(ccp(30,20));
	b->setScale(0.3);
	b->setTag(2);
	b->setRotation(170);
	CCActionInterval *hit = CCMoveTo::create(10,ccp(30,480));
	b->runAction(hit);
	addChild(b);
	_Bullet->addObject(b);
	
}

void BattleScene::explodingParticle(float positionX,float positionY)
{
	CCParticleSystem *particle = CCParticleSystemQuad::create("example.plist");
	particle->setPosition(positionX,positionY);
	addChild(particle);
}

void BattleScene::hitParticle(float positionX,float positionY)
{
	CCParticleSystem *particle = CCParticleSystemQuad::create("hit.plist");
	particle->setPosition(positionX,positionY);
	addChild(particle);
}

void BattleScene::gameLogic()
{
	int count = 0;
	CCObject* it = NULL;
	CCObject* jt = NULL;
	CCArray *giantToDelete = CCArray::create();
	giantToDelete->retain();
	CCARRAY_FOREACH(_Giant,it)
	{
		Giant *giant = (Giant *)it;
		CCRect collisionRect = sp1->boundingBox();
		float x = collisionRect.origin.x;
		float y = collisionRect.origin.y-collisionRect.size.height;
		float width = collisionRect.size.width;
		float height = collisionRect.size.height;
		CCRect final_collisionRect = CCRectMake(x,y,width,height);
		if(giant->boundingBox().intersectsRect(final_collisionRect))
		{
			giant->setVisible(false);
			giantToDelete->addObject(giant);
			HPBar->setPercentage(HPBar->getPercentage()-50);
		}
	}
	CCARRAY_FOREACH(giantToDelete,jt)
	{
		Giant *giant = (Giant *)jt;
		_Giant->removeObject(giant);
		this->removeChild(giant,true);
	}
	if(HPBar->getPercentage()==0)
	{ 
		CCScene *scene = GameOverScene::scene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.8f,scene));
	}
	if(atoi(score->getString())>=50000)
	{
		CCLOG("win!!!");
		CCScene *scene = VictoryScene::scene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.8f,scene));
	}
	//CCLOG(score->getString());
}

void BattleScene::updateScore(Giant *giant)
{
	//利用case判断巨人种类
	int a=0,b;
	const char *getTempString = score->getString();
	a=atoi(getTempString);
	a+=giant->getScore();
	char final_string[50]={0};
	sprintf(final_string,"%d",a);
	score->setString(final_string);
}

bool BattleScene::updateGiantHP(Giant *giant)
{
	int HP = giant->getHP();
	HP-=1;
	giant->setHP(HP);
	if(giant->getHP()==0)
	{
		giant->setVisible(false);
		return true;
	}
	return false;
}

 void BattleScene::SpecialAttackCallBack1(CCObject* pScender)
 {
	 CCLOG("Special");
	 CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	 cache->addSpriteFramesWithFile("TitanSpecial2.plist");

	 animate1=CCSprite::createWithSpriteFrameName("TitanSpecial20001.png");
	 animate1->setPosition(ccp(size.width/2,size.height/2));
	 addChild(animate1);

	 char str[30]={0};
	 CCArray *array = CCArray::create();

	 for(int i=1;i<18;i++)
	 {
		 sprintf(str,"TitanSpecial200%02d.png",i);
		 CCSpriteFrame *frame = cache->spriteFrameByName(str);
		 array->addObject(frame);
	 }

	 CCAnimation *animation = CCAnimation::createWithSpriteFrames(array,0.1f);
	 animate1->runAction(CCRepeat::create(CCAnimate::create(animation),1));
	 Alldamage();
	 scheduleOnce(schedule_selector(BattleScene::updateAnimate1),1.0f);
 }

  void BattleScene::SpecialAttackCallBack2(CCObject* pScender)
  {
	 CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	 cache->addSpriteFramesWithFile("AllHit.plist");

	 animate2= CCSprite::createWithSpriteFrameName("AllHit0001.png");
	 animate2->setPosition(ccp(size.width/2,size.height/2));
	 addChild(animate2);

	 char str[30]={0};
	 CCArray *array = CCArray::create();

	 for(int i=1;i<16;i++)
	 {
		 sprintf(str,"AllHit00%02d.png",i);
		 CCSpriteFrame *frame = cache->spriteFrameByName(str);
		 array->addObject(frame);
	 }

	 CCAnimation *animation = CCAnimation::createWithSpriteFrames(array,0.08f);
	 animate2->runAction(CCRepeat::create(CCAnimate::create(animation),1));
	 scheduleOnce(schedule_selector(BattleScene::updateAnimate2),1.0f);
  }
  
  void BattleScene::SpecialAttackCallBack3(CCObject* pScender)
  {
	 CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	 cache->addSpriteFramesWithFile("TitanSpecial.plist");

	 animate3 = CCSprite::createWithSpriteFrameName("TitanSpecial0001.png");
	 animate3->setPosition(ccp(size.width/2,size.height/2));
	 this->addChild(animate3);

	 char str[30]={0};
	 CCArray *array = CCArray::create();

	 for(int i=1;i<11;i++)
	 {
		 sprintf(str,"TitanSpecial00%02d.png",i);
		 CCSpriteFrame *frame = cache->spriteFrameByName(str);
		 array->addObject(frame);
	 }

	 CCAnimation *animation = CCAnimation::createWithSpriteFrames(array,0.1f);
	 animate3->runAction(CCRepeat::create(CCAnimate::create(animation),1));
	  scheduleOnce(schedule_selector(BattleScene::updateAnimate3),1.0f);
  }

  void BattleScene::Alldamage()
  {
	CCObject* it = NULL;
	CCObject* jt = NULL;
	CCArray *giantToDelete = CCArray::create();
	giantToDelete->retain();
	CCARRAY_FOREACH(_Giant,it)
	{
		Giant *giant = (Giant *)it;
		CCRect giantRect = giant->boundingBox();
	    explodingParticle(giantRect.origin.x+giantRect.size.width*0.5,giantRect.origin.y);
		giant->setVisible(false);
		giantToDelete->addObject(giant);
		updateScore(giant);
		
	}

	CCARRAY_FOREACH(giantToDelete,jt)
	{
		Giant *giant = (Giant *)jt;
		_Giant->removeObject(giant);
		this->removeChild(giant,true);
	}
  }

  void BattleScene::updateAnimate1(float dt)
  {
	  animate1->setVisible(false);
  }

  void BattleScene::updateAnimate2(float dt)
  {
	  animate2->setVisible(false);
  }

   void BattleScene::updateAnimate3(float dt)
  {
	  animate3->setVisible(false);
  }
