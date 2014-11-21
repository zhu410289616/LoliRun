//
//  GameAboutLayer.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameAboutLayer.h"
#include "GameMenuLayer.h"

CCScene* GameAboutLayer::scene()
{
    CCScene *scene = CCScene::create();
    GameAboutLayer *layer = GameAboutLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameAboutLayer::init()
{
    if (!CCLayer::init())
        return false;
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *bg = CCSprite::create("back_1.png");
    bg->setScale(0.6f);
    bg->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(bg, 0, 0);
    
    CCSprite *kuang = CCSprite::create("tb.png");
    kuang->setScale(0.5f);
    kuang->setRotation(90);
    kuang->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(kuang, 2, 2);
    char info[256];
    sprintf(info, "name : Loli Run\n\nprogram: wa wa\n\nart design: loli\n\ncompany: diqiukeji\n\n              powered by cocos2d-x");
    CCLabelTTF *label = CCLabelTTF::create(info, "Marker Felt", 20, CCSizeMake(400, 400), kCCTextAlignmentLeft);
    label->setAnchorPoint(ccp(0, 1));
    label->setColor(ccc3(0, 0, 0));
    label->setPosition(ccp(100, 260));
    this->addChild(label);
    
    CCSprite *aboutTitle = CCSprite::create("about.png");
    aboutTitle->setPosition(ccp(size.width/2, size.height - 20));
    this->addChild(aboutTitle, 3, 3);
    
    CCMenuItemImage *backItem = CCMenuItemImage::create("backA.png", "backB.png", this, menu_selector(GameAboutLayer::menuBackCallback));
    backItem->setPosition(ccp(size.width - 20, size.height - 20));
    backItem->setEnabled(false);
    CCMenu *mainMenu = CCMenu::create(backItem,NULL);
    mainMenu->setPosition(CCPointZero);
    this->addChild(mainMenu, 3, 4);
    
    return true;
}

void GameAboutLayer::onEnter()
{
    CCLayer::onEnter();
    CCNode *mainMenu = this->getChildByTag(4);
    CCArray *items = mainMenu->getChildren();
    ((CCMenuItemImage *)items->objectAtIndex(0))->setEnabled(true);
}

void GameAboutLayer::onExit()
{
    CCLayer::onExit();
}

void GameAboutLayer::menuBackCallback(CCObject *pSender)
{
    CCDirector::sharedDirector()->setDepthTest(true);
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, GameMenuLayer::scene(), true));
}

void GameAboutLayer::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
    CCDirector::sharedDirector()->setDepthTest(false);
}

void GameAboutLayer::onExitTransitionDidStart()
{
    CCLayer::onExitTransitionDidStart();
}
