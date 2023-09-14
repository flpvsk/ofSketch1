#include "pmLineTrace.h"

void pmLineTrace::setup(){
  // listen on the given port
  ofLog() << "listening for osc messages on port " << PORT;
  receiver.setup(PORT);
}

void pmLineTrace::update(){
  // check for waiting messages
  while (receiver.hasWaitingMessages()) {
    ofxOscMessage m;

    // get the next message
    receiver.getNextMessage(m);

    // ofLog() << m.getAddress();
    if (m.getAddress() == "/coord") {
      float x = m.getArgAsFloat(0);
      float y = m.getArgAsFloat(1);

      if (
        !points.empty() &&
        points.back().x == x &&
        points.back().y == y
      ) {
        continue;
      }

      ofPoint pt = ofPoint(x, y);

      while (points.size() >= MAX_POINTS) {
        points.pop_front();
      }

      points.push_back(pt);
      continue;
    }

    if (m.getAddress() == "/clear") {
      points.clear();
    }
  }
}

void pmLineTrace::draw() {
  ofSetColor(palette.getMain(1.0));
  ofPoint prevPoint;
  bool hasFirstPoint = false;
  for (auto point : points) {
    if (!hasFirstPoint) {
      prevPoint = point;
      hasFirstPoint = true;
      continue;
    }
    ofSetColor(palette.getMain(1.0));
    ofDrawLine(
      ofPoint(
        ofLerp(bounds.getLeft(), bounds.getRight(), prevPoint.x),
        ofLerp(bounds.getBottom(), bounds.getTop(), prevPoint.y)
      ),
      ofPoint(
        ofLerp(bounds.getLeft(), bounds.getRight(), point.x),
        ofLerp(bounds.getBottom(), bounds.getTop(), point.y)
      )
    );
    prevPoint = point;
  }
}

void pmLineTrace::mousePressed(int x, int y, int button){
  points.clear();
}

void pmLineTrace::setPalette(pmPalette newPalette){
  palette = newPalette;
}

void pmLineTrace::setBounds(ofRectangle rect){
  bounds = rect;
}
