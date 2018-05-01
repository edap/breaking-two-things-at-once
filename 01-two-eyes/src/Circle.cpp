#include "Circle.h"

Circle::Circle(){} //what happens if you remove this line? can you explain why?

Circle::Circle(glm::vec2 _pos, float _radius,ofColor _color){
    pos = _pos;
    radius = _radius;
    color = _color;
}

void Circle::draw(){
    ofPushStyle();
    ofSetColor(color.r, color.g, color.b, 150);
    ofDrawCircle(pos, radius);
//    ofDrawEllipse()
//    ofDrawLine()
//    ofDrawRectangle()
//    ofDrawString()
//    ofDrawTriangle()
    //ofDrawLine(pos.x, pos.y, 0, pos.x+20, pos.y+20, 0);
    ofPopStyle();
}

float Circle::getRadius(){
    return radius;
}

void Circle::update(float speed){
    float leftLimit = 0 + radius;
    float rightLimit = ofGetWidth() - radius;
    float topLimit = 0 + radius;
    float bottomLimit = ofGetHeight() - radius;

    if (pos.x > rightLimit || pos.x < leftLimit) {
        xDir *= -1;
    }

    if (pos.y > bottomLimit  || pos.y < topLimit) {
        yDir *= -1;
    }

    pos.x += speed * xDir;
    pos.y += speed * yDir;
}


