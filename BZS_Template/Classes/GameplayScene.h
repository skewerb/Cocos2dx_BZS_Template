//
//  GameplayScene.h
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#ifndef __BZS_Template__GameplayScene__
#define __BZS_Template__GameplayScene__

#include "cocos2d.h"
//#include "PauseMenu.h"
#include <UIWidget.h>

class GameplayScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // Win Button callback
    void winButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    //Pause Button callback
    void pauseButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameplayScene);
private:
    //PauseMenu *pause;
    Layer *gameLayer;
};


#endif /* defined(__BZS_Template__GameplayScene__) */
