#pragma once
#include "ofMain.h"

class Circle{
public:
    Circle();
    Circle(glm::vec2 pos, float radius,ofColor color);
    void update(glm::vec2 pos, float radius, ofColor color);
    void draw();

private:
    glm::vec2 pos;
    float radius;
    ofColor color;
};
