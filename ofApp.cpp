#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);


	this->noise_param += ofNoise(ofRandom(1000), ofGetFrameNum() * 0.039) * 0.01;
}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<glm::vec2> location_list;

	for (int i = 0; i < 65; i++) {

		auto location = glm::vec2(
			ofMap(ofNoise(ofRandom(1000), this->noise_param), 0, 1, 60, ofGetWidth() - 60),
			ofMap(ofNoise(ofRandom(1000), this->noise_param), 0, 1, 60, ofGetHeight() - 60)
		);

		location_list.push_back(location);
	}

	for (auto& location : location_list) {

		ofDrawCircle(location, 5);
		for (auto& other : location_list) {

			if (location == other) { continue; }

			if (glm::distance(location, other) < 65) {

				ofDrawLine(location, other);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}