#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3.0);
    
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.001;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),
                ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2)));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        if (atraction) {
            particles[i].addAttractionForce(mouseX, mouseY, ofGetWidth(), 0.1);
        }
        // パーティクル同士の反発する力
        for (int j = 0; j < i; j++){
            particles[i].addAttractionForce(particles[j], 150.0, 0.001);
        }
        
        particles[i].update();
        particles[i].throughOfWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 31);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    // メッシュを点で描く
    mesh.clear();
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    // 重力の点を描く
    if (atraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(mouseX, mouseY, 4);
    
    //文字の背景
    ofSetColor(0, 127);
    ofRect(0, 0, 200, 60);
    
    // ログを表示
    ofSetColor(255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        particles.clear();
        for (int i = 0; i < NUM; i++) {
            Particle p;
            p.friction = 0.002;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            particles.push_back(p);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    atraction = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    atraction = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
