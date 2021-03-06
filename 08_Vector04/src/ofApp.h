#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void setInit(); // 初期設定
    void resetForce(); // 力をリセット
    void addForce(ofVec2f force); // 力を加える
    void updateForce(); // 力を更新
    void updatePos(); // 位置の更新
    // 画面からはみ出たらバウンドさせる
    void checkBounds(float xmin, float ymin, float xmax, float ymax);
    // 位置を枠内に収める
    void constrain(float xmin, float ymin, float xmax, float ymax);
    
    // 描画する円の数を指定
    static const int CIRCLE_NUM = 400;
    // 位置ベクトルの配列
    ofVec2f position[CIRCLE_NUM];
    // 速度ベクトルの配列
    ofVec2f velocity[CIRCLE_NUM];
    // 力ベクトルの配列
    ofVec2f force[CIRCLE_NUM];
    // 摩擦係数
    float friction = 0.01;
};
