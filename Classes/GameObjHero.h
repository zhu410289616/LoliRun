//
//  GameObjHero.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameObjHero__
#define __LoliRun__GameObjHero__

#include "cocos2d.h"

USING_NS_CC;

class GameObjHero : public CCNode, public CCTargetedTouchDelegate
{
public:
    CCPoint offset;
    short   state; //0:正常 1:跳跃 2:受伤
    bool    isControl;
    CCSprite    *mainSprite;
    CCTexture2D *jump;
    CCTexture2D *hurt;
    
    GameObjHero(void);
    virtual ~GameObjHero(void);
    void setState(short var);
    CCRect rect();
    void jumpEnd();
    void hurtEnd();
    virtual void onEnter();
    virtual void onExit();
    bool containsTouchLocation(CCTouch* touch);
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    virtual void touchDelegateRetain();
    virtual void touchDelegateRelease();
};

#endif /* defined(__LoliRun__GameObjHero__) */
