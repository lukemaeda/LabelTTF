//
//  LabelTTFScene.cpp
//  LabelTTF
//
//  Created by MAEDAHAJIME on 2015/03/02.
//
//

#include "LabelTTFScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

using namespace std; // String*

Scene* LabelTTFScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = LabelTTFScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

LabelTTFScene::LabelTTFScene()
{
    
}

LabelTTFScene::~LabelTTFScene()
{
    
}

// 「INIT」初期化
bool LabelTTFScene::init()
{
    if ( !Layer::init() )
    {
        
        return false;
    }
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // バックキー処理
    auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2(LabelTTFScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    auto director = Director::getInstance();
    auto winSize = director->getWinSize();
    
    // バックグランドカラー（ホワイト）
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    this->addChild(background);
    
    // LabelTTFクラスのsetDimensions()メソッドを利用
    auto *labelString = LabelTTF::create("文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！文字を表示させる！！！", "HiraKakuProN-W6", 36);
    labelString->setAnchorPoint(Vec2(0.5,0.5)); // 0.5：原点中央
    labelString->setPosition(Vec2(winSize.width/2, winSize.height/2)); // 中央
    
    //Size型を指定
    // 改行をさせるには、LabelTTFクラスのsetDimensions()メソッドを利用
    labelString->setDimensions(Size(550,900)); // 箱：幅と高さを指定
    /*
     画面のサイズに達した時に、文字が改行されます。
     Sizeクラスで、どこまでいったら改行するかを設定します。
     こうすれば、文字がどれだけ増えても自動的に改行されます。
     */
    this->addChild(labelString);
    
    return true;
}

// BGMの再生
void LabelTTFScene::onEnterTransitionDidFinish()
{
    // BGMの再生
    //CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("o12.mp3", true);
}

// バックキー処理 onKeyReleased()でバックキーのイベントを取得
void LabelTTFScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        Director::getInstance()->end(); // アプリを終了させる
    }
}

/*
 (runWithScene) プログラム起動後、最初のsceneを起動する処理。
 (replaceScene) 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
 (pushScene)    直前のsceneに戻る予定があるので、メモリに取っておく方法です。
 (popScene)     pushしたsceneを消して、元のsceneに戻る処理。
 
 pushとpopは、ゲーム中にオプション画面を開いてまた戻ってくる時などに使用します。
 
 cocos2dその7。シーン遷移 【pushScene、runWithScene】
 http://ameblo.jp/hash-r-1234/entry-10967942550.html
 
 */
