//
//  GameObjMap.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameObjMap__
#define __LoliRun__GameObjMap__

#include "cocos2d.h"

USING_NS_CC;

class GameObjMap : public CCNode
{
public:
    short state;
    CCArray *stars1;
    CCArray *stars2;
    
    GameObjMap();
    virtual ~GameObjMap();
    virtual void onEnter();
    virtual void onExit();
    void bg1Change();
    void bg2Change();
};

#endif /* defined(__LoliRun__GameObjMap__) */
