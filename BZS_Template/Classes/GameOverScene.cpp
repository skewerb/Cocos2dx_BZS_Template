//
//  GameOverScene.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "GameplayScene.h"
#include <UIButton.h>

using namespace cocos2d::ui;

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = GameOverScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameOverScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Title
    auto title = Label::createWithTTF("GameOver Scene", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    
    title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    
    this->addChild(title, -1);
    
    //Replay Button
    auto replayButton = Button::create("ui/button_normal.png", "ui/button_highlighted.png");
    replayButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.5 + origin.y));
    replayButton->setTitleText("Play Again");
    replayButton->setTitleFontName("fonts/Dimbo Regular.ttf");
    replayButton->setTitleFontSize(replayButton->getContentSize().height/2);
    replayButton->setTitleColor(Color3B::BLACK);
    replayButton->setTouchEnabled(true);
    replayButton->addTouchEventListener(CC_CALLBACK_2(GameOverScene::replayClicked, this));
    
    this->addChild(replayButton, 1);
    
    //Main Menu Button
    auto mainMenuButton = Button::create("ui/button_normal.png", "ui/button_highlighted.png");
    mainMenuButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.4+ origin.y));
    mainMenuButton->setTitleText("Main Menu");
    mainMenuButton->setTitleFontName("fonts/Dimbo Regular.ttf");
    mainMenuButton->setTitleFontSize(mainMenuButton->getContentSize().height/2);
    mainMenuButton->setTitleColor(Color3B::BLACK);
    mainMenuButton->setTouchEnabled(true);
    mainMenuButton->addTouchEventListener(CC_CALLBACK_2(GameOverScene::mainMenuClicked, this));
    
    this->addChild(mainMenuButton, 1);
    
    return true;
}

void GameOverScene::mainMenuClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(scene);
}

void GameOverScene::replayClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = GameplayScene::create();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(scene);
}

