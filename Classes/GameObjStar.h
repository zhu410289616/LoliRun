//
//  GameObjStar.h
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#ifndef __LoliRun__GameObjStar__
#define __LoliRun__GameObjStar__

#include "cocos2d.h"

USING_NS_CC;

class GameObjStar : public CCNode
{
public:
    short   state;
    bool    _visible;
    
    GameObjStar();
    virtual ~GameObjStar();
    virtual void onEnter();
    virtual void onExit();
    void set_visible(bool var);
    bool get_visible();
};

#endif /* defined(__LoliRun__GameObjStar__) */
