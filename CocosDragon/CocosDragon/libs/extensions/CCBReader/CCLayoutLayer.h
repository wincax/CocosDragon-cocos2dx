//
//  CCLayoutLayer.h
//  iwar
//
//  Created by michaelwong on 3/1/13.
//
//

#ifndef __CCLayoutLayer_H_
#define __CCLayoutLayer_H_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

class CCLayoutLayer
: public cocos2d::CCLayer
, public cocos2d::extension::CCNodeLoaderListener
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCLayoutLayer, create);
  
  CCLayoutLayer();
  virtual ~CCLayoutLayer();
  
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
  
  virtual bool init();

    
};

class CCLayoutLayerLoader : public cocos2d::extension::CCLayerLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCLayoutLayerLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCLayoutLayer);
};

#endif /* defined(__iwar__CCLayoutLayer__) */
