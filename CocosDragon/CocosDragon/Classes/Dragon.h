//
//  Dragon.h
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#ifndef __CocosDragon__Dragon__
#define __CocosDragon__Dragon__

#include "cocos2d.h"
#include "GameObject.h"


class Dragon : public GameObject
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Dragon, create);
  Dragon();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  virtual bool init();
  
  virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
  virtual void completedAnimationSequenceNamed(const char *name);
  virtual void handleCollisionWith(GameObject* gameObject);

public:
  virtual void update();
  
  float getXTarget() {
    return xTarget_;
  }
  void setXTarget(float target) {
    xTarget_ = target;
  }
  virtual float getRadius(){
    return 25;
  }
  
private:
  
  float ySpeed_;
  float xTarget_;
  
};

class DragonLoader : public cocos2d::extension::CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DragonLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Dragon);
  
};

#endif /* defined(__CocosDragon__Dragon__) */
