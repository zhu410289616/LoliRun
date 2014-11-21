//
//  GameMainLayer.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameMainLayer__
#define __LoliRun__GameMainLayer__

#include "cocos2d.h"

USING_NS_CC;

class GameObjHero;
class GameObjMap;
class GameMark;

class GameMainLayer : public CCLayer
{
private:
    
public:
    bool    isOver;
    GameObjHero *hero;
    GameObjMap  *map;
    GameMark    *gameMark;
    CCSprite    *gameOver;
    
    CREATE_FUNC(GameMainLayer);
    virtual bool init();
    static CCScene *scene();
    virtual void onEnter();
    virtual void onExit();
    void menuBackCallback(CCObject *pSender);
    void update(float time);
    void isHeroDrop();
    void setOver();
    bool isCollision(CCPoint pos1, CCPoint pos2, int w1, int h1, int w2, int h2);
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
};

#endif /* defined(__LoliRun__GameMainLayer__) */
