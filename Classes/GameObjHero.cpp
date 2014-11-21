//
//  GameObjHero.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameObjHero.h"
#include "GameMainLayer.h"

GameObjHero::GameObjHero(void)
{
}

GameObjHero::~GameObjHero(void)
{
}

void GameObjHero::setState(short var)
{
    if (state == var)
        return;
    state = var;
    switch (state) {
        case 0:
        {
            this->stopAllActions();
            mainSprite->stopAllActions();
            CCAnimation *animation = CCAnimation::create();
            animation->addSpriteFrameWithFileName("s_1.png");
            animation->addSpriteFrameWithFileName("s_2.png");
            animation->addSpriteFrameWithFileName("s_3.png");
            animation->addSpriteFrameWithFileName("s_4.png");
            animation->addSpriteFrameWithFileName("s_5.png");
            animation->addSpriteFrameWithFileName("s_6.png");
            animation->setDelayPerUnit(0.1f);
            animation->setRestoreOriginalFrame(true);
            mainSprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
            break;
        }
        case 1:
        {
            this->stopAllActions();
            mainSprite->stopAllActions();
            mainSprite->setTexture(jump);
            this->runAction(CCSequence::create(CCJumpBy::create(1.6f, ccp(0, 0), 100, 1),CCCallFunc::create(this, callfunc_selector(GameObjHero::jumpEnd)),NULL));
            break;
        }
        case 2:
        {
            this->stopAllActions();
            mainSprite->stopAllActions();
            mainSprite->setTexture(hurt);
            this->runAction(CCSequence::create(CCBlink::create(2, 6),CCCallFunc::create(this, callfunc_selector(GameObjHero::hurtEnd)),NULL));
            ((GameMainLayer *)this->getParent())->setOver();
            break;
        }
    }
}

CCRect GameObjHero::rect()
{
    CCSize size = CCSizeMake(100, 125);
    return CCRectMake(-size.width/2, -size.height/2, size.width, size.height);
}

void GameObjHero::jumpEnd()
{
    this->setState(0);
}

void GameObjHero::hurtEnd()
{
    this->setState(0);
}

void GameObjHero::onEnter()
{
    CCNode::onEnter();
    this->setContentSize(CCSizeMake(85, 90));
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite *obj = CCSprite::create("s_jump.png");
    jump = obj->getTexture();
    obj = CCSprite::create("s_hurt.png");
    hurt = obj->getTexture();
    mainSprite = CCSprite::create("s_1.png");
    
    CCAnimation *animation = CCAnimation::create();
    animation->addSpriteFrameWithFileName("s_1.png");
    animation->addSpriteFrameWithFileName("s_2.png");
    animation->addSpriteFrameWithFileName("s_3.png");
    animation->addSpriteFrameWithFileName("s_4.png");
    animation->addSpriteFrameWithFileName("s_5.png");
    animation->addSpriteFrameWithFileName("s_6.png");
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    
    mainSprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    this->state = 0;
    this->addChild(mainSprite);
}

void GameObjHero::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCNode::onExit();
}

bool GameObjHero::containsTouchLocation(CCTouch* touch)
{
    return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool GameObjHero::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if (((GameMainLayer *)this->getParent())->isOver)
        return false;
    this->setState(1);
    return true;
}

void GameObjHero::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
}

void GameObjHero::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}

void GameObjHero::touchDelegateRetain()
{
    this->retain();
}

void GameObjHero::touchDelegateRelease()
{
    this->release();
}
