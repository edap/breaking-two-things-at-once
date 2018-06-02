#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60);


    buttonState = "digital pin:";
    potValue = "analog pin:";

    img.load("orchids.jpg");
    font.load("franklinGothic.otf", 20);
    smallFont.load("franklinGothic.otf", 14);

    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
    ard.connect("/dev/ttyACM3", 57600);

    // listen for EInitialized notification. this indicates that
    // the arduino is ready to receive commands and it is safe to
    // call setupArduino()
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)

    //Image
    float imgWidth = img.getWidth();
    float imgHeight = img.getHeight();
    float ratio = ofGetWidth() / imgWidth;
    img.resize(ofGetWidth(), ratio*imgHeight);

}

//--------------------------------------------------------------
void ofApp::update(){
    // This is fundamental! every change in input or output
    // get not reflected in your app without this function.
    updateArduino();

}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {

    // remove listener because we don't need it anymore
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);

    // it is now safe to send commands to the Arduino
    bSetupArduino = true;

    // print firmware name and version to the console
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();

    // Note: pins A0 - A5 can be used as digital input and output.
    // Refer to them as pins 14 - 19 if using StandardFirmata from Arduino 1.0.
    // If using Arduino 0022 or older, then use 16 - 21.
    // Firmata pin numbering changed in version 2.3 (which is included in Arduino 1.0)

    // set pins D2 and A5 to digital input
    ard.sendDigitalPinMode(2, ARD_INPUT);
    ard.sendDigitalPinMode(19, ARD_INPUT);  // pin 21 if using StandardFirmata from Arduino 0022 or older

    // set pin A0 to analog input
    ard.sendAnalogPinReporting(0, ARD_ANALOG);

    // Listen for changes on the digital and analog pins
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    // update the arduino, get any data or messages.
    // the call to ard.update() is required
    ard.update();

}

// digital pin event handler, called whenever a digital pin value has changed
// note: if an analog pin has been set as a digital pin, it will be handled
// by the digitalPinChanged function rather than the analogPinChanged function.

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int & pinNum) {
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    // do something with the analog input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    analogValue = ard.getAnalog(pinNum);
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(analogValue);
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    //ofSetColor(0, 0, 0, 127);
    if (!bSetupArduino){
        font.drawString("arduino not ready...\n", 515, 40);
    } else {
        font.drawString(potValue + "\n" + buttonState, 515, 40);

        noiseTheImage(analogValue);
        noisedImage.draw(0,0, img.getWidth(), img.getHeight());
    }
    ofPopStyle();

}

// via http://junkiyoshi.com/insta20180505/
void ofApp::noiseTheImage(int arduinoValue){
    float mappedAnalog = ofMap(arduinoValue, 0, 1023, 0, 140);
    auto pixels = img.getPixels();
    for (int y = 0; y < pixels.getHeight(); y++) {
        int noise_x = ofMap(ofNoise(y * 0.05 + ofGetFrameNum() * 0.05), 0, 1, -mappedAnalog, mappedAnalog);

        //if the noise is positive, shift the pixel to the left
        if (noise_x > 0) {
            for (int x = pixels.getWidth() - 1; x > noise_x; x--) {
                pixels.setColor(x, y, pixels.getColor(x - noise_x, y));
            }
        // if it is negative, shift them to the right
        } else if(noise_x < 0) {
            for (int x = 0; x < pixels.getWidth() + noise_x; x++) {
                pixels.setColor(x, y, pixels.getColor(x - noise_x, y));
            }
        }
    }
    noisedImage.setFromPixels(pixels);
};

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

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
