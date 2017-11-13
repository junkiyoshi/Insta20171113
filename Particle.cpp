#include "Particle.h"

Particle::Particle() {
	this->location = ofVec3f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2));
	this->velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2), ofRandom(-2, 2));
	this->body_color.setHsb(ofRandom(255), 255, 255);
	//this->body_color = ofColor(0);
}

void Particle::update() {
	this->location += this->velocity;

	if (this->location.x < -ofGetWidth() / 2) {
		this->location.x = -ofGetWidth() / 2;
		this->velocity.x *= -1;
	}
	else if (this->location.x > ofGetWidth() / 2) {
		this->location.x = ofGetWidth() / 2;
		this->velocity.x *= -1;
	}

	if (this->location.y < -ofGetHeight() / 2) {
		this->location.y = -ofGetHeight() / 2;
		this->velocity.y *= -1;
	}
	else if (this->location.y > ofGetHeight() / 2) {
		this->location.y = ofGetHeight() / 2;
		this->velocity.y *= -1;
	}

	if (this->location.z < -ofGetWidth() / 2) {
		this->location.z = -ofGetWidth() / 2;
		this->velocity.z *= -1;
	} else if (this->location.z > ofGetWidth() / 2) {
		this->location.z = ofGetWidth() / 2;
		this->velocity.z *= -1;
	}
}

void Particle::draw(vector<shared_ptr<Particle>> particles) {

	ofSetColor(this->body_color);
	ofDrawSphere(this->location, 3);

	float distance;
	for (int i = 0; i < particles.size(); i++) {
		distance = this->location.distance(particles[i]->get_location());
		if (distance > 0 && distance < 64) {
			ofDrawLine(this->location, particles[i]->get_location());
		}
	}
}

ofVec3f Particle::get_location() {
	return this->location;
}