#pragma once
#include "ofMain.h"

class Circle{
public:
    Circle();
    Circle(glm::vec2 pos, float radius,ofColor color);

    void setup(float r, glm::vec2 p, ofColor c);
    void update(glm::vec2 pos, float radius, ofColor color);
    void draw();
    void setNewTarget(glm::vec2 newTarget);
    void update(float speed = 0.01); // default arguments

    glm::vec2 getPos();
    float getRadius(); // use getter to read private properties

private:
    string smell="sweet";
    glm::vec2 startPos;
    glm::vec2 pos;
    glm::vec2 target;
    glm::vec2 direction;
    float radius=13.6;
    ofColor color;

    float seed = 1;
    float xDir = 1;
    float yDir = 1;
};
