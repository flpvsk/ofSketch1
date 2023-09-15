#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "pmPalette.h"

// listening port
#define PORT 8000

class pmLineTrace : public ofBaseApp{
  private:
    deque<ofPoint> points;
    ofxOscReceiver receiver;
    pmPalette palette;
    ofRectangle bounds;
    int maxPoints;

  public:
    void setup() override;
    void update() override;
    void draw() override;
    void mousePressed(int x, int y, int button) override;

    void setPalette(pmPalette palette);
    void setBounds(ofRectangle rect);
    void setMaxPoints(int maxPoints);
};
