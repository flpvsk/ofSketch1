#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  padding = 8;

  ofSetWindowTitle("sketch1");
  ofSetFrameRate(24); // run at 60 fps
  ofSetVerticalSync(true);

	ofTrueTypeFont::setGlobalDpi(72);
	fontBody.load("MorePerfectDOSVGA.ttf", 18);
	fontBody.setLineHeight(24.0f);
	fontBody.setLetterSpacing(1.0);

	fontH2.load("MorePerfectDOSVGA.ttf", 40);
	fontH2.setLineHeight(39.0f);
	fontH2.setLetterSpacing(0.9);

	fontH1.load("MorePerfectDOSVGA.ttf", 46);
	fontH1.setLineHeight(48);
	fontH1.setLetterSpacing(1);

  ofBackground(palette.getBg());

  lineTrace.setup();
  auto w = ofGetWidth();
  auto h = ofGetHeight();

  auto bottomLineFrame = ofRectangle(
    padding,
    h - fontBody.getLineHeight() * 2,
    w - 2 * padding,
    fontBody.getLineHeight() * 2
  );
  auto lineTraceFrame = ofRectangle(
    padding,
    0.5 * h,
    w - 2 * padding,
    bottomLineFrame.getTop() - 0.5 * h
  );
  lineTrace.setBounds(lineTraceFrame);
  lineTraceBorder.setBounds(lineTraceFrame);
  lineTraceBorder.setPalette(palette);
  lineTraceBorder.setWidth(ofVec2f(2, 1));
  lineTraceBorder.setDistance(2);
  lineTraceBorder.setFont(fontBody);
  lineTraceBorder.setText("Sound of the shop");

  bottomTextLineBorder.setBounds(bottomLineFrame);
  bottomTextLineBorder.setWidth(ofVec2f(2, 1));
  bottomTextLineBorder.setDistance(2);
  bottomTextLineBorder.setPalette(palette);

  bottomTextLine.setBounds(bottomLineFrame);
  bottomTextLine.setFont(fontBody);
  bottomTextLine.setText("pedalmarkt.com");
  bottomTextLine.setColor(palette.getMain(0));
  bottomTextLine.setIsCenterHorizontal(true);
  bottomTextLine.setIsCenterVertical(true);

  auto timeOfDayTextBounds = ofRectangle(
    padding,
    padding,
    0.25 * (w - 2 * padding),
    fontH1.getLineHeight()
  );
  timeOfDayText.setBounds(timeOfDayTextBounds);
  timeOfDayText.setColor(palette.getMain(1.0));
  timeOfDayText.setFont(fontH1);
  timeOfDayText.setText("14:21");

  auto dayOfWeekBounds = ofRectangle(
    padding,
    timeOfDayTextBounds.getBottom() - 14,
    0.25 * (w - 2 * padding),
    fontH2.getLineHeight()
  );
  dayOfWeekText.setBounds(dayOfWeekBounds);
  dayOfWeekText.setColor(palette.getMain(0.4));
  dayOfWeekText.setFont(fontH2);
  dayOfWeekText.setText("FRIDAY");

  auto dayOfMonthBounds = ofRectangle(
    padding,
    dayOfWeekBounds.getBottom() - 10,
    0.25 * (w - 2 * padding),
    fontH2.getLineHeight()
  );
  dayOfMonthText.setBounds(dayOfMonthBounds);
  dayOfMonthText.setColor(palette.getMain(0.4));
  dayOfMonthText.setFont(fontH2);
  dayOfMonthText.setText("Sep 15");
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
  dayOfWeekText.draw();
  dayOfMonthText.draw();
  timeOfDayText.draw();

  lineTrace.draw();
  lineTraceBorder.draw();

  bottomTextLine.draw();
  // bottomTextLineBorder.draw();

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
