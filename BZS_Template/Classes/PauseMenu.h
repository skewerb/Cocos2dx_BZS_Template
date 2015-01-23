//
//  PauseMenu.h
//  BZS_Template
//
//  Created by Steven Yang on 1/20/15.
//
//

#ifndef __BZS_Template__PauseMenu__
#define __BZS_Template__PauseMenu__

#include "cocos2d.h"

class PauseMenu : public cocos2d::Node
{
public:
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //Show Pause Menu
    void showMenu();
    
    // Play Button callback
    void playButtonClicked(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PauseMenu);
    
private:
    cocos2d::Label *title;
};


#endif /* defined(__BZS_Template__PauseMenu__) */
