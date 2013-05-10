//
//  Explosion.h
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#ifndef __CocosDragon__Explosion__
#define __CocosDragon__Explosion__

#include "cocos2d.h"
#include "GameObject.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Explosion
: public GameObject
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Explosion, create);
 
  Explosion();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  virtual bool init();
  
  virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
  virtual void completedAnimationSequenceNamed(const char *name);
public:
  

};
class ExplosionLoader : public cocos2d::extension::CCNodeLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ExplosionLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Explosion);
  
};

#endif /* defined(__CocosDragon__Explosion__) */
