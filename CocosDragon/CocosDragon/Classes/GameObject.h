//
//  GameObject.h
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#ifndef __CocosDragon__GameObject__
#define __CocosDragon__GameObject__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class GameObject : public cocos2d::CCNode
, public cocos2d::extension::CCBAnimationManagerDelegate
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
, public cocos2d::extension::CCBSelectorResolver
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameObject, create);

  GameObject();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  virtual bool init();
  
  virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
  virtual void completedAnimationSequenceNamed(const char *name);
public:
  
  virtual void update();
  virtual void handleCollisionWith(GameObject* gameObject);
  virtual float getRadius();
  
  bool getScheduledForRemove() {
    return isScheduledForRemove_;
  }
  void setScheduledForRemove(bool value) {
    isScheduledForRemove_ = value;
  }
  
private:
  
  bool isScheduledForRemove_;
  float radius_;
  
};

class GameObjectLoader : public cocos2d::extension::CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameObjectLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameObject);
  
};

#endif /* defined(__CocosDragon__GameObject__) */
