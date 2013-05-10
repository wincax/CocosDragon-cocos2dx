//
//  common_function.h
//  CocosDragon
//
//  Created by michaelwong on 5/10/13.
//
//

#ifndef CocosDragon_common_function_h
#define CocosDragon_common_function_h
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

static CCNode *loadCCBFile(const char * ccbi_file_name, map<string, CCNodeLoader*>& loader_map)
{
  CCNode *layer = NULL;
  if (!ccbi_file_name || loader_map.size() <= 0) {
    return layer;
  }
  
  // Create an autorelease CCNodeLoaderLibrary.
  CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
  
  map<string, CCNodeLoader*>::iterator iter = loader_map.begin();
  for (; iter != loader_map.end(); iter++) {
    ccNodeLoaderLibrary->registerCCNodeLoader(iter->first.c_str(), iter->second);
  }
  
  // Create an autorelease CCBReader.
  cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
  ccbReader->setCCBRootPath("res/");
  ccbReader->autorelease();
  // Load the scene from the ccbi-file, setting this class as
  // the owner will cause lblTestTitle to be set by the CCBReader.
  // lblTestTitle is in the TestHeader.ccbi, which is referenced
  // from each of the test scenes.
  layer = (CCNode*)ccbReader->readNodeGraphFromFile(ccbi_file_name, NULL);
  return layer;
}


#endif
