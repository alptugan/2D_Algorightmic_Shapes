#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(40);
    rectGrad.setColors(ofColor(255,204,0), ofColor(155,104,0));
    rectGradAlpha.setColors(ofColor(255,204,0), ofColor(255,255,255,0), VERTICAL);
    rectGradDiagonalFill.setColors(ofColor(255,204,0), ofColor(255,255,255,0), DIAGONAL);
    rectGradDiagonalRevFill.setColors(ofColor(255,204,0), ofColor(255,255,255,0), DIAGONAL_REV);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    rectGrad.draw(50, 50, 200, 200);
    rectGradAlpha.draw(50 + rectGrad.x + rectGrad.getWidth(), 50, 200, 200);
    rectGradDiagonalFill.draw(rectGrad.x, 50 + rectGradAlpha.y + rectGradAlpha.getHeight(), 200, 200);
    rectGradDiagonalRevFill.draw(50 + rectGradDiagonalFill.x + rectGradDiagonalFill.getWidth(), rectGradDiagonalFill.y, 200, 200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
