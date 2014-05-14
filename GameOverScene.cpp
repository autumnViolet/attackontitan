#include "GameOverScene.h"


GameOverScene::GameOverScene(void)
{

}


GameOverScene::~GameOverScene(void)
{

}

CCScene* GameOverScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	
	// 'layer' is an autorelease objecj
	GameOverScene *layer = GameOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	
	return scene;
}


bool GameOverScene::init()
{
	size = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *falseBg = CCSprite::create("shibaiditu.png");
	falseBg->setPosition(ccp(size.width/2,size.height/2));
	addChild(falseBg);
	CCSprite *buttonBg = CCSprite::create("continue_fight_text.png");
	Button *continuteButton = Button::create();
	continuteButton->addNode(buttonBg);
	continuteButton->setPosition(ccp(size.width/2,size.height/2));
	addChild(continuteButton);
    CCComAudio *pAudio = CCComAudio::create();
    pAudio->setFile("shibai.mp3");
    pAudio->playBackgroundMusic("shibai.mp3",true);
	return true;
}
