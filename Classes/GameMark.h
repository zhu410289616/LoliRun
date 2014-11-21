//
//  GameMark.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameMark__
#define __LoliRun__GameMark__

#include "cocos2d.h"

USING_NS_CC;

class GameMark : public CCNode
{
public:
    int mark;
    CCArray *bits;
    CCTexture2D *ui;
    
    GameMark();
    virtual ~GameMark();
    virtual void onEnter();
    virtual void onExit();
    void addNumber(int var);
};

#endif /* defined(__LoliRun__GameMark__) */
