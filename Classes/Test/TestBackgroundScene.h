//
//  TestBackgroundScene.h
//  LoliRun
//
//  Created by pig on 14/11/21.
//
//

#ifndef __LoliRun__TestBackgroundScene__
#define __LoliRun__TestBackgroundScene__

#include "cocos2d.h"

#define MAP_1_TAG       1
#define MAP_2_TAG       2

USING_NS_CC;

class TestBackgroundScene : public CCLayer
{
private:
    void update(float time);
    virtual void onExit();
    
public:
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(TestBackgroundScene);
};

#endif /* defined(__LoliRun__TestBackgroundScene__) */
