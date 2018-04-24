#include "ofApp.h"
#include "ofxEasing.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bgOne = ofFloatColor::limeGreen;
    bgTwo = ofFloatColor::mistyRose;
    // try to pass other arguments to the Circle constructor.
    circle = Circle(glm::vec2(200, 400), 40., ofFloatColor::fuchsia);
    ofDisableAlphaBlending(); // What happen if you remove this line? observe
    // carefully the colors of your application.

    positions.resize(5);
    initTime = 0;
    endPosition = ofGetWidth() - 40;

    easingNames = {
        "linear",
        "quad",
        "cubic",
        "bounce",
        "back",
    };

}

//--------------------------------------------------------------
void ofApp::update(){
    circle.update(2);


    auto duration = 1.f;
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    positions[0] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::linear::easeIn);
    positions[1] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::quad::easeIn);
    positions[2] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::cubic::easeIn);
    positions[3] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::bounce::easeOut);

    // the back easing equation can receive an extra parameter in the _s functions
    // that controls how much the easing goes forward or backwards
    positions[4] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::back::easeOut_s, 0.8);


}

//--------------------------------------------------------------
void ofApp::draw(){

    /*
    /// Try differents background.
    /// - Circular: `OF_GRADIENT_CIRCULAR`
    /// - Linear: `OF_GRADIENT_LINEAR`
    /// - Bar: `OF_GRADIENT_BAR`
    ofBackgroundGradient(bgOne, bgTwo, OF_GRADIENT_CIRCULAR);

    // Draw Two Circles
    auto x1 = ofGetWidth()/2 - 200;
    auto x2 = ofGetWidth()/2 + 200;
    ofPushStyle();
    ofSetColor(250,200,100);
    ofDrawCircle(glm::vec2(x1, 300), 300.);
    ofPopStyle();

    ofPushStyle();
    ofSetColor(100,50,100);
    ofDrawCircle(glm::vec2(x2, 300), 30.);
    ofPopStyle();

    // Use the Circle class to draw a circle
    circle.draw();
    */


    ofSetColor(255);
    auto h = 20;
    auto y = 20;
    auto i = 0;
    for(auto & x: positions){
        ofDrawRectangle(0, y, x, h);
        ofDrawBitmapString(easingNames[i], 10, y+h*1.6);
        y+=h*2;
        i++;
    }

    ofSetColor(200);
    ofDrawLine(endPosition, 0, endPosition, ofGetHeight());


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
    initTime = ofGetElapsedTimef();
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
