#pragma once

#include "ofMain.h"

class Pen {
public:
    Pen();
    glm::vec2 pos;

    void update(float x, float y);
    void drawCircle();
    
};
