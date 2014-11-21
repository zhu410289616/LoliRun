//
//  GameCommonUtility.h
//  LoliRun
//
//  Created by pig on 14/11/20.
//
//

#ifndef __LoliRun__GameCommonUtility__
#define __LoliRun__GameCommonUtility__

#include "cocos2d.h"

USING_NS_CC;

enum DesignFixType
{
    DesignFixTypeWidth,         //固定宽度
    DesignFixTypeHeight,        //固定高度
    DesignFixTypeUnknown
};

class GameCommonUtility
{
public:
    static void setDesignResolutionSize(CCSize designSize, DesignFixType designFixType);
    static void showSomeSize();
};

#endif /* defined(__LoliRun__GameCommonUtility__) */
