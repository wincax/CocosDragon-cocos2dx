//
//  Explosion.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "Explosion.h"
#include "Dragon.h"
#include "cocos-ext.h"
//#include "GameScene.h"

Explosion::Explosion()
{
  
}

bool Explosion::init()
{
  if (GameObject::init()) {
    return true;
  }
  return false;
}

cocos2d::SEL_MenuHandler Explosion::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler Explosion::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool Explosion::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  return false;
}

void Explosion::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
  CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
  if (animationManager) {
    animationManager->setDelegate(this);
  }
}

void Explosion::completedAnimationSequenceNamed(const char *name)
{
  // Remove the explosion object after the animation has finished
  this->setScheduledForRemove(true);
}
