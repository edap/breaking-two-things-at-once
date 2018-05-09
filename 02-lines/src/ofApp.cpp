#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetColor(30,30,30,30);
}

void ofApp::update(){
}

void ofApp::draw(){
    ofEnableAlphaBlending();


    for (auto line : lines) {
        ofPushStyle();
        ofSetColor(line.color);
        ofDrawLine(line.a, line.b);
        ofPopStyle();
    }
}

void ofApp::mouseDragged(int x, int y, int button){
    for (auto point : drawnPoints){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < 30){
            Line lineTemp;

            float hue = ofMap(dist, 0, 30, 100, 255);
            ofColor c = ofColor::fromHsb(hue, 200, 255);
            lineTemp.color = c;
    
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));
}
