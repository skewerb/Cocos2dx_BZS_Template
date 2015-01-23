//
//  OptionsMenuScene.h
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#ifndef __BZS_Template__OptionsMenuScene__
#define __BZS_Template__OptionsMenuScene__

#include "cocos2d.h"
#include <UIWidget.h>
#include <UISlider.h>
#include <UIText.h>

class OptionsMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //Music Slider callback
    void musicSliderMoved(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type);
    
    //Sound Slider callback
    void soundSliderMoved(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type);
    
    // Back Button callback
    void backButtonClicked(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(OptionsMenuScene);
    
private:
    cocos2d::ui::Text* musicSliderValue;
    cocos2d::ui::Text* soundSliderValue;
};


#endif /* defined(__BZS_Template__OptionsMenuScene__) */
