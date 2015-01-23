//
//  GameplayScene.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#include "GameplayScene.h"
#include "GameOverScene.h"
#include <UIButton.h>

USING_NS_CC;

using namespace cocos2d::ui;

Scene* GameplayScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = GameplayScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameplayScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Gameplay Layer
    this->gameLayer = Layer::create();
    this->addChild(gameLayer, 0);
    
    /*
    //Pause setup
    this->pause = PauseMenu::create();
    this->addChild(pause, 1);
     */
    
    //Title
    auto title = Label::createWithTTF("Gameplay Scene", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    
    this->gameLayer->addChild(title, -1);
    
    //Win Game
    auto winButton = Button::create("ui/button_normal.png", "ui/button_highlighted.png");
    winButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.5 + origin.y));
    winButton->setTitleText("Win");
    winButton->setTitleFontName("fonts/Dimbo Regular.ttf");
    winButton->setTitleFontSize(winButton->getContentSize().height/2);
    winButton->setTitleColor(Color3B::BLACK);
    winButton->setTouchEnabled(true);
    winButton->addTouchEventListener(CC_CALLBACK_2(GameplayScene::winButtonClicked, this));
    
    this->gameLayer->addChild(winButton, 1);
    
    /*
    //Pause Button
    auto pauseButton = Button::create("ui/pause.png");
    pauseButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.25 + origin.y));
    pauseButton->setTouchEnabled(true);
    pauseButton->addTouchEventListener(CC_CALLBACK_2(GameplayScene::pauseButtonClicked, this));
    
    this->addChild(pauseButton, 1);
     */
    
    return true;
}

void GameplayScene::winButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = GameOverScene::create();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(scene);
}

void GameplayScene::pauseButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    
}