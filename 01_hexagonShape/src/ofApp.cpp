#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // drops framerate about 30-40
    //ofEnableSmoothing();
    
    ofLogToConsole();
    
    // SINGLE INSTANCE
    /*hexagoShape.setup(glm::vec3(100, 100, 0),60);
    hexagoShape.setStrokeSize(0);
    hexagoShape.setRoundness(0);
    hexagoShape.setDebug(true);
    */
    
    // MULTIPLE INSTANCES
    // Grid Size
    int size = 50;
    
    float hexW = 2 * size;
    float hexH = sqrt(3) * size;
    
    // The horizontal distance between adjacent hexagon centers is w * 3/4.
    // The vertical distance between adjacent hexagon centers is h.
    float hexHDist = hexW * (3.f / 4.f);
    float hexVDist = hexH;
    
    rowNum = floor(ofGetWidth() / hexHDist * 2) + 2;
    colNum = floor(ofGetHeight() / (hexH * 0.5f)) + 2;
    
    int startPosX = 0;
    int startPosY = 0;
    
    grid.resize((rowNum) * (colNum));
    
    for (int i = 0; i < colNum; i++ ) {
        for (int j = 0; j < rowNum; j++) {
            
            int pushFac;
            
            if(i % 2 == 0) {
                pushFac = hexHDist;
            }else{
                pushFac = 0;
            }
            
            int x = pushFac + startPosX + ( hexHDist * 2 ) * j;
            int y = startPosY + ( hexH * 0.5 ) * i;
            
            int _id = (j + (i * (rowNum)));

            grid[_id].setup(glm::vec3(floor(x), floor(y) ,0),size,FLAT);
            grid[_id].setDebug(false);
            grid[_id].setRoundness(0);
            grid[_id].setStrokeSize(4);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(100), ofColor(0));
    
    // SINGLE INSTANCE DRAW
    //hexagoShape.draw();
    
    // MULTIPLE INSTANCES DRAWING
    for (int i = 0; i < colNum; i++ ) {
        for (int j = 0; j < rowNum; j++) {
            int _id = (j + (i * (rowNum)));
            grid[_id].draw();
         }
    }
    
    
    // Utility class to draw fps on window
    utils.drawFPS(TOP_RIGHT);
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
