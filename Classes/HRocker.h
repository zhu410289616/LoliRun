//
//  HRocker.h
//  LoliRun
//
//  Created by pig on 14/11/23.
//
//

#ifndef __LoliRun__HRocker__
#define __LoliRun__HRocker__

#include "cocos2d.h"

USING_NS_CC;

/**
 *  使用方式：
 *  1. 根据角度或者摇杆与背景圆心的距离
 
 void GameLayer::updateRotation()
 {
 CCPoint direction=_hud->getRRocker()->getDirection();
 CCLog("%d",CC_RADIANS_TO_DEGREES(atan2(direction.y, - direction.x)));
 _hero->setRotation(CC_RADIANS_TO_DEGREES(atan2(direction.y, - direction.x)));
 }
 
 *  2. 判断方向
 
 CCPoint direct=myCircle->getDirection();
 CCPoint right=CCPoint(1,0);
 CCPoint left=CCPoint(-1,0);
 if(ccpAngle(direct,left)<0.707 &&myCircle->currentPoint.x>myCircle->centerPoint.x)
 {
 CCLog("left");
 }
 if(ccpAngle(direct,right)<0.707&&myCircle->currentPoint.x<myCircle->centerPoint.x)
 {
 CCLog("right");
 }
 
 */
class HRocker : public CCLayer
{
private:
    HRocker *initWithCenter(CCPoint aPoint, float aRadius, CCSprite *aJsSprite, CCSprite *aJsBg, bool aIsFollowRole);
    CCPoint centerPoint;//摇杆中心
    CCPoint currentPoint;//摇杆当前位置
    bool active;//是否激活摇杆
    float radius;//摇杆半径
    CCSprite *jsSprite;
    bool isFollowRole;//是否跟随用户点击
    CCPoint getDirection();
    float getVelocity();
    void updatePos(CCTime dt);
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    CREATE_FUNC(HRocker);
    
public:
    //aPoint是摇杆中心，aRadius是摇杆半径，aJsSprite是摇杆控制点，aJsBg是摇杆背景
    static HRocker *HRockerWithCenter(CCPoint aPoint, float aRadius, CCSprite *aJsSprite, CCSprite *aJsBg, bool aIsFollowRole);
    //启动摇杆
    void Active();
    //解除摇杆
    void Inactive();
};

#endif /* defined(__LoliRun__HRocker__) */
