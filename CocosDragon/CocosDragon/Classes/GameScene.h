//
//  GameScene.h
//  CocosDragon
//
//  Created by michaelwong on 5/10/13.
//
//

#ifndef __CocosDragon__GameScene__
#define __CocosDragon__GameScene__

#include "cocos2d.h"
#include "GameObject.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class GameScene
: public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameScene, create);

  GameScene();
  virtual ~GameScene();
  // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
  static GameScene *sharedScene();
  
  virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
  virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
  virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
  
public:
  int getScore() {
    return score_;
  }
  void setScore(int score);
  
  void handleGameOver();
  void handleLevelComplete();

private:
  
  CCLayer* levelLayer_;
  CCLabelTTF* scoreLabel_;
  
  CCNode* level_;
  int score_;

};
class GameSceneLoader : public cocos2d::extension::CCLayerLoader {
public:
  CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameSceneLoader, loader);
  
protected:
  CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameScene);
  
};

#endif /* defined(__CocosDragon__GameScene__) */
