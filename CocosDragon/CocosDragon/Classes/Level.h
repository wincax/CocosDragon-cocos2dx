//
//  Level.h
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#ifndef __CocosDragon__Level__
#define __CocosDragon__Level__

#include "cocos2d.h"
#include "GameObject.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Dragon;

class Level
: public cocos2d::CCLayer
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
, public cocos2d::extension::CCBSelectorResolver
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Level, create);
  
  Level();
  ~Level();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  virtual bool init();
  // default implements are used to call script callback if exist
  virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
  virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
  virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
  virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
  
  virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
  virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
public:
  virtual void onEnter();
  virtual void onExit();
  
  void update(float delta);

private:
   Dragon* dragon_;
};

class LevelLoader : public cocos2d::extension::CCLayerLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Level);
  
};

#endif /* defined(__CocosDragon__Level__) */
