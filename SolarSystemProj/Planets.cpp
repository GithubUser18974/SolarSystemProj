#include <stdlib.h>
#include <GL/glut.h>
#include "Planets.h"
#include <string>

Planets::Planets(std::string name, float radius, float distance, float orbitNumber, float speed,float orbitAngle)
{
	this->distance = distance;
	this->name = name;
	this->radius = radius;
	this->orbitNumber = orbitNumber;
	this->speed = speed;
	this->orbitAngle = orbitAngle;
}
Planets::Planets(){

//Give a Default Values
	this->distance = 10;
	this->name = "earth";
	this->radius = 20;
	this->rotatAngle = 60;
	this->orbitNumber = 3;
}
float Planets::getDistance(){
	return this->distance;
}
std::string Planets::getName(){
	return this->name;
}
float Planets::getOrbitNumber(){
	return this->orbitNumber;
}
float Planets::getRadius(){
	return this->radius;
}

float Planets::getSpeed(){
	return this->speed;
}
float Planets::getOrbitAngle(){
	return this->orbitAngle;
}


void Planets::setDistance(float distance){
	this->distance = distance;
}
void Planets::setName(std::string name){
	this->name = name;
}
void Planets::setOrbitAngle(float orbitAngle){
	this->orbitAngle = orbitAngle;
}
void Planets::setOrbitNumber(float OrbitNumber){
	this->orbitNumber = OrbitNumber;
}
void Planets::setRadius(float radius){
	this->radius = radius;
}

void Planets::setSpeed(float speed){
	this->speed = speed;
}


void Planets::drawChildMoon(){
	GLUquadricObj *quadric;
	quadric = gluNewQuadric();
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glRotatef(this->getOrbitNumber(), 0.0, 1.0, 0.0);
	glTranslatef(distance, 0.0, 0.0);
	gluSphere(quadric, radius, 20.0, 20.0);
	glPopMatrix();
}
void Planets::drawMoonOrbit(){
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireTorus(0.001, this->distance, 100.0, 100.0);
	glPopMatrix();
}
void Planets::detectCollision(){
	if (this->name == "nayzak"){
	}
}
