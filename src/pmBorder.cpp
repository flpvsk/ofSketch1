#include "pmBorder.h"

pmBorder::pmBorder(): text("") {

}

void pmBorder::update(){
}

void pmBorder::draw(){
  ofSetLineWidth(0);
  ofSetRectMode(OF_RECTMODE_CORNER);
  ofFill();

  // background frame
  ofSetColor(palette.getMain(0));
  ofDrawRectangle(
    bounds.getLeft(),
    bounds.getTop(),
    0,
    bounds.getWidth(),
    2 * width.x + distance
  );

  ofDrawRectangle(
    bounds.getLeft(),
    bounds.getBottom() - (2 * width.x + distance),
    0,
    bounds.getWidth(),
    2 * width.x + distance
  );

  ofDrawRectangle(
    bounds.getLeft(),
    bounds.getTop(),
    0,
    2 * width.y + distance,
    bounds.getHeight()
  );

  ofDrawRectangle(
    bounds.getRight() - (2 * width.y + distance),
    bounds.getTop(),
    0,
    2 * width.y + distance,
    bounds.getHeight()
  );

  // horizontal lines
  ofSetColor(palette.getMain(1));

  ofDrawRectangle(
    bounds.getLeft(),
    bounds.getTop(),
    0,
    bounds.getWidth(),
    width.x
  );

  ofDrawRectangle(
    bounds.getLeft() + width.y + distance,
    bounds.getTop() + width.x + distance,
    0,
    bounds.getWidth() - 2 * (width.y + distance),
    width.x
  );

  ofDrawRectangle(
    bounds.getLeft(),
    bounds.getBottom() - width.x,
    0,
    bounds.getWidth(),
    width.x
  );

  ofDrawRectangle(
    bounds.getLeft() + width.y + distance,
    bounds.getBottom() - (2 * width.x + distance),
    0,
    bounds.getWidth() - 2 * (width.y + distance),
    width.x
  );

  // vertical lines
  ofDrawRectangle(
    bounds.getLeft(),
    bounds.getTop(),
    0,
    width.y,
    bounds.getHeight()
  );

  ofDrawRectangle(
    bounds.getLeft() + (width.y + distance),
    bounds.getTop() + (width.x + distance),
    0,
    width.y,
    bounds.getHeight() - 2 * (width.x + distance)
  );

  ofDrawRectangle(
    bounds.getRight() - width.y,
    bounds.getTop(),
    0,
    width.y,
    bounds.getHeight()
  );

  ofDrawRectangle(
    bounds.getRight() - (2 * width.y + distance),
    bounds.getTop() + (width.x + distance),
    0,
    width.y,
    bounds.getHeight() - 2 * (width.x + distance)
  );

  font.drawString(text, bounds.getLeft() + 20, bounds.getTop() + 20);
}

void pmBorder::setBounds(ofRectangle rect){
  bounds = rect;
}

void pmBorder::setPalette(pmPalette newPalette){
  palette = newPalette;
}

void pmBorder::setWidth(ofVec2f w) {
  width = w;
}

void pmBorder::setDistance(float d) {
  distance = d;
}

void pmBorder::setFont(ofTrueTypeFont f) {
  font = f;
}

void pmBorder::setText(std::string s) {
  text = s;
}
