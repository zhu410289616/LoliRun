//
//  GameMenuLayer.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameMenuLayer__
#define __LoliRun__GameMenuLayer__

#include "cocos2d.h"

USING_NS_CC;

class GameMenuLayer : public CCLayer
{
private:
    
public:
    bool isSound;
    CCMenuItemImage *soundItem;
    
    CREATE_FUNC(GameMenuLayer);
    static CCScene *scene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    void menuEnter();
    void menuNewGameCallback(CCObject *pSender);
    void menuContinueCallback(CCObject *pSender);
    void menuAboutCallback(CCObject *pSender);
    void menuSoundCallback(CCObject *pSender);
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
};

#endif /* defined(__LoliRun__GameMenuLayer__) */
