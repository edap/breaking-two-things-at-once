#include "ofApp.h"

// credits to http://junkiyoshi.com/insta20180612/


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

    this->font.load("frabk.ttf", 250, true, true, true);

    // open an FBO and write text to it
    this->fbo.allocate(ofGetWidth(), ofGetHeight());
    this->fbo.begin();
    ofClear(0);
    ofSetColor(0);

    // move the coordinate space to the center of the screen
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

    string word_1 = "MY";
    string word_2 = "NAME";
    font.drawString(word_1, font.stringWidth(word_1) * -0.5, font.stringHeight(word_1) * -0.3);
    font.drawString(word_2, font.stringWidth(word_2) * -0.5, font.stringHeight(word_2) * 1.3);
    fbo.end();
    fbo.readToPixels(pix);

}

//--------------------------------------------------------------
void ofApp::update(){
    // try to comment this out, and see what happens.
    ofSeedRandom(39);
}


//--------------------------------------------------------------
void ofApp::draw(){
    int number_of_circle = 600;

    vector<ofPoint> points;
    while (points.size() < number_of_circle) {

        int x = ofRandom(ofGetWidth());
        int y = ofRandom(ofGetHeight());

        // in these lines:
        // take some random value on the screen.
        // if this random value is not overlapping the
        // font, skip it
        ofColor pix_color = this->pix.getColor(x, y);
        if (pix_color != ofColor(0)) {
            continue;
        }

        float offset = 20;
        float time = sin(ofGetElapsedTimef());
        float x_increase = ofMap(ofNoise(ofRandom(number_of_circle), ofGetFrameNum() * 0.005), 0, 1, -offset, offset);
        float y_increase = ofMap(ofNoise(ofRandom(number_of_circle), ofGetFrameNum() * 0.005), 0, 1, -offset, offset);
        x += x_increase;
        y += y_increase;

        points.push_back(ofPoint(x, y));
    }

    // try out the drawConnected method instead the drawPointsSimple
    // Invent your own drawPointsMethod
    //drawConnected(points);
    drawPointsSimple(points);
}

void ofApp::drawPointsSimple(vector<ofPoint> points){
    for (auto p:points) {
        ofColor color;
        color.setHsb(ofRandom(255), 255, 255);
        ofSetColor(color);
        ofDrawCircle(p, ofRandom(3, 6));
    }
}

void ofApp::drawConnected(vector<ofPoint> points){
    for (int i = 0; i < points.size(); i++) {

        ofColor color;
        color.setHsb(ofRandom(255), 255, 255);

        ofSetColor(color);
        ofDrawCircle(points[i], 3);

        for(int j = 0; j < points.size(); j++){

            float distance = points[i].distance(points[j]);
            if (distance < 50) {

                ofSetColor(color, ofMap(distance, 0, 50, 255, 0));
                ofDrawLine(points[i], points[j]);
            }
        }
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
