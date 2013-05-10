//
//  GameScene.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/10/13.
//
//

#include "GameScene.h"
#include "common_function.h"
#include "Level.h"
#include "Dragon.h"
#include "Explosion.h"
#include "Bomb.h"
#include "Coin.h"
#include "MainMenuScene.h"

static GameScene* sharedScene_;

GameScene::GameScene()
: scoreLabel_(NULL)
, levelLayer_(NULL)
, level_(NULL)
{
  
}

GameScene::~GameScene()
{
  CC_SAFE_RELEASE(scoreLabel_);
  CC_SAFE_RELEASE(levelLayer_);
}

GameScene* GameScene::sharedScene()
{
  return sharedScene_;
}

cocos2d::SEL_MenuHandler GameScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

cocos2d::extension::SEL_CCControlHandler GameScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
  return NULL;
}

bool GameScene::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode)
{
  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLabel", CCLabelTTF*, this->scoreLabel_);
  CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer", CCLayer*, this->levelLayer_);
  return false;
}

void GameScene::onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader)
{
  sharedScene_ = this;
  
  this->setScore(0);
  
  // Load the level
  map<string, CCNodeLoader*> loader_map;
  loader_map.insert(make_pair("Level", LevelLoader::loader()));
  loader_map.insert(make_pair("Dragon", DragonLoader::loader()));
  loader_map.insert(make_pair("Explosion", ExplosionLoader::loader()));
  loader_map.insert(make_pair("Bomb", BombLoader::loader()));
  loader_map.insert(make_pair("Coin", CoinLoader::loader()));
  level_ = loadCCBFile("res/Level.ccbi", loader_map);
  
  // And add it to the game scene
  if (level_ && levelLayer_) {
    levelLayer_->addChild(level_);
  }
}

void GameScene::setScore(int score) {
  score_ = score;
  CCString *velue = CCString::createWithFormat("%d", score_);
  scoreLabel_->setString(velue->getCString());
}

void GameScene::handleGameOver()
{
  CCScene *scene = NULL;
  // "MainMenuScene.ccbi"
  map<string, CCNodeLoader*> loader_map;
  loader_map.insert(make_pair("MainMenuScene", MainMenuSceneLoader::loader()));
  scene = (CCScene*)loadCCBFile("res/MainMenuScene.ccbi", loader_map);
  if (scene) {
    CCDirector::sharedDirector()->replaceScene(scene);
  }
}

void GameScene::handleLevelComplete()
{
  CCScene *scene = NULL;
  // "MainMenuScene.ccbi"
  map<string, CCNodeLoader*> loader_map;
  loader_map.insert(make_pair("MainMenuScene", MainMenuSceneLoader::loader()));
  scene = (CCScene*)loadCCBFile("res/MainMenuScene.ccbi", loader_map);
  if (scene) {
    CCDirector::sharedDirector()->replaceScene(scene);
  }
}
