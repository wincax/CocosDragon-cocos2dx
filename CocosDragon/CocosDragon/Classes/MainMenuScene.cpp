//
//  MainMenuScene.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "MainMenuScene.h"
#include "GameScene.h"
#include "common_function.h"

MainMenuScene::MainMenuScene()
{
  
}

bool MainMenuScene::init()
{
  if (CCLayer::init()) {
    return true;
  }
  return false;
}

cocos2d::SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPlay:", MainMenuScene::pressedPlay);
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler MainMenuScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool MainMenuScene::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  return false;
}

void MainMenuScene::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
}

void MainMenuScene::pressedPlay(CCNode* sender)
{
  // Load the game scene
  map<string, CCNodeLoader*> loader_map;
  loader_map.insert(make_pair("GameScene", GameSceneLoader::loader()));
  CCScene* gameScene = (CCScene*)loadCCBFile("res/GameScene.ccbi", loader_map);
  // Go to the game scene
  if (gameScene) {
    // Then add the scene to the stack. The director will run it when it automatically when the view is displayed.
    CCDirector::sharedDirector()->replaceScene(gameScene);
  }
}
