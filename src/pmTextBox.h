#pragma once
#include "ofMain.h"

class pmTextBox{
  private:
    ofRectangle bounds;
    ofColor color;
    ofTrueTypeFont font;
    std::string text;
    ofRectangle textBox;
    bool isCenterHorizontal;
    bool isCenterVertical;

  public:
    void draw();
    void setBounds(ofRectangle rect);
    void setFont(ofTrueTypeFont font);
    void setText(std::string text);
    void setColor(ofColor color);
    void setIsCenterHorizontal(bool val);
    void setIsCenterVertical(bool val);
};

