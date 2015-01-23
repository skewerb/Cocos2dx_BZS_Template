//
//  PauseMenu.cpp
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#include "PauseMenu.h"

using namespace cocos2d;

bool PauseMenu::init()
{
    
    //Get Screen Size & Origin
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Title
    this->title = Label::createWithTTF("Paused", "fonts/Dimbo Regular.ttf",visibleSize.width * 0.08 + origin.x);
    this->title->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    this->title->setVisible(false);

    this->addChild(this->title, -1);
    
    return true;

}

void PauseMenu::showMenu()
{
    this->title->setVisible(true);
}