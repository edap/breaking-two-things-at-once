#include "ofApp.h"
#include "ofxEasing.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofFloatColor::ivory);

    palette.insert(make_pair(1, ofColor(1,77,189)));
    palette.insert(make_pair(2, ofColor(3,150,170)));
    palette.insert(make_pair(3, ofColor(240,195,4)));
    palette.insert(make_pair(4, ofColor(226,141,206)));

    for (int i = 0; i<nCircles; i++) {
        auto randKey = ofRandom(1,5);
        auto color = palette[randKey];

        auto randomPos = glm::vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
        auto randomRadius = ofRandom(10, 60);
        auto c = Circle(randomPos, randomRadius, color);

        circles.push_back(c);
    }

    initTime = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
//    auto duration = 10.f; // try to change the duration
//    auto endTime = initTime + duration;
//    auto now = ofGetElapsedTimef();
//    float pct = ofxeasing::map_clamp(now, initTime, endTime, 0, 1, &ofxeasing::bounce::easeOut);
//
//    cout << pct << endl;
//    for (auto &c:circles) {
//        c.update(pct);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto c:circles) {
        c.draw();
        //cout << c.getPos() << endl;
    }
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
    for (int i = 0; i<circles.size(); i++) {
        circles[i].setNewTarget(
                                  glm::vec2(
                                          ofRandom(x - proximity, x + proximity),
                                          ofRandom(y - proximity, y + proximity)
                                          )
                                  );
    }
    initTime = ofGetElapsedTimef();
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
