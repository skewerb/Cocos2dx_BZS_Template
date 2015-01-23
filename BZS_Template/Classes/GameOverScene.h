//
//  GameOverScene.h
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#ifndef __BZS_Template__GameOverScene__
#define __BZS_Template__GameOverScene__

#include "cocos2d.h"
#include <UIWidget.h>

class GameOverScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // Main Menu Button callback
    void mainMenuClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    // Replay callback
    void replayClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);
};


#endif /* defined(__BZS_Template__GameOverScene__) */
