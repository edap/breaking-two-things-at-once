#pragma once
#include "ofxOsc.h"

// send host (aka ip address)
#define HOST "localhost"

/// send port
#define PORT 4559


#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void sendOSC(int note); // notes goes from 0 to 70

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

        ofxOscSender sender;

    float radiusOne;
    float radiusTwo;
    float radiusThree;
    float radiusFour;
};
