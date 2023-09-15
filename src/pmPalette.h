#ifndef PMPALETTE_H
#define PMPALETTE_H

#include "ofColor.h"
#include "ofMath.h"

class pmPalette {
 public:
  ofColor getMain(float f) {
    // assert(f <= 1 && f >= 0 && "Color should be between 0. and 1.");
    return ofColor::fromHsb(
      0.,
      0.,
      ofLerp(10, 255 - 60, 1. - f)
    );
  }
};

inline pmPalette getPalette() {
  return pmPalette();
}

#endif
