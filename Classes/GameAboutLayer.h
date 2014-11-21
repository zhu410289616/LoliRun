//
//  GameAboutLayer.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameAboutLayer__
#define __LoliRun__GameAboutLayer__

#include "cocos2d.h"

USING_NS_CC;

class GameAboutLayer : public CCLayer
{
public:
    CREATE_FUNC(GameAboutLayer);
    static CCScene* scene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    void menuBackCallback(CCObject *pSender);
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
};

#endif /* defined(__LoliRun__GameAboutLayer__) */
