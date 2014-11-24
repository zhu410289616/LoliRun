//
//  TestBackgroundScene.cpp
//  LoliRun
//
//  Created by pig on 14/11/21.
//
//

#include "TestBackgroundScene.h"

CCScene *TestBackgroundScene::scene()
{
    CCScene *scene = CCScene::create();
    TestBackgroundScene *layer = TestBackgroundScene::create();
    scene->addChild(layer);
    return scene;
}

bool TestBackgroundScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *map1 = CCSprite::create("HelloWorld.png");
    CCSprite *map2 = CCSprite::create("HelloWorld.png");
    map1->setPosition(ccp(map1->getContentSize().width/2 + originPoint.x, map1->getContentSize().height/2 + originPoint.y));
    map2->setPosition(ccp(map2->getContentSize().width/2 + originPoint.x + map2->getContentSize().width, map2->getContentSize().height/2 + originPoint.y));
    this->addChild(map1, 0, MAP_1_TAG);
    this->addChild(map2, 0, MAP_2_TAG);
    this->scheduleUpdate();
    return true;
}

void TestBackgroundScene::update(float time)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *tempMap1 = (CCSprite *)this->getChildByTag(MAP_1_TAG);
    CCSprite *tempMap2 = (CCSprite *)this->getChildByTag(MAP_2_TAG);
    
    tempMap1->setPositionX(tempMap1->getPositionX() - 5);
    tempMap2->setPositionX(tempMap2->getPositionX() - 5);
    
    if (tempMap1->getPositionX() + tempMap1->getContentSize().width/2 <= originPoint.x) {
        float offset = tempMap1->getPositionX() + tempMap1->getContentSize().width/2 - originPoint.x;
        tempMap1->setPosition(ccp(tempMap1->getContentSize().width/2 + originPoint.x + visibleSize.width + offset, visibleSize.height/2 + originPoint.y));
    }
    
    if (tempMap2->getPositionX() + tempMap2->getContentSize().width/2 <= originPoint.x) {
        float offset = tempMap2->getPositionX() + tempMap2->getContentSize().width/2 - originPoint.x;
        tempMap2->setPosition(ccp(tempMap2->getContentSize().width/2 + originPoint.x + visibleSize.width + offset, visibleSize.height/2 + originPoint.y));
    }
}

void TestBackgroundScene::onExit()
{
    this->unscheduleUpdate();
    CCLayer::onExit();
}
