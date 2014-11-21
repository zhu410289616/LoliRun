//
//  GameObjMap.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameObjMap.h"
#include "GameObjStar.h"
#include "GameConst.h"

GameObjMap::GameObjMap()
{
}

GameObjMap::~GameObjMap()
{
}

void GameObjMap::onEnter()
{
    CCNode::onEnter();
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
//    this->setContentSize(CCSizeMake(960, 320));
    this->setContentSize(CCSizeMake(size.width, size.height/2));
    
    //初始化背景
    CCSprite *skyBg1 = CCSprite::create("back_1.png");
//    skyBg1->setScale(0.5f);
    skyBg1->setAnchorPoint(ccp(0, 1));
    skyBg1->setPosition(ccp(0, size.height));
    this->addChild(skyBg1, 0, 0);
    
    CCSprite *groundBg1 = CCSprite::create("back_5.png");
    groundBg1->setAnchorPoint(ccp(0, 0));
    groundBg1->setPosition(ccp(0, -124));
    skyBg1->addChild(groundBg1, 1);
    
    CCSprite *skyBg2 = CCSprite::create("back_1.png");
//    skyBg2->setScale(0.5f);
    skyBg2->setAnchorPoint(ccp(0, 1));
    skyBg2->setPosition(ccp(size.width, size.height));
    this->addChild(skyBg2, 0, 1);
    
    CCSprite *groundBg2 = CCSprite::create("back_5.png");
    groundBg2->setAnchorPoint(ccp(0, 0));
    groundBg2->setPosition(ccp(0, -124));
    skyBg2->addChild(groundBg2, 1);
    
    skyBg1->runAction(CCSequence::create(CCMoveBy::create(6, ccp(-480, 0)),CCCallFunc::create(this, callfunc_selector(GameObjMap::bg1Change)),NULL));
    skyBg2->runAction(CCSequence::create(CCMoveBy::create(12, ccp(-960, 0)),CCCallFunc::create(this, callfunc_selector(GameObjMap::bg2Change)),NULL));
    
    stars1 = CCArray::createWithCapacity(5);
    stars2 = CCArray::createWithCapacity(5);
    for (int i = 0; i < 5; i++) {
        GameObjStar *star = new GameObjStar();
        star->setPosition(ccp(172 + 192*i, 350));
        stars1->addObject(star);
        skyBg1->addChild(star, 3);
        
        star = new GameObjStar();
        star->setPosition(ccp(172 + 192*i, 350));
        stars2->addObject(star);
        skyBg2->addChild(star, 3);
    }
    stars1->retain();
    stars2->retain();
    
    //添加大图素
    for (int i = 0; i < 7; i++) {
        CCSprite *plant;
        CCSprite *roaddi;
        if (bg1shu[i] != -1) {
            CCSprite *road;
            switch (bg1shu[i]) {
                case 0:
                    plant = CCSprite::create("back_2.png");
                    plant->setAnchorPoint(ccp(0.5f, 0));
                    plant->setPosition(ccp(128*i + 64, 117));
                    skyBg1->addChild(plant, 1);
                    
                    road = CCSprite::create("road_2.png");
                    road->setAnchorPoint(ccp(0, 0));
                    road->setPosition(ccp(128*i, 0));
                    
                    roaddi = CCSprite::create("road_3.png");
                    roaddi->setAnchorPoint(ccp(0, 1));
                    roaddi->setPosition(ccp(128*i, 0));
                    skyBg1->addChild(roaddi, 1);
                    break;
                case 1:
                    road = CCSprite::create("road_1.png");
                    road->setAnchorPoint(ccp(0, 0));
                    road->setPosition(ccp(26 + 128*i, 0));
                    
                    roaddi = CCSprite::create("road_4.png");
                    roaddi->setAnchorPoint(ccp(0, 1));
                    roaddi->setPosition(ccp(26 + 128*i, 0));
                    skyBg1->addChild(roaddi, 1);
                    break;
                case 2:
                    plant = CCSprite::create("enemy.png");
                    plant->setAnchorPoint(ccp(0.5f, 0));
                    plant->setPosition(ccp(128*i + 64, 112));
                    skyBg1->addChild(plant, 1);
                    
                    road = CCSprite::create("road_1.png");
                    road->setFlipX(true);
                    road->setAnchorPoint(ccp(0, 0));
                    road->setPosition(ccp(128*i, 0));
                    
                    roaddi = CCSprite::create("road_4.png");
                    roaddi->setFlipX(true);
                    roaddi->setAnchorPoint(ccp(0, 1));
                    roaddi->setPosition(ccp(128*i, 0));
                    skyBg1->addChild(roaddi, 1);
                    break;
                case 3:
                    road = CCSprite::create("road_5.png");
                    road->setAnchorPoint(ccp(0, 0));
                    road->setPosition(ccp(128*i, 0));
                    break;
            }
            skyBg1->addChild(road, 1);
        }
        if (bg2shu[i] != -1) {
            CCSprite *road1;
            switch (bg2shu[i]) {
                case 0:
                    road1 = CCSprite::create("road_2.png");
                    road1->setAnchorPoint(ccp(0, 0));
                    road1->setPosition(ccp(128*i, 0));
                    
                    roaddi = CCSprite::create("road_3.png");
                    roaddi->setAnchorPoint(ccp(0, 1));
                    roaddi->setPosition(ccp(128*i, 0));
                    skyBg2->addChild(roaddi, 1);
                    break;
                case 1:
                    plant = CCSprite::create("back_3.png");
                    plant->setAnchorPoint(ccp(0.5f, 0));
                    plant->setPosition(ccp(128*i + 128, 117));
                    skyBg2->addChild(plant, 1);
                    
                    road1 = CCSprite::create("road_1.png");
                    road1->setAnchorPoint(ccp(0, 0));
                    road1->setPosition(ccp(26 + 128*i, 0));
                    
                    roaddi = CCSprite::create("road_4.png");
                    roaddi->setAnchorPoint(ccp(0, 1));
                    roaddi->setPosition(ccp(26 + 128*i, 0));
                    skyBg2->addChild(roaddi, 1);
                    break;
                case 2:
                    road1 = CCSprite::create("road_1.png");
                    road1->setFlipX(true);
                    road1->setAnchorPoint(ccp(0, 0));
                    road1->setPosition(ccp(128*i, 0));
                    
                    roaddi = CCSprite::create("road_4.png");
                    roaddi->setFlipX(true);
                    roaddi->setAnchorPoint(ccp(0, 1));
                    roaddi->setPosition(ccp(128*i, 0));
                    skyBg2->addChild(roaddi, 1);
                    break;
                case 3:
                    road1 = CCSprite::create("road_5.png");
                    road1->setAnchorPoint(ccp(0, 0));
                    road1->setPosition(ccp(128*i, 0));
                    break;
            }
            skyBg2->addChild(road1, 1);
        }
    }
    this->state = 0;
}

