#include "ofApp.h"
#include "ofxEasing.h"

//This example is copied from that one in the ofxEasing repository
void ofApp::setup(){
    positions.resize(5);
    circles.resize(5);

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
    auto duration = 1.f; // try to change the duration
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    positions[0] = ofxeasing::map_clamp(now,
                                        initTime,
                                        endTime,
                                        0,
                                        endPosition,
                                        &ofxeasing::linear::easeIn);



    positions[1] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::quad::easeIn);
    positions[2] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::cubic::easeIn);
    positions[3] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::bounce::easeOut);

    // the back easing equation can receive an extra parameter in the _s functions
    // that controls how much the easing goes forward or backwards
    positions[4] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::back::easeOut_s, 0.8);


    // Have a look at the addon, there are others easing function available
    // try a different one

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    auto h = 20;
    auto y = 20;
    auto i = 0;
    // try to change the colors of the ball
    for(auto & x: positions){
        // in this case, the updatePosition method is moving the ball from
        // left to right.
        // can you imagine other ways to move the balls reading the values
        // contained in the positions vector?
        circles[i].updatePosition(glm::vec2(x, y));
        circles[i].draw();
        ofDrawBitmapString(easingNames[i], 10, y+h*1.6);
        y+=h*2;
        i++;
    }

    ofSetColor(255, 0, 0);
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
