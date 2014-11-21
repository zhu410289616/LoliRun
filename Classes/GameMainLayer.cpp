//
//  GameMainLayer.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameMainLayer.h"
#include "GameMenuLayer.h"
#include "GameObjHero.h"
#include "GameObjStar.h"
#include "GameObjMap.h"
#include "GameMark.h"
#include "GameConst.h"

bool GameMainLayer::init()
{
    if (!CCLayer::init())
        return false;
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    
    map = new GameObjMap();
    map->setAnchorPoint(ccp(0, 1));
    map->setPosition(ccpSub(ccp(0, size.height), originPoint));
    this->addChild(map, 0);
    
    hero = new GameObjHero();
    hero->setScale(0.5f);
    hero->setPosition(ccpAdd(ccp(100, 160), originPoint));
    this->addChild(hero, 1);
    
    gameMark = new GameMark();
    this->addChild(gameMark, 4);
    
    //游戏结束
    gameOver = CCSprite::create("gameover.png");
    gameOver->setScale(0.5f);
    gameOver->setPosition(ccp(size.width/2, size.height/2 + 70));
    gameOver->setVisible(false);
    this->addChild(gameOver, 5);
    
    //菜单项
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create("back.png", "back.png", this, menu_selector(GameMainLayer::menuBackCallback));
    pCloseItem->setPosition(ccp(size.width/2, size.height/2 - 50));
    pCloseItem->setScale(0.5f);
    
    CCMenu *pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 5, 25);
    pMenu->setVisible(false);
    pMenu->setEnabled(false);
    
    this->isOver = false;
    this->scheduleUpdate();
    return true;
}

CCScene *GameMainLayer::scene()
{
    CCScene *scene = CCScene::create();
    GameMainLayer *layer = GameMainLayer::create();
    scene->addChild(layer);
    return scene;
}

void GameMainLayer::onEnter()
{
    CCLayer::onEnter();
}

void GameMainLayer::onExit()
{
    CCLayer::onExit();
}

void GameMainLayer::menuBackCallback(CCObject *pSender)
{
    CCDirector::sharedDirector()->setDepthTest(true);
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, GameMenuLayer::scene(), true));
}

void GameMainLayer::update(float time)
{
    if (hero->state == 0)
        this->isHeroDrop();
    CCPoint pos1 = (map->getChildByTag(0))->getPosition();
    CCPoint pos2 = (map->getChildByTag(1))->getPosition();
    //检测主角是否吃到星星
    for (int i = 0; i < 5; i++) {
        if (pos1.x <= 100 && (pos1.x + 480) >= 100) {
            GameObjStar *star = (GameObjStar *)(map->stars1)->objectAtIndex(i);
            if (star->get_visible() && isCollision(ccp(100,hero->getPosition().y + 62.5), ccp(pos1.x + 86 + 96*i, 280), 40, 35, 18.25, 17.75)) {
                star->set_visible(false);
                gameMark->addNumber(100);
            }
        } else {
            GameObjStar *star = (GameObjStar *)(map->stars2)->objectAtIndex(i);
            if (star->get_visible() && isCollision(ccp(100,hero->getPosition().y + 62.5), ccp(pos2.x + 86 + 96*i, 280), 40, 35, 18.25, 17.75)) {
                star->set_visible(false);
                gameMark->addNumber(100);
            }
        }
    }
}

void GameMainLayer::isHeroDrop()
{
    //判断主角是否从地图掉落
    CCPoint pos1 = (map->getChildByTag(0))->getPosition();
    CCPoint pos2 = (map->getChildByTag(1))->getPosition();
    int temp;
    if (pos1.x <= 100 && (pos1.x + 480) >= 100) {
        temp = (100 - pos1.x)/64;
        if (bg1shu[temp] == -1) {
            hero->setState(2);
        }
    } else {
        temp = (100 - pos2.x)/64;
        if (bg2shu[temp] == -1) {
            hero->setState(2);
        }
    }
}

void GameMainLayer::setOver()
{
    //游戏结束
    CCMenu *pMenu = (CCMenu *)this->getChildByTag(25);
    pMenu->setVisible(true);
    pMenu->setEnabled(true);
    pMenu->setScale(0);
    pMenu->runAction(CCScaleTo::create(0.5f, 1));
    
    gameOver->setVisible(true);
    gameOver->setScale(0);
    gameOver->runAction(CCScaleTo::create(0.5f, 0.5f));
    
    this->isOver = true;
}

bool GameMainLayer::isCollision(CCPoint pos1, CCPoint pos2, int w1, int h1, int w2, int h2)
{
    if (abs(pos1.x - pos2.x) < w1 + w2 && abs(pos1.y - pos2.y) < h1 + h2) {
        return true;
    }
    return false;
}

void GameMainLayer::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
    CCDirector::sharedDirector()->setDepthTest(false);
}

void GameMainLayer::onExitTransitionDidStart()
{
    CCLayer::onExitTransitionDidStart();
}
