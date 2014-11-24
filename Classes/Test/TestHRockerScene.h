//
//  TestHRockerScene.h
//  LoliRun
//
//  Created by pig on 14/11/24.
//
//

#ifndef __LoliRun__TestHRockerScene__
#define __LoliRun__TestHRockerScene__

#include "cocos2d.h"

USING_NS_CC;

class TestHRockerScene : public CCLayer
{
private:
    
public:
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(TestHRockerScene);
};

#endif /* defined(__LoliRun__TestHRockerScene__) */
