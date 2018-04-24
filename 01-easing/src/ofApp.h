#pragma once

#include "ofMain.h"
#include "Circle.h"

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


    ofColor bgOne;
    ofColor bgTwo;

    Circle circle;
    Circle bigCircle;

    // easing
    std::vector<float> positions;
    std::vector<Circle> circles;
    std::vector<std::string> easingNames;
    float initTime;
    float endPosition;
};

//Types, background
// ofPushStyle, ofPopStyle

// Classes: Constructor, types, return types in methods, instance variables


// Animation, fps. Time based animation VS Frame based animation (make an example just for this)
