//
//  LabelTTFScene.h
//  LabelTTF
//
//  Created by MAEDAHAJIME on 2015/03/02.
//
//

#ifndef __LabelTTF__LabelTTFScene__
#define __LabelTTF__LabelTTFScene__

#include "cocos2d.h"

class LabelTTFScene : public cocos2d::Layer
{
protected:
    LabelTTFScene();
    virtual ~LabelTTFScene();
    //初期化のメソッド
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    // BGMの再生
    void onEnterTransitionDidFinish() override;
    // create()を使えるようにしている。
    CREATE_FUNC(LabelTTFScene);
    
    // バッククリックキー
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    
};


#endif /* defined(__LabelTTF__LabelTTFScene__) */
