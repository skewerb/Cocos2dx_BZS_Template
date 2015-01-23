//
//  MainMenuScene.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "HighScoreMenuScene.h"
#include "OptionsMenuScene.h"
#include "AboutUsScene.h"
#include <UIButton.h>

using namespace cocos2d::ui;

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MainMenuScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Create Menu
    auto menu = Menu::create(NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //Title
    auto title = Label::createWithTTF("BZS Template", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    
    title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    
    this->addChild(title, -1);
    
    //Play Button
    auto playButton = Button::create("ui/button_normal.png", "ui/button_highlighted.png");
    playButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.5 + origin.y));
    playButton->setTitleText("Play");
    playButton->setTitleFontName("fonts/Dimbo Regular.ttf");
    playButton->setTitleFontSize(playButton->getContentSize().height/2);
    playButton->setTitleColor(Color3B::BLACK);
    playButton->setTouchEnabled(true);
    playButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::playButtonClicked, this));
    
    this->addChild(playButton, 1);
    
    //High Score Button
    auto highScoreButton = Button::create("ui/button_normal.png", "ui/button_highlighted.png");
    highScoreButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.4+ origin.y));
    highScoreButton->setTitleText("High Score");
    highScoreButton->setTitleFontName("fonts/Dimbo Regular.ttf");
    highScoreButton->setTitleFontSize(highScoreButton->getContentSize().height/2);
    highScoreButton->setTitleColor(Color3B::BLACK);
    highScoreButton->setTouchEnabled(true);
    highScoreButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::highScoreButtonClicked, this));
    
    this->addChild(highScoreButton, 1);
    
    //Options Button
    auto optionsButton = Button::create("ui/button_normal.png", "ui/button_highlighted.png");
    optionsButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.3+ origin.y));
    optionsButton->setTitleText("Options");
    optionsButton->setTitleFontName("fonts/Dimbo Regular.ttf");
    optionsButton->setTitleFontSize(optionsButton->getContentSize().height/2);
    optionsButton->setTitleColor(Color3B::BLACK);
    optionsButton->setTouchEnabled(true);
    optionsButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::optionsButtonClicked, this));
    
    this->addChild(optionsButton, 1);
    
    //Options Button
    auto aboutButton = Button::create("ui/information.png");
    aboutButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.1+ origin.y));
    aboutButton->setTouchEnabled(true);
    aboutButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::aboutUsButtonClicked, this));
    
    this->addChild(aboutButton, 1);
    
    
    return true;
}

void MainMenuScene::playButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = GameplayScene::create();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(scene);
}


void MainMenuScene::highScoreButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = HighScoreMenuScene::create();
    scene->addChild(layer);
    Director::getInstance()->pushScene(scene);
}

void MainMenuScene::optionsButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = OptionsMenuScene::create();
    scene->addChild(layer);
    Director::getInstance()->pushScene(scene);
}

void MainMenuScene::aboutUsButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto scene = Scene::create();
    auto layer = AboutUsScene::create();
    scene->addChild(layer);
    Director::getInstance()->pushScene(scene);
}
