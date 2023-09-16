#ifndef PMPALETTE_H
#define PMPALETTE_H

#include "ofColor.h"
#include "ofMath.h"
#include "ofxEasingFunc.h"

class pmPalette {
 public:
  ofColor getMain(float f) {
    // assert(f <= 1 && f >= 0 && "Color should be between 0. and 1.");
    return ofColor::fromHsb(
      0.,
      0.,
      ofLerp(0, 255, ofxEasingFunc::Cubic::easeIn(1. - f))
    );
  }

  ofColor getBg() {
    return ofColor::fromHsb(
      0,
      0,
      255 - 60
    );
  }
};

inline pmPalette getPalette() {
  return pmPalette();
}

#endif
