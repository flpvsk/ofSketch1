#pragma once
#include "ofMain.h"
#include "pmPalette.h"

class pmBorder{
  private:
    pmPalette palette;
    ofRectangle bounds;
    ofVec2f width;
    float distance;
    ofTrueTypeFont font;
    std::string text;

  public:
    pmBorder();
    void update();
    void draw();
    void setPalette(pmPalette palette);
    void setBounds(ofRectangle rect);
    void setWidth(ofVec2f width);
    void setDistance(float distance);
    void setFont(ofTrueTypeFont font);
    void setText(std::string text);
};
