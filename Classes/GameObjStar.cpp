//
//  GameObjStar.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameObjStar.h"

GameObjStar::GameObjStar()
{
}

GameObjStar::~GameObjStar()
{
}

void GameObjStar::onEnter()
{
    CCNode::onEnter();
    
    //初始化星星
    this->setContentSize(CCSizeMake(36.5, 35.5));
    CCSprite *star = CCSprite::create("star.png");
    star->setScale(0.5f);
    this->_visible = true;
    this->addChild(star, 1);
}

void GameObjStar::onExit()
{
    CCNode::onExit();
}

void GameObjStar::set_visible(bool var)
{
    this->_visible = var;
    this->setVisible(var);
}

bool GameObjStar::get_visible()
{
    return _visible;
}
