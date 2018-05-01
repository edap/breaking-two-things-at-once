#include "Circle.h"

Circle::Circle(){} //what happens if you remove this line? can you explain why?

Circle::Circle(glm::vec2 _pos, float _radius,ofColor _color){
    pos = _pos;
    startPos = _pos;
    radius = _radius;
    color = _color;
}

void Circle::draw(){
    ofPushStyle();
    ofSetColor(color.r, color.g, color.b, 200);
    ofDrawCircle(pos, radius);
    //ofDrawLine(pos.x, pos.y, 0, pos.x+20, pos.y+20, 0);
    ofPopStyle();
}

float Circle::getRadius(){
    return radius;
}

glm::vec2 Circle::getPos(){
    return pos;
}

void Circle::update(float pct){
    pos = startPos + direction * pct;
}

void Circle::setNewTarget(glm::vec2 newTarget){
    startPos = pos;
    target = newTarget;
    direction = target - pos;
};

