//
//  Bomb.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "Bomb.h"
#include "Dragon.h"
#include "Explosion.h"
#include "cocos-ext.h"
#include "common_function.h"

Bomb::Bomb()
{
  
}

bool Bomb::init()
{
  if (GameObject::init()) {
    return true;
  }
  return false;
}
cocos2d::SEL_MenuHandler Bomb::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler Bomb::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool Bomb::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  return false;
}

void Bomb::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
}

void Bomb::completedAnimationSequenceNamed(const char *name)
{
  
}

void Bomb::handleCollisionWith(GameObject* gameObject)
{
  Dragon *object = dynamic_cast<Dragon*>(gameObject);
  if (object) {
    // Collided with the dragon, remove object and add an exposion instead
    this->setScheduledForRemove(true);
    CCNode* explosion = NULL;
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair("Explosion", ExplosionLoader::loader()));
    explosion = loadCCBFile("res/Explosion.ccbi", loader_map);
    if (explosion) {
      explosion->setPosition(this->getPosition());
      this->getParent()->addChild(explosion);
    }
  }
}

float Bomb::getRadius()
{
  return 15;
  
}

