//
//  GameCommonUtility.cpp
//  LoliRun
//
//  Created by pig on 14/11/20.
//
//

#include "GameCommonUtility.h"

void GameCommonUtility::setDesignResolutionSize(cocos2d::CCSize designSize, DesignFixType designFixType)
{
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    CCSize frameSize = pEGLView->getFrameSize();
    CCSize lsSize = CCSizeMake(960, 640);
    
    //set design size
    if (designSize.width > 0 && designSize.height > 0) {
        lsSize = designSize;
    }
    float scaleX = frameSize.width / lsSize.width;
    float scaleY = frameSize.height / lsSize.height;
    float scale = MAX(scaleX, scaleY);
    
    switch (designFixType) {
        case DesignFixTypeWidth:
        {
            //固定宽度
            if (scaleX > scaleY) {
                scale = scaleY / (frameSize.height / lsSize.height);
            } else {
                scale = scaleY / (frameSize.width / lsSize.width);
            }
        }
            break;
        case DesignFixTypeHeight:
        {
            //固定高度
            if (scaleX > scaleY) {
                scale = scaleX / (frameSize.height / lsSize.height);
            } else {
                scale = scaleX / (frameSize.width / lsSize.width);
            }
        }
            break;
            
        default:
            break;
    }//switch
    
    CCLog("x: %f, y: %f, scale: %f", scaleX, scaleY, scale);
    pEGLView->setDesignResolutionSize(lsSize.width * scale, lsSize.height * scale, kResolutionNoBorder);
    //show size
    showSomeSize();
}

void GameCommonUtility::showSomeSize()
{
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    CCSize frameSize = pEGLView->getFrameSize();
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCLog("FrameSize: width[%f], height[%f]", frameSize.width, frameSize.height);
    CCLog("WinSize: width[%f], height[%f]", winSize.width, winSize.height);
    CCLog("VisibleSize: width[%f], height[%f]", visibleSize.width, visibleSize.height);
    CCLog("VisibleOrigin: x[%f], y[%f]", visibleOrigin.x, visibleOrigin.y);
    
    CCLog("XScale: %f, YScale: %f", CCEGLView::sharedOpenGLView()->getScaleX(), CCEGLView::sharedOpenGLView()->getScaleY());
}
