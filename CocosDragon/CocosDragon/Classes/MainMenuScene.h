//
//  MainMenuScene.h
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#ifndef __CocosDragon__MainMenuScene__
#define __CocosDragon__MainMenuScene__

#include "cocos2d.h"
#include "GameObject.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MainMenuScene
: public cocos2d::CCLayer
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
, public cocos2d::extension::CCBSelectorResolver
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainMenuScene, create);

  MainMenuScene();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  virtual bool init();
  
  virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
 
public:
  
  void pressedPlay(CCNode* sender);
};

class MainMenuSceneLoader : public cocos2d::extension::CCLayerLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainMenuSceneLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainMenuScene);
  
};

#endif /* defined(__CocosDragon__MainMenuScene__) */
