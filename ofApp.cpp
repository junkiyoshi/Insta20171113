#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	for (int i = 0; i < 512; i++) {
		this->particles.push_back(shared_ptr<Particle>(new Particle()));
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->draw(this->particles);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}