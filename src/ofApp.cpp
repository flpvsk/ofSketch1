#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetWindowTitle("sketch1");
  ofSetFrameRate(24); // run at 60 fps
  ofSetVerticalSync(true);

	ofTrueTypeFont::setGlobalDpi(72);
	font.load("Moderat.otf", 18);
	font.setLineHeight(24.0f);
	font.setLetterSpacing(1.0);

  ofBackground(palette.getMain(0));

  lineTrace.setup();
  auto w = ofGetWidth();
  auto h = ofGetHeight();
  float pad = 0.1;
  auto frame = ofRectangle(
    pad * w,
    pad * h,
    (1 - 2 * pad) * w,
    (1 - 2 * pad) * h
  );
  lineTrace.setBounds(frame);
  border.setBounds(frame);
  border.setWidth(ofVec2f(4, 2));
  border.setDistance(2);
  border.setFont(font);
  border.setText("Check border text");
}

//--------------------------------------------------------------
void ofApp::update() {
  lineTrace.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  // ofSetColor(255, 0, 0, 255);
  // ofFill();
  // ofDrawRectangle(0, 0, 0, ofGetWidth(), ofGetHeight());
  lineTrace.draw();
  border.draw();
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
