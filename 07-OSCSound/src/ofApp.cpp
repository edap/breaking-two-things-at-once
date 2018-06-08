#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofFloatColor::yellow);
    radiusOne = ofGetHeight()/2;
    radiusTwo = radiusOne;

    sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    radiusTwo = radiusOne*0.7 + sin(ofGetElapsedTimef() * 3.0)* radiusOne*0.3;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofFloatColor::aqua);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radiusOne);

    ofSetColor(ofFloatColor::coral);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radiusTwo);

    auto diff = (radiusOne - radiusTwo);
    ofLog() << diff;
    if (diff < 0.09) {
        sendOSC();
    }
}

void ofApp::sendOSC(){
    ofxOscMessage m;
    m.setAddress("/trigger/prophet");
    m.addFloatArg(ofRandom(10, 70)); //note
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
