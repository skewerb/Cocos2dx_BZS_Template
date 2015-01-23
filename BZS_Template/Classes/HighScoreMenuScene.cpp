//
//  HighScoreMenuMenuScene.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#include "HighScoreMenuScene.h"
#include <UIButton.h>

using namespace cocos2d::ui;

USING_NS_CC;

Scene* HighScoreMenuScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = HighScoreMenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool HighScoreMenuScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Title
    auto title = Label::createWithTTF("Highest Score", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    
    this->addChild(title, -1);
    
    //Highest Score
    auto score = Label::createWithTTF("0", "fonts/Dimbo Regular.ttf",visibleSize.height * 0.15 + origin.y);
    score->setString(String::createWithFormat("%d", UserDefault::getInstance()->getIntegerForKey("Best Score"))->getCString());
    score->setColor(Color3B::YELLOW);
    score->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.55 + origin.y));
    
    this->addChild(score, -1);
    
    //Back button
    auto backButton = Button::create("ui/return.png");
    backButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.25 + origin.y));
    backButton->setTouchEnabled(true);
    backButton->addTouchEventListener(CC_CALLBACK_2(HighScoreMenuScene::backButtonClicked, this));
    
    this->addChild(backButton, 1);
    
    return true;
}

void HighScoreMenuScene::backButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    Director::getInstance()->popScene();
}