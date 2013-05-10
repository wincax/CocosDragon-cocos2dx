//
//  GameObject.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "GameObject.h"

GameObject::GameObject()
: isScheduledForRemove_(false)
, radius_(0) {
  
}

bool GameObject::init()
{
  return true;
}

cocos2d::SEL_MenuHandler GameObject::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler GameObject::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool GameObject::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  return false;
}

void GameObject::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
}

void GameObject::completedAnimationSequenceNamed(const char *name)
{
  
}

void GameObject::update()
{
  
}

void GameObject::handleCollisionWith(GameObject* gameObject)
{
  
}

float GameObject::getRadius()
{
  return radius_;
}
