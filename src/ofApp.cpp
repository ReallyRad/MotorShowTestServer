#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	TCP.setMessageDelimiter("\n");
	TCP.setup(5555);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (TCP.isClientConnected(0)) {
		string str = "a";
		str = TCP.receive(0);
		ofxJSONElement element = new ofxJSONElement;
		if (element.parse(str)) {
			if (element["COMMAND"].asString() == "start") {
				cout << "received start" << endl;
				TCP.send(0,"{ \"STATUS\": \"OK\"");
			}

			if (element["COMMAND"].asString() == "stop") {
				cout << "received stop" << endl;
				TCP.send(0, "{ \"STATUS\": \"OK\"");
			}
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){

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
