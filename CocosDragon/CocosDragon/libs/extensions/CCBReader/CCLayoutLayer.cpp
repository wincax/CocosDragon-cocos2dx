//
//  CCLayoutLayer.cpp
//  iwar
//
//  Created by michaelwong on 3/1/13.
//
//

#include "CCLayoutLayer.h"


CCLayoutLayer::CCLayoutLayer()
{
  
}

bool CCLayoutLayer::init()
{
  bool ret = CCLayer::init();
  if (ret) {
  }
  return ret;
}


CCLayoutLayer::~CCLayoutLayer()
{
}

void CCLayoutLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
  
  float scaleX = CCDirector::sharedDirector()->getOpenGLView()->getScaleX();
  float scaleY = CCDirector::sharedDirector()->getOpenGLView()->getScaleY();
  
  if (scaleX < 1 || scaleY < 1) {
    if (scaleX > scaleY && scaleY != 0) {
      this->setScaleY(scaleX/scaleY);
    }
    else if (scaleX < scaleY && scaleX != 0) {
      this->setScaleX(scaleY/scaleX);
    }
  }
  else if (scaleX < 1.2f || scaleY < 1.2f){
    this->setScaleX(1.0f/scaleX);
    this->setScaleY(1.0f/scaleY);
  }
  else {
    if (scaleX > scaleY && scaleX != 0) {
      this->setScaleX(scaleY/scaleX);
    }
    else if (scaleX < scaleY && scaleY != 0) {
      this->setScaleY(scaleX/scaleY);
    }
  }
  CCLOG("onNodeLoaded");
}

