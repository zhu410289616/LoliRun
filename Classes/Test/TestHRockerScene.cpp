//
//  TestHRockerScene.cpp
//  LoliRun
//
//  Created by pig on 14/11/24.
//
//

#include "TestHRockerScene.h"
#include "HRocker.h"

CCScene *TestHRockerScene::scene()
{
    CCScene *scene = CCScene::create();
    TestHRockerScene *layer = TestHRockerScene::create();
    scene->addChild(layer);
    return scene;
}

bool TestHRockerScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    //不跟随触点
    CCSprite *spRocker = CCSprite::create("CloseSelected.png");//摇杆
    CCSprite *spRockerBG = CCSprite::create("gameover.png");//摇杆背景
    HRocker *rocker = HRocker::HRockerWithCenter(ccp(150.0f, 130.0f), 50.0f, spRocker, spRockerBG, false);
    this->addChild(rocker);
    
    //跟随触点
    CCSprite *spRocker2 = CCSprite::create("CloseSelected.png");//摇杆
    CCSprite *spRockerBG2 = CCSprite::create("gameover.png");//摇杆背景
    HRocker *rocker2 = HRocker::HRockerWithCenter(ccp(270.0f, 130.0f), 50.0f, spRocker2, spRockerBG2, true);
    this->addChild(rocker2);
    
    return true;
}
