#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("sketch1");
  ofSetFrameRate(24); // run at 60 fps
  ofSetVerticalSync(true);

  // listen on the given port
  ofLog() << "listening for osc messages on port " << PORT;
  receiver.setup(PORT);

  ofBackground(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
  // check for waiting messages
  while (receiver.hasWaitingMessages()) {
    ofxOscMessage m;

    // get the next message
    receiver.getNextMessage(m);

    // ofLog() << m.getAddress();
    if (m.getAddress() != "/coord") {
      continue;
    }

    float x = m.getArgAsFloat(0);
    float y = m.getArgAsFloat(1);

    if (prevPoint.x == x && prevPoint.y == y) {
      continue;
    }

    ofPoint pt = ofPoint(x, y);

    while (lines.size() >= MAX_LINES) {
      lines.pop_front();
    }

    Line line;
    line.a = ofPoint(prevPoint.x, prevPoint.y);
    line.b = pt;
    lines.push_back(line);
    prevPoint = pt;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (auto line : lines) {
    ofSetColor(200, 200, 200);
    ofDrawLine(
      ofPoint(
        line.a.x * ofGetWidth(), line.a.y * ofGetHeight()
      ),
      ofPoint(
        line.b.x * ofGetWidth(), line.b.y * ofGetHeight()
      )
    );
  }
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
  lines.clear();
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
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
