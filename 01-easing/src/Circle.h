#pragma once
#include "ofMain.h"

class Circle{
public:
    Circle();
    Circle(glm::vec2 pos, float radius,ofColor color);
    void update(glm::vec2 pos, float radius, ofColor color);
    void draw();
    void update(float speed = 1.0); // default arguments
    void updatePosition(glm::vec2 _pos);

    float getRadius(); // use getter to read private properties

private:
    glm::vec2 pos;
    float radius = 20;
    ofColor color;

    float xDir = 1;
    float yDir = 1;
};
