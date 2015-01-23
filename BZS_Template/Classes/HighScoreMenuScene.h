//
//  HighScoreMenuScene.h
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#ifndef __BZS_Template__HighScoreMenuScene__
#define __BZS_Template__HighScoreMenuScene__

#include "cocos2d.h"
#include <UIWidget.h>

class HighScoreMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // Back Button callback
    void backButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HighScoreMenuScene);
};

#endif /* defined(__BZS_Template__HighScoreMenuScene__) */
