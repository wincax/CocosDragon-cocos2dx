//
//  Level.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "Level.h"
#include "Dragon.h"

#define kCJScrollFilterFactor 0.1
#define kCJDragonTargetOffset 80

Level::Level()
: dragon_(NULL)
{
  
}

Level::~Level()
{
  CC_SAFE_RELEASE(dragon_);
}

bool Level::init()
{
  if (CCLayer::init()) {
    return true;
  }
  return false;
}
cocos2d::SEL_MenuHandler Level::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler Level::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool Level::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dragon", Dragon*, this->dragon_);
  return false;
}

void Level::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
}

void Level::onEnter()
{
  CCLayer::onEnter();
  
  // Schedule a selector that is called every frame
  this->scheduleUpdate();
  
  // Make sure touches are enabled
  this->setTouchEnabled(true);

}

void Level::onExit()
{
  CCLayer::onExit();
  
  // Remove the scheduled selector
  this->unscheduleUpdate();
}

void Level::update(float delta)
{
  // Iterate through all objects in the level layer
  CCObject* child;
  CCARRAY_FOREACH(this->getChildren(), child)
  {
    GameObject* gameObject = dynamic_cast<GameObject*>(child);
    // Check if the child is a game object
    if (gameObject)
    {
      // Update all game objects
      gameObject->update();
      
      // Check for collisions with dragon
      if (gameObject != dragon_)
      {
        if (ccpDistance(gameObject->getPosition(), dragon_->getPosition()) < gameObject->getRadius() + dragon_->getRadius())
        {
          // Notify the game objects that they have collided
          gameObject->handleCollisionWith(dragon_);
          dragon_->handleCollisionWith(gameObject);
        }
      }
    }
  }
  
  // Check for objects to remove
  CCArray* gameObjectsToRemove = CCArray::create();
  CCARRAY_FOREACH(this->getChildren(), child)
  {
    GameObject* gameObject = dynamic_cast<GameObject*>(child);
    if (gameObject)
    {
      if (gameObject->getScheduledForRemove())
      {
        gameObjectsToRemove->addObject(gameObject);
      }
    }
  }

  CCARRAY_FOREACH(gameObjectsToRemove, child)
  {
    GameObject* gameObject = dynamic_cast<GameObject*>(child);
    this->removeChild(gameObject, true);
  }
  
  // Adjust the position of the layer so dragon is visible
  float yTarget = kCJDragonTargetOffset - dragon_->getPosition().y;
  CCPoint oldLayerPosition = this->getPosition();
  
  float xNew = oldLayerPosition.x;
  float yNew = yTarget * kCJScrollFilterFactor + oldLayerPosition.y * (1.0f - kCJScrollFilterFactor);
  
  this->setPosition(ccp(xNew, yNew));
}
// default implements are used to call script callback if exist

void Level::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
  if (pTouches->count() == 1) {
    CCTouch* touch = reinterpret_cast<CCTouch*>(pTouches->anyObject());
    CCPoint location = touch->getLocationInView();
    dragon_->setXTarget(location.x);
  }
}

void Level::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
  if (pTouches->count() == 1) {
    CCTouch* touch = reinterpret_cast<CCTouch*>(pTouches->anyObject());
    CCPoint location = touch->getLocationInView();
    dragon_->setXTarget(location.x);
  }
}

void Level::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
  
}

void Level::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
  
}
