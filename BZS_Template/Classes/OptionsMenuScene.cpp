//
//  OptionsMenuScene.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#include "OptionsMenuScene.h"
#include <UIButton.h>

using namespace cocos2d::ui;

USING_NS_CC;

Scene* OptionsMenuScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = OptionsMenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool OptionsMenuScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Title
    auto title = Label::createWithTTF("Options", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    
    title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    
    this->addChild(title, -1);
    
    //Music Slider Node
    auto musicSliderNode = Node::create();
    musicSliderNode->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.55 + origin.y));
    this->addChild(musicSliderNode, 1);
    
    //Music Slider
    auto musicSlider = Slider::create();
    musicSlider->loadBarTexture("ui/slider.png");
    musicSlider->loadSlidBallTextures("ui/slider_ball_grey.png", "ui/slider_ball_white.png", "");
    musicSlider->setPercent(UserDefault::getInstance()->getIntegerForKey("Music Volume"));
    musicSlider->setScale(2.0);
    musicSlider->setPosition(Vec2(0,0));
    musicSlider->addEventListener(CC_CALLBACK_2(OptionsMenuScene::musicSliderMoved, this));
    musicSliderNode->addChild(musicSlider, 1);
    
    //Music Slider Text
    auto musicSliderText = Label::createWithTTF("Music", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.03 + origin.x);
    musicSliderText->setPosition(Vec2(-1*(musicSlider->getContentSize().width + visibleSize.width * 0.1 + origin.x),0));
    musicSliderNode->addChild(musicSliderText, 1);
    
    //Music Slider Values
    this->musicSliderValue = Text::create("0", "0", (visibleSize.width * 0.03 + origin.x));
    this->musicSliderValue->setFontName("fonts/Dimbo Regular.ttf");
    this->musicSliderValue->setString(String::createWithFormat("%d", (UserDefault::getInstance()->getIntegerForKey("Music Volume")))->getCString());
    this->musicSliderValue->setPosition(Vec2((musicSlider->getContentSize().width + visibleSize.width * 0.1 + origin.x), 0));
    
    musicSliderNode->addChild(this->musicSliderValue, 1);
    
    //Sound Slider Node
    auto soundSliderNode = Node::create();
    soundSliderNode->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.4 + origin.y));
    this->addChild(soundSliderNode);
    
    //Sound Slider
    auto soundSlider = Slider::create();
    soundSlider->loadBarTexture("ui/slider.png");
    soundSlider->loadSlidBallTextures("ui/slider_ball_grey.png", "ui/slider_ball_white.png", "");
    soundSlider->setPercent(UserDefault::getInstance()->getIntegerForKey("Sound Volume"));
    soundSlider->setPosition(Vec2(0,0));
    soundSlider->addEventListener(CC_CALLBACK_2(OptionsMenuScene::soundSliderMoved, this));
    soundSlider->setScale(2.0);
    soundSliderNode->addChild(soundSlider, 1);
    
    //Sound Slider Text
    auto soundSliderText = Label::createWithTTF("Sound", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.03 + origin.x);
    soundSliderText->setPosition(Vec2(-1*(soundSlider->getContentSize().width + visibleSize.width * 0.1 + origin.x),0));
    soundSliderNode->addChild(soundSliderText, 1);
    
    //Sound Slider Values
    this->soundSliderValue = Text::create("0", "0", (visibleSize.width * 0.03 + origin.x));
    this->soundSliderValue->setFontName("fonts/Dimbo Regular.ttf");
    this->soundSliderValue->setString(String::createWithFormat("%d", (UserDefault::getInstance()->getIntegerForKey("Sound Volume")))->getCString());
    this->soundSliderValue->setPosition(Vec2((soundSlider->getContentSize().width + visibleSize.width * 0.1 + origin.x), 0));
    
    soundSliderNode->addChild(this->soundSliderValue, 1);

    //Back button
    auto backButton = Button::create("ui/return.png");
    backButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.25 + origin.y));
    backButton->setTouchEnabled(true);
    backButton->addTouchEventListener(CC_CALLBACK_2(OptionsMenuScene::backButtonClicked, this));
    
    this->addChild(backButton, 1);
    
    return true;
}

void OptionsMenuScene::musicSliderMoved(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type)
{
    if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
        Slider* slider = dynamic_cast<Slider*>(pSender);
        int percent = slider->getPercent();
        this->musicSliderValue->setString(String::createWithFormat("%d", percent)->getCString());
        UserDefault::getInstance()->setIntegerForKey("Music Volume", percent);
    }
}

void OptionsMenuScene::soundSliderMoved(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type)
{
    if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
        Slider* slider = dynamic_cast<Slider*>(pSender);
        int percent = slider->getPercent();
                this->soundSliderValue->setString(String::createWithFormat("%d", percent)->getCString());
        UserDefault::getInstance()->setIntegerForKey("Sound Volume", percent);
    }
}

void OptionsMenuScene::backButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    Director::getInstance()->popScene();
}
