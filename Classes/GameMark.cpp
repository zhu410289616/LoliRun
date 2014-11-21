//
//  GameMark.cpp
//  LoliRun
//
//  Created by pig on 14/11/19.
//
//

#include "GameMark.h"

GameMark::GameMark()
{
}

GameMark::~GameMark()
{
}

void GameMark::onEnter()
{
    CCNode::onEnter();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    this->setContentSize(size);
    
    CCSprite *title = CCSprite::create("score.png");
    title->setPosition(ccp(size.width/2 + 120,size.height - 15));
    title->setScale(0.5f);
    this->addChild(title);
    
    bits = CCArray::createWithCapacity(5);
    for (int i = 0; i < 5; i++) {
        CCSprite *shu = CCSprite::create("shu.png");
        ui = shu->getTexture();
        shu->setScale(0.5f);
        shu->setTextureRect(CCRectMake(234, 0, 26, 31));
        shu->setPosition(ccp(size.width - 15 - i*15, size.height - 15));
        bits->addObject(shu);
        this->addChild(shu);
    }
    bits->retain();
    
    this->mark = 0;
}

void GameMark::onExit()
{
    CCNode::onExit();
}

void GameMark::addNumber(int var)
{
    //按位设置数字
    mark += var;
    int temp = mark % 10;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = (mark % 100) / 10;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));
        
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = (mark % 1000) / 100;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));
        
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = (mark % 10000) / 1000;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));
        
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = mark / 10000;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));
        
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake(234,0,26,31));
    }
}
