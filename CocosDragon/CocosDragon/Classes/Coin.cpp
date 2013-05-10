//
//  Coin.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "Coin.h"
#include "Dragon.h"
#include "cocos-ext.h"
#include "GameScene.h"

Coin::Coin()
: isEndCoin_(false)
{
  
}

bool Coin::init()
{
  if (GameObject::init()) {
    return true;
  }
  return false;
}
cocos2d::SEL_MenuHandler Coin::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler Coin::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool Coin::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  return false;
}

void Coin::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
}

void Coin::completedAnimationSequenceNamed(const char *name)
{
  
}

void Coin::handleCollisionWith(GameObject* gameObject)
{
  Dragon *object = dynamic_cast<Dragon*>(gameObject);
  if (object) {
    if (isEndCoin_)
    {
      // Level is complete!
      GameScene::sharedScene()->handleLevelComplete();
    }
    // Collided with the dragon, remove object and add an exposion instead
    this->setScheduledForRemove(true);
  }
}

float Coin::getRadius()
{
  return 15;
  
}
