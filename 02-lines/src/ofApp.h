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

		void mouseDragged(int x, int y, int button);

    vector < ofPoint > drawnPoints;
    vector < Line > lines;
};