void GameObjMap::onExit()
{
    CCNode::onExit();
}

void GameObjMap::bg1Change()
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSprite *background = (CCSprite *)this->getChildByTag(0);
//    background->setPosition(ccp(480, 320));
    background->setPosition(ccpAdd(ccp(size.width/2, size.height/2), originPoint));
    background->runAction(CCSequence::create(CCMoveBy::create(12, ccpAdd(ccp(-960, 0), originPoint)),CCCallFunc::create(this, callfunc_selector(GameObjMap::bg1Change)),NULL));
    for (int i = 0; i < 5; i++) {
        ((GameObjStar *)stars1->objectAtIndex(i))->set_visible(true);
    }
}

void GameObjMap::bg2Change()
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSprite *background = (CCSprite *)this->getChildByTag(1);
//    background->setPosition(ccp(480, 320));
    background->setPosition(ccpAdd(ccp(size.width/2, size.height/2), originPoint));
    background->runAction(CCSequence::create(CCMoveBy::create(12, ccpAdd(ccp(-960, 0), originPoint)),CCCallFunc::create(this, callfunc_selector(GameObjMap::bg2Change)),NULL));
    for (int i = 0; i < 5; i++) {
        ((GameObjStar *)stars2->objectAtIndex(i))->set_visible(true);
    }
}
