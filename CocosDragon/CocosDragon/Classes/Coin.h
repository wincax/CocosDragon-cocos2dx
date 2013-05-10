//
//  Coin.h
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#ifndef __CocosDragon__Coin__
#define __CocosDragon__Coin__

#include "cocos2d.h"
#include "GameObject.h"


class Coin : public GameObject
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Coin, create);
  Coin();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  virtual bool init();
  
  virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
  virtual void completedAnimationSequenceNamed(const char *name);
public:
  
  virtual void handleCollisionWith(GameObject* gameObject);
  virtual float getRadius();
  
private:
  
  bool isEndCoin_;

};
class CoinLoader : public cocos2d::extension::CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CoinLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Coin);
  
};

#endif /* defined(__CocosDragon__Coin__) */
