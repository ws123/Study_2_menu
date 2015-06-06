//
//  MenuScene.cpp
//  Study_2_menu
//
//  Created by 张 兵龙 on 15/6/6.
//
//

#include "MenuScene.h"
#include "cocos2d.h"
Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}
bool MenuScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    size = Director::getInstance()->getVisibleSize();
    auto bg = Sprite::create("bg.jpg");
    float sx = size.width/bg->getContentSize().width;
    float sy = size.height/bg->getContentSize().height;
    bg->setScale(sx,sy);
    bg->setPosition(size.width/2,size.height/2);
    this->addChild(bg);
    testMenu_label();
    return true;
}

void MenuScene::testMenu1()
{
    //为菜单选项设置字体名称
    MenuItemFont::setFontName("Arial");
    //创建一个菜单选项，第一个参数是选项名字，第二个参数是点击了以后，回调的方法
    //这里，一共创建了三个菜单选项，start gamen,setting,level
    MenuItemFont *item1 = MenuItemFont::create("start game",CC_CALLBACK_1(MenuScene::Menu1Callback_1, this));
    MenuItemFont *item2 = MenuItemFont::create("setting", CC_CALLBACK_1(MenuScene::Menu1Callback_2, this));
    MenuItemFont *item3 = MenuItemFont::create("level", CC_CALLBACK_1(MenuScene::menu1Callback_3, this));
    //创建一个菜单，它的参数就是各个菜单选项，最后，一定要跟一个NULL，表示结束了
    Menu *menu = Menu::create(item1,item2,item3, NULL);
    //设置菜单的位置
    menu->setPosition(size.width/2,size.height/2);
    //设置菜单的对齐方式，这里的对齐方式是垂直对齐
    menu->alignItemsVertically();
    //把这个菜单添加到当前场景
    this->addChild(menu);
    
}
void MenuScene::testMenu_label()
{
    //先创建一个标签,这里一共创建三个
    auto label_1 = LabelBMFont::create("start game", "bitmapFontTest5.fnt");
    //根据标签创建一个菜单项,第一个参数就是一个标签，第二个参数是点击后要回调的方法
    auto item_1 = MenuItemLabel::create(label_1,CC_CALLBACK_1(MenuScene::Menu1Callback_1, this));
    auto label_2 = LabelBMFont::create("setting", "bitmapFontTest5.fnt");
    auto item_2 = MenuItemLabel::create(label_2,CC_CALLBACK_1(MenuScene::Menu1Callback_2, this));
    auto label_3 = LabelBMFont::create("level", "bitmapFontTest5.fnt");
    auto item_3 = MenuItemLabel::create(label_3,CC_CALLBACK_1(MenuScene::menu1Callback_3, this));
    //创建一个菜单，把上面的三个菜单项包含进去
    Menu *menu = Menu::create(item_1,item_2,item_3, NULL);
    //设置菜单的位置
    menu->setPosition(size.width/2,size.height/2);
    //设置菜单的对齐方式，这里的对齐方式是水平对齐
    menu->alignItemsHorizontally();
    //把这个菜单添加到当前场景
    this->addChild(menu);
}

//回调方法1，点击了start game后回调
void MenuScene::Menu1Callback_1(cocos2d::Ref *sender)
{
    //log输出
    CCLOG("点击了开始按钮");
}
//回调方法2，点击了setting后回调
void MenuScene::Menu1Callback_2(cocos2d::Ref *sender)
{
    CCLOG("设置选项");
}
//回调方法3，点击了level后回调
void MenuScene::menu1Callback_3(cocos2d::Ref *sender)
{
    CCLOG("设置级别");
}