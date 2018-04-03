#include "Circle.h"

Circle::Circle(){}

Circle::Circle(glm::vec2 _pos, float _radius,ofColor _color){
    pos = _pos;
    radius = _radius;
    color = _color;
}

void Circle::draw(){
    ofPushStyle();
    ofSetColor(color.r, color.g, color.b);
    ofDrawCircle(pos, radius);
    ofPopStyle();
}


