//
//  GameMenuLayer.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameMenuLayer.h"
#include "GameMainLayer.h"
#include "GameAboutLayer.h"
#include "SimpleAudioEngine.h"
#include "GameConst.h"

using namespace CocosDenshion;

CCScene* GameMenuLayer::scene()
{
    CCScene *scene = CCScene::create();
    GameMenuLayer *layer = GameMenuLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameMenuLayer::init()
{
    if (!CCLayer::init())
        return false;
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *bg = CCSprite::create("MainMenu.png");
    bg->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(bg, 0, 0);
    
    CCMenuItemImage *newGameItem = CCMenuItemImage::create("newgameA.png", "newgameB.png", this, menu_selector(GameMenuLayer::menuNewGameCallback));
    newGameItem->setPosition(ccp(size.width/2 + 40, size.height/2));
    newGameItem->setEnabled(false);
    
    CCMenuItemImage *continueItem = CCMenuItemImage::create("continueA.png", "continueB.png", this, menu_selector(GameMenuLayer::menuContinueCallback));
    continueItem->setPosition(ccp(size.width/2 + 40, size.height/2 - 60));
    continueItem->setEnabled(false);
    
    CCMenuItemImage *aboutItem = CCMenuItemImage::create("aboutA.png", "aboutB.png", this, menu_selector(GameMenuLayer::menuAboutCallback));
    aboutItem->setPosition(ccp(size.width/2 + 40, size.height/2 - 120));
    aboutItem->setEnabled(false);
    
    soundItem = CCMenuItemImage::create("sound-on-A.png", "sound-on-B.png", this, menu_selector(GameMenuLayer::menuSoundCallback));
    soundItem->setPosition(ccpAdd(ccp(40, 40), originPoint));
    soundItem->setEnabled(false);
    
    CCMenu *mainMenu = CCMenu::create(newGameItem,continueItem,aboutItem,soundItem,NULL);
    mainMenu->setPosition(CCPointZero);
    this->addChild(mainMenu, 1, 3);
    
    this->isSound = CCUserDefault::sharedUserDefault()->getBoolForKey(kBackgroundSound, false);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename("background.mp3").c_str());
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5f);
    if (this->isSound) {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename("background.mp3").c_str(), true);
    }
    
    return true;
}

void GameMenuLayer::onEnter()
{
    CCLayer::onEnter();
    CCNode *mainMenu = this->getChildByTag(3);
    mainMenu->setScale(0);
    mainMenu->runAction(CCSequence::create(CCScaleTo::create(0.5f, 1),CCCallFunc::create(this, callfunc_selector(GameMenuLayer::menuEnter)),NULL));
}

void GameMenuLayer::onExit()
{
    CCLayer::onExit();
}

void GameMenuLayer::menuEnter()
{
    CCNode *mainMenu = this->getChildByTag(3);
    CCArray *items = mainMenu->getChildren();
    for (int i = 0; i < items->count(); i++)
        ((CCMenuItemImage *)items->objectAtIndex(i))->setEnabled(true);
}

void GameMenuLayer::menuNewGameCallback(CCObject *pSender)
{
    CCDirector::sharedDirector()->setDepthTest(true);
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, GameMainLayer::scene(), false));
}

void GameMenuLayer::menuContinueCallback(CCObject *pSender)
{
    CCDirector::sharedDirector()->setDepthTest(true);
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, GameMainLayer::scene(), false));
}

void GameMenuLayer::menuAboutCallback(CCObject *pSender)
{
    CCDirector::sharedDirector()->setDepthTest(true);
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, GameAboutLayer::scene(), false));
}

void GameMenuLayer::menuSoundCallback(CCObject *pSender)
{
    if (!isSound) {
        soundItem->setNormalImage(CCSprite::create("sound-on-A.png"));
        soundItem->setDisabledImage(CCSprite::create("sound-on-B.png"));
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename("background.mp3").c_str(), true);
        isSound = true;
    } else {
        soundItem->setNormalImage(CCSprite::create("sound-off-A.png"));
        soundItem->setDisabledImage(CCSprite::create("sound-off-B.png"));
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
        isSound = false;
    }
    CCUserDefault::sharedUserDefault()->setBoolForKey(kBackgroundSound, isSound);
}

void GameMenuLayer::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
    CCDirector::sharedDirector()->setDepthTest(false);
}

void GameMenuLayer::onExitTransitionDidStart()
{
    CCLayer::onExitTransitionDidStart();
}
