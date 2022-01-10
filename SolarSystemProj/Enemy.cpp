#include "Enemy.h"
Enemy::Enemy(float x, float y, float z,float r){
	this->posX = x;
	this->posY = y;
	this->posZ = z;
	this->radius = r;
}
Enemy::Enemy(){
	this->posX = 20;
	this->posY = 30;
	this->posZ = 0;
}

void Enemy::setPosX(float x){
	this->posX = x;
}
void Enemy::setPosY(float y){
	this->posY = y;
}
void Enemy::setPosZ(float z){
	this->posZ = z;
}
void Enemy::setRadius(float r){
	this->radius = r;
}
float Enemy::getradius(){
	return this->radius;
}
float Enemy::getPosX(){
	return this->posX;
}
float Enemy::getPosY(){
	return this->posY;
}
float Enemy::getPosZ(){
	return this->posZ;
}