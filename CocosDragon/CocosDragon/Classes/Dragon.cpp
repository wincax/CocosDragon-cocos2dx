//
//  Dragon.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//
//

#include "Dragon.h"
#import "Coin.h"
#import "Bomb.h"
#import "GameScene.h"
#import "CCBAnimationManager.h"

#define kCJStartSpeed 8
#define kCJCoinSpeed 8
#define kCJStartTarget 160

#define kCJTargetFilterFactor 0.05
#define kCJSlowDownFactor 0.995
#define kCJGravitySpeed 0.1
#define kCJGameOverSpeed -10
#define kCJDeltaToRotationFactor 5


Dragon::Dragon()
: ySpeed_(0)
, xTarget_(0) {
  
}

bool Dragon::init()
{
  if (GameObject::init()) {
    xTarget_ = kCJStartTarget;
    ySpeed_ = kCJStartSpeed;
    return true;
  }
  return false;
}
cocos2d::SEL_MenuHandler Dragon::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler Dragon::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool Dragon::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  return false;
}

void Dragon::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
}


void Dragon::completedAnimationSequenceNamed(const char *name)
{
  
}

void Dragon::update()
{
  // Calculate new position
  CCPoint oldPosition = this->getPosition();
  
  float xNew = xTarget_ * kCJTargetFilterFactor + oldPosition.x * (1-kCJTargetFilterFactor);
  float yNew = oldPosition.y + ySpeed_;
  
  this->setPosition(ccp(xNew,yNew));
  
  // Update the vertical speed
  ySpeed_ = (ySpeed_ - kCJGravitySpeed) * kCJSlowDownFactor;
  
  // Tilt the dragon depending on horizontal speed
  float xDelta = xNew - oldPosition.x;
  this->setRotation(xDelta * kCJDeltaToRotationFactor);
  
  // Check for game over
  if (ySpeed_ < kCJGameOverSpeed)
  {
    GameScene::sharedScene()->handleGameOver();
  }
}

void Dragon::handleCollisionWith(GameObject* gameObject)
{
  Coin *coin = dynamic_cast<Coin*>(gameObject);
  Bomb *bomb = dynamic_cast<Bomb*>(gameObject);
  if (coin)
  {
    // Took a coin
    ySpeed_ = kCJCoinSpeed;
    
    GameScene::sharedScene()->setScore(GameScene::sharedScene()->getScore()+1);
  }
  else if (bomb)
  {
    // Hit a bomb
    if (ySpeed_ > 0) ySpeed_ = 0;
    
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    if (animationManager) {
      animationManager->runAnimationsForSequenceNamed("Hit");
    }
  }
  
}

