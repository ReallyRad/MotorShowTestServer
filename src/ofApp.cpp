#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	TCP.setMessageDelimiter("\n");
	TCP.setup(5555);
	started = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	//si hay algun cliente conectado
	if (TCP.isClientConnected(0)) {	
		//recibir mensaje del cliente
		string str = TCP.receive(0);
		ofxJSONElement element = new ofxJSONElement;
		
		//look for start/stop messages
		if (str != "" && element.parse(str)) {
			if (element["COMMAND"].asString() == "start") {
				cout << "received start" << endl;
				TCP.send(0,"{ \"STATUS\": \"OK\"}");
				started = true;
			}

			if (element["COMMAND"].asString() == "stop") {
				cout << "received stop" << endl;
				TCP.send(0, "{ \"STATUS\": \"OK\"}");
				started = false;
			}
		}
		else {
			//cout << "error receiving message" << endl;
		}
	
		if (started) {

			//every 500ms, eda_fasic and eda_tonic, 1*8 samples
			if (ofGetElapsedTimeMillis() - timer_eda > 500) {
				//reset the timer
				timer_eda = ofGetElapsedTimeMillis();
				
				//use the template eda json file
				ofxJSONElement e = new ofxJSONElement();
				std::string file = "eda.json";
				bool parsingSuccessful = e.open(file);
				
				if (parsingSuccessful) {
					for (int i = 0; i < 2; i++) {
						//for each eda signal, set 8 random values and the timestamp
						for (int j = 0; j < 8; j++) e["DATA"][i]["Values"][j] = ofRandom(1);						
						e["DATA"][i]["Timestamp"] = ofGetElapsedTimeMillis();
					}
					
					//save to file to view results
					e.save("test.json", true);
					//send to client
					TCP.send(0,e.getRawString());
				}
				
			}

			//every 31.25ms, eeg_alpha, eeg_beta, eeg_theta, 4*8 samples
			if (ofGetElapsedTimeMillis() - timer_eeg > 31) {
				timer_eeg = ofGetElapsedTimeMillis();

			}

			//every 1000 ms, ecg_hr, 1 sample
			if (ofGetElapsedTimeMillis() - timer_ecg > 1000) {
				timer_ecg = ofGetElapsedTimeMillis();
			}


			//randomly, adquisition error
		}
	
	}
		
}
