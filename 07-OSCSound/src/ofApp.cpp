#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofFloatColor::yellow);
    radiusOne = ofGetHeight()/2;
    radiusTwo = radiusOne;
    radiusThree = radiusOne;
    radiusFour = radiusOne;

    sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    float sintime = sin(ofGetElapsedTimef() * 2.0);
    float cosTime = cos(ofGetElapsedTimef() * 2.0);
    radiusTwo = radiusOne*0.7 + sintime * radiusOne*0.3;
    radiusThree = radiusTwo*0.4 + cosTime * radiusTwo*0.6;
    radiusFour = radiusThree*0.2 + sintime * radiusThree*0.8;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofFloatColor::aqua);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radiusOne);

    ofSetColor(ofFloatColor::coral);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radiusTwo);

    ofSetColor(ofFloatColor::greenYellow);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radiusThree);

    ofSetColor(ofFloatColor::darkBlue);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radiusFour);

    auto diff1 = (radiusOne - radiusTwo);
    if (diff1 < 0.09) {
        sendOSC(30);
    }

    auto diff2 = (radiusTwo - radiusThree);
    if (diff2 < 0.09) {
        sendOSC(50);
    }

    auto diff3 = (radiusThree - radiusFour);
    if (diff3 < 0.09) {
        sendOSC(60);
    }
}

void ofApp::sendOSC(int note){
    ofxOscMessage m;
    m.setAddress("/trigger/prophet");
    m.addFloatArg(note); //note
    m.addFloatArg(0.1); // attach
    m.addFloatArg(0.2); // sustain
    m.addFloatArg(0.1);  //release
    sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
