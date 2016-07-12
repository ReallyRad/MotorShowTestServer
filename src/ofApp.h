#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();

		ofxTCPServer TCP;
		bool started;
		int timer_eda, timer_eeg, timer_ecg;

};
