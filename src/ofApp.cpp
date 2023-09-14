#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetWindowTitle("sketch1");
  ofSetFrameRate(24); // run at 60 fps
  ofSetVerticalSync(true);
  ofBackground(palette.getMain(0));

  lineTrace.setup();
  auto w = ofGetWidth();
  auto h = ofGetHeight();
  lineTrace.setBounds(
    ofRectangle(0.01 * w, 0.01 * h, 0.98 * w, 0.98 * h)
  );
}

//--------------------------------------------------------------
void ofApp::update() {
  lineTrace.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  lineTrace.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
  lineTrace.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
void ofApp::dragEvent(ofDragInfo dragInfo){

}
