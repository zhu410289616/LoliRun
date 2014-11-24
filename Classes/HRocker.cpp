//
//  HRocker.cpp
//  LoliRun
//
//  Created by pig on 14/11/23.
//
//

#include "HRocker.h"

void HRocker::updatePos(cocos2d::CCTime dt)
{
    jsSprite->setPosition(ccpAdd(jsSprite->getPosition(), ccpMult(ccpSub(currentPoint, jsSprite->getPosition()), 0.5)));
}

void HRocker::Active()
{
    if (!active) {
        active = true;
        schedule(schedule_selector(HRocker::updatePos));
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);//添加触摸委托
    } else {
        
    }
}

void HRocker::Inactive()
{
    if (active) {
        active = false;
        this->unschedule(schedule_selector(HRocker::updatePos));
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    }
}

CCPoint HRocker::getDirection()
{
    return ccpNormalize(ccpSub(centerPoint, currentPoint));
}

float HRocker::getVelocity()
{
    return ccpDistance(centerPoint, currentPoint);
}

HRocker *HRocker::HRockerWithCenter(cocos2d::CCPoint aPoint, float aRadius, cocos2d::CCSprite *aJsSprite, cocos2d::CCSprite *aJsBg, bool aIsFollowRole)
{
    HRocker *jstick = HRocker::create();
    jstick->initWithCenter(aPoint, aRadius, aJsSprite, aJsBg, aIsFollowRole);
    return jstick;
}

bool HRocker::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (!active) {
        return false;
    }
    this->setVisible(true);
    CCPoint touchPoint = convertTouchToNodeSpace(pTouch);
    if (!isFollowRole) {
        if (ccpDistance(touchPoint, centerPoint) > radius) {
            return false;
        }
    }
    currentPoint = touchPoint;
    if (isFollowRole) {
        centerPoint = currentPoint;
        jsSprite->setPosition(currentPoint);
        this->getChildByTag(88)->setPosition(currentPoint);
    }
    return true;
}

void HRocker::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchPoint = convertTouchToNodeSpace(pTouch);
    if (ccpDistance(touchPoint, centerPoint) > radius) {
        currentPoint = ccpAdd(centerPoint, ccpMult(ccpNormalize(ccpSub(touchPoint, centerPoint)), radius));
    } else {
        currentPoint = touchPoint;
    }
}

void HRocker::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    currentPoint = centerPoint;
    if (isFollowRole) {
        this->setVisible(false);
    }
}

HRocker *HRocker::initWithCenter(cocos2d::CCPoint aPoint, float aRadius, cocos2d::CCSprite *aJsSprite, cocos2d::CCSprite *aJsBg, bool aIsFollowRole)
{
    isFollowRole = aIsFollowRole;
    active = false;
    radius = aRadius;
    if (!aIsFollowRole) {
        centerPoint = aPoint;
    } else {
        centerPoint = ccp(0, 0);
    }
    
    currentPoint = centerPoint;
    jsSprite = aJsSprite;
    jsSprite->setPosition(centerPoint);
    aJsBg->setPosition(centerPoint);
    aJsBg->setTag(88);
    this->addChild(aJsBg);
    this->addChild(jsSprite);
    if (isFollowRole) {
        this->setVisible(false);
    }
    this->Active();//激活摇杆
    return this;
}
