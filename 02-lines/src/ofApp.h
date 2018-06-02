#pragma once

#include "ofMain.h"

class Line {
public:
    ofPoint a;
    ofPoint b;
    ofColor color;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        void mouseDragged(int x, int y, int button);

    vector < ofPoint > drawnPoints;
    vector < Line > lines;

    bool enableNoise = false;
};
