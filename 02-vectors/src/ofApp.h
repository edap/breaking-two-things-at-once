#pragma once

#include "ofMain.h"
#include "Circle.h"
#include "penner.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    map<int, ofColor> palette;
    vector<Circle> circles;
    int nCircles = 400;
    float proximity = 200;

    // penner equation values
    float initTime;
};
