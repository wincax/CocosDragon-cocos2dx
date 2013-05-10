//
//  CocosDragonAppDelegate.cpp
//  CocosDragon
//
//  Created by michaelwong on 5/8/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
//#include "HelloWorldScene.h"
#include "MainMenuScene.h"
#include "common_function.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
  
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
  // initialize director
  CCDirector *pDirector = CCDirector::sharedDirector();
  CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
  pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
  pDirector->setProjection(kCCDirectorProjection2D);
  
  // Set the design resolution
  pEGLView->setDesignResolutionSize(320,
                                    480,
                                    kResolutionExactFit);
  
  CCSize frameSize = pEGLView->getFrameSize();
  
  pDirector->setContentScaleFactor(1.0f);
  
  // turn on display FPS
  pDirector->setDisplayStats(true);
  
  // set FPS. the default value is 1.0/60 if you don't call this
  pDirector->setAnimationInterval(1.0 / 60);
  
  // Load the main menu scene from the ccbi-file
  map<string, CCNodeLoader*> loader_map;
  loader_map.insert(make_pair("MainMenuScene", MainMenuSceneLoader::loader()));
  CCScene* mainScene = (CCScene*)loadCCBFile("res/MainMenuScene.ccbi", loader_map);
  if (mainScene) {
    // Then add the scene to the stack. The director will run it when it automatically when the view is displayed.
    pDirector->runWithScene(mainScene);
  }
  
  return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
  CCDirector::sharedDirector()->stopAnimation();
  SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
  SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
  CCDirector::sharedDirector()->startAnimation();
  SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
  SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}

