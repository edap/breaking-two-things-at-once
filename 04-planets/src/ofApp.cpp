#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    material.setAmbientColor(ofFloatColor::red);
    material2.setAmbientColor(ofFloatColor::lavender);
    material3.setAmbientColor(ofFloatColor::yellowGreen);
    lineMaterial.setAmbientColor(ofFloatColor::darkorange);
    light.setup();
    light.setPosition(-100, 100, 100);

    ofEnableDepthTest();

    nullNode.setPosition(0,0,0);
    opaNode.setParent(nullNode);

    sphere.setPosition(100,0,0);
    sphere.setParent(opaNode);

    sphere2.setPosition(200, 100,0);
    sphere2.setParent(sphere);

    sphere3.setPosition(50, 40,200);
    sphere3.setParent(sphere2);

    dog.load("sounds/dog.mp3");
    bird.load("sounds/bird.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
    nullNode.panDeg(1);
    sphere.tilt(3);
    sphere2.tilt(3);
    sphere3.roll(1);

    line.addVertex(sphere3.getGlobalPosition());
    if(line.size() > 300){
        line.getVertices().erase(
                    line.getVertices().begin()
                    );
    }

    // tilt
    ofLog() << sphere.getPitchDeg();
    // roll
    sphere.getRollDeg();
    // pan
    sphere.getHeadingDeg();

    if(sphere.getPitchDeg() < 100 && sphere.getPitchDeg() > 10){
        dog.play();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofFloatColor::coral, ofFloatColor::lightGreen);
    cam.begin();
    light.draw();
    material.begin();
    sphere.draw();
    material.end();

    lineMaterial.begin();
    line.draw();
    lineMaterial.end();

    material2.begin();
    sphere2.draw();
    material2.end();

    material3.begin();
    sphere3.draw();
    material3.end();

    cam.end();
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
