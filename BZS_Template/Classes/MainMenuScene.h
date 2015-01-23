//
//  MainMenuScene.h
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#ifndef BZS_Template_MainMenuScene_h
#define BZS_Template_MainMenuScene_h

#include "cocos2d.h"
#include <UIWidget.h>

class MainMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // Play Button callback
    void playButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    //High Score callback
    void highScoreButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    //Option Button callback
    void optionsButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    //About Us callback
    void aboutUsButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);
};



#endif
