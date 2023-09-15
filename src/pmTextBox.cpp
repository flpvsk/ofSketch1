#include "pmTextBox.h"

void pmTextBox::draw(){
  ofSetColor(color);
  float x = bounds.getLeft();
  float y = (
    bounds.getTop() +
    font.getLineHeight() * 0.6
  );

  if (isCenterHorizontal) {
    x += (bounds.getWidth() - textBox.getWidth()) * 0.5;
  }

  if (isCenterVertical) {
    y += (
      bounds.getHeight() * 0.5 -
      textBox.getHeight() * 0.5
    );
  }

  font.drawString(text, x, y);
}

void pmTextBox::setText(std::string s){
  textBox = font.getStringBoundingBox(s, 0, 0);
  text = s;
}

void pmTextBox::setBounds(ofRectangle rect){
  bounds = rect;
}

void pmTextBox::setFont(ofTrueTypeFont f){
  font = f;
}

void pmTextBox::setColor(ofColor c){
  color = c;
}

void pmTextBox::setIsCenterHorizontal(bool b){
  isCenterHorizontal = b;
}

void pmTextBox::setIsCenterVertical(bool b){
  isCenterVertical = b;
}
