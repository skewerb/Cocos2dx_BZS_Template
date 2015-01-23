//
//  AboutUsScene.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/21/15.
//
//

#include "AboutUsScene.h"
#include <UIButton.h>

using namespace cocos2d::ui;

USING_NS_CC;

Scene* AboutUsScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = AboutUsScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool AboutUsScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Title
    auto title = Label::createWithTTF("About Us", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    
    this->addChild(title, -1);
    
    //Developer Node
    auto devNode = Node::create();
    devNode->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.55 + origin.y));
    this->addChild(devNode, 1);
    
    //Developer Title
    auto devTitle= Label::createWithTTF("Developer", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.03 + origin.x);
    devTitle->setPosition(Vec2(0,0));
    
    devNode->addChild(devTitle, 1);
    
    //Developer Name
    auto devName= Label::createWithTTF("Blast Zone Studios", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.03 + origin.x);
    devName->setColor(Color3B::YELLOW);
    devName->setPosition(Vec2(0,(-1*(visibleSize.width * 0.05 + origin.x))));
    
    devNode->addChild(devName, 1);
    
    //Back button
    auto backButton = Button::create("ui/return.png");
    backButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.25 + origin.y));
    backButton->setTouchEnabled(true);
    backButton->addTouchEventListener(CC_CALLBACK_2(AboutUsScene::backButtonClicked, this));
    
    this->addChild(backButton, 1);
    
    return true;
}

void AboutUsScene::backButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    Director::getInstance()->popScene();
}