//
//  MenuScene.h
//  Study_2_menu
//
//  Created by carlos on 15/6/6.
//
//

#ifndef Study_2_menu_MenuScene_h
#define Study_2_menu_MenuScene_h
#include "cocos2d.h"
USING_NS_CC;
class MenuScene:public cocos2d::Layer
{
private:
    Size size;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void testMenu1();
    void testMenu_label();
    
    void Menu1Callback_1(Ref* sender);
    void Menu1Callback_2(Ref* sender);
    void menu1Callback_3(Ref* sender);
    
    CREATE_FUNC(MenuScene);
};

#endif
