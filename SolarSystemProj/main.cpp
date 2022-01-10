#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "imageloader.h"
#include "Planets.h"
#include "Enemy.h"
using namespace std;

/********************************************************GLOBAL VARIABELS**************/
Enemy enemy1(20, 30, 0,1);
Enemy enemy2(25, 30, 0, 1);
Enemy enemy3(30, 30, 0, 1);
Enemy enemy4(20, 30, 5, 1);
Enemy enemy5(25, 30, 10, 1);
Enemy enemy6(30, 30, 15, 1);

//(string name, float radius, float distance, float orbitNumber, float speed,float orbitAngle)
//name describe planet name
//radius describe planet radius
//distance describe planet distance from sun
//orbit number describe planet rotation around sun
//speed describe the speed of rotation
//orbit anglr describe planet rotation around itself
Planets sun("Sun",5.0, 0, 0, 0, 0);				
Planets mer("Mercury", 1.0, 7, 0, 4.74,  0);		
Planets ven("Venus", 1.5, 11, 0, 3.50,  0);		
Planets ear("Earth", 2.0, 16, 0, 2.98,  0);		
Planets mar("Mars", 1.2, 21, 0, 2.41,  0);		
Planets jup("Jupiter", 3.5, 28, 0, 1.31,  0);		
Planets sat("Saturn", 3.0, 37, 0, 0.97,  0);		
Planets ura("Uranus", 2.5, 45.5, 0, 0.68,  0);	
Planets nep("Neptune", 2.3, 53.6, 0, 0.54,  0);	
Planets plu("Pluto", 0.3, 59, 0, 0.47,  0);		
Planets lun("Luna", .40, 3, 0, 5.40,  0);			
Planets pho("Phobos", .20, 1.8, 0, 2.30, 0);	
Planets dei("Deimos", .24, 2.4, 0, 3.60, 0);		
Planets eur("Europa", .24, 4, 0, 4.40,  0);		
Planets gan("Ganymede", .24, 4.7, 0, 5.00, 0);		
Planets cal("Callisto", .24, 5.3, 0, 2.30, 0);	
Planets tit("Titan", .75, 3.7, 0, 2.40,  0);	
Planets nix("Titan", .10, 1.5, 0, 5.00,  0);		
Planets puc("Puck", .26, 2.9, 0, 7.00, 0);		
Planets tri("Triton", .36, 3.2, 0, 3.40,  0);
Planets she("shehab", .2, 50, 0, 20, 0);

GLuint sunTexture, merTexture, venTexture,
	   earTexture, marTexture, jupTexture,
	   satTexture, uraTexture, nepTexture,
	   pluTexture, staTexture, logTexture,
	   nayzakTexture;
int isAnimate = 0; // make the palnets pause/move
int bigOrbitActive = 1;//	show/hide planet orbit 
int smallOrbitActive = 1;//	show/hide planet moon orbit
int moonsActive = 1;//	show/hide planet move
int changeCamera = 0;// change camers position
int showNames = 0; // show/hide planets name
int zoom = 50;   //   camera distance 
bool isNayzakStart = 0;
bool showTeamNamesB = false;
float nayPosy = 35.0f;
float nayPosZ = 0.0;
float lightPos[] = { 0.0, 0.0, 0.0, .1 };
// Spotlight position.
static float spotAngle = 180;// Spotlight cone half-angle.
float spotDirection[] = { 1.0f, 0.0f, 0.0f }; // Spotlight direction.
static float spotExponent = 1.0;// Spotlight exponent = attenuation factor.


/**********************************************************LOAD TEXTURE********/
//this function load the texture and return it

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); 
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

/**************************************************************AID HELPER***/
//this function write the planet name 

void writeBitmapString(void *font, string string)
{
	for (int i = 0; i < string.length() ; i++){
		glutBitmapCharacter(font, string[i]);
	}
}

/*****************************************ENemy**************************/
void drawEnemies(Enemy enemy){
	GLUquadric *quadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(enemy.getPosX(), enemy.getPosY(), enemy.getPosZ());
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, satTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric,enemy.getradius(), 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();



}
/********************* DETECTING COLLISION*******************/
Enemy fCollision(Enemy enemy){
	
	float tmp;

		enemy.setPosX(enemy.getPosX() - 0.03);
		tmp = 0.03;
	
	if (enemy.getPosX() - sun.getDistance() <= 0 &&enemy.getPosY()-tmp==0  ){
		cout << "sun";
		
	}
	else if (enemy.getPosX() - sat.getDistance() <= 0 ){
		cout << "sat";
	}
	else if (enemy.getPosX() - ear.getDistance() <= 0 ){
		cout << "ear";
	}
	else if (enemy.getPosX() - jup.getDistance() <= 0  ){
		cout << "jup";
	}
	else if (enemy.getPosX() - eur.getDistance() <= 0  ){
		cout << "ear";
	}
	else if (enemy.getPosX() - lun.getDistance() <= 0 ){
		cout << "lun";
	}
	else if (enemy.getPosX() - plu.getDistance() <= 0  ){
		cout << "plu ";
	}
	else if (enemy.getPosX() - mar.getDistance() <= 0  ){
		cout << "mar ";
	}
	else if (enemy.getPosX() - ura.getDistance() <= 0  ){
		cout << "urra ";
	}
	//////////////////////////////
	tmp = enemy.getPosY();
	if (tmp - 0.03 > 0){
		enemy.setPosY(enemy.getPosY() - 0.03);
	}
	tmp = enemy.getPosZ();
	if (tmp > 20  && tmp>0){
		enemy.setPosZ(enemy.getPosZ() - 0.1);
	}
	else if (tmp <= 0 && tmp < -20){
		enemy.setPosZ(enemy.getPosZ() + 0.1);
	}
	cout << enemy.getPosX() << " " << enemy.getPosY() << " " << enemy.getPosZ() << endl;
	return enemy;
}
/****************************************DRAW PLANET*********************************/
void drawPlanet(Planets planet,float y,float z,GLuint texture){
		GLUquadric *quadric = gluNewQuadric();
	glPushMatrix();
	glRotatef(planet.getOrbitNumber(), 0.0, 1.0, 0.0);
	glTranslatef(planet.getDistance(), 0.0, 0.0);
	if (showNames == 1){
		glRasterPos3f(0.0, 3, 0.0);
		glColor3ub(255, 255, 255);
		string tName = planet.getName();
		const char *name = tName.c_str();
		writeBitmapString(GLUT_BITMAP_HELVETICA_12,planet.getName());
	}
	glPushMatrix();
	//glRotatef(mer.getRotatAngle(), 1.0, 0.0, 0.0);
	glRotatef(planet.getOrbitAngle(), 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, planet.getRadius(), 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (smallOrbitActive == 1){
		tit.drawMoonOrbit();
	}
	if (moonsActive == 1){
		tit.drawChildMoon();
	}
	glPopMatrix();
}
/****************************************Initializaion FUNC*********************************/

void setup(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// update the depth buffer
	glEnable(GL_DEPTH_TEST);
	//TEXUTRING SETUP
	glEnable(GL_LINEAR);
	glEnable(GL_COLOR_MATERIAL);
	Image* sta = loadBMP("stars.bmp");
	staTexture = loadTexture(sta);		
	delete sta;
	Image* sun = loadBMP("sun.bmp");
	sunTexture = loadTexture(sun);		
	delete sun;
	Image* mer = loadBMP("mercury.bmp");
	merTexture = loadTexture(mer);		
	delete mer;
	Image* ven = loadBMP("venus.bmp");
	venTexture = loadTexture(ven);		
	delete ven;
	Image* ear = loadBMP("earth.bmp");
	earTexture = loadTexture(ear);		
	delete ear;
	Image* mar = loadBMP("mars.bmp");	
	marTexture = loadTexture(mar);		
	delete mar;
	Image* jup = loadBMP("jupiter.bmp");
	jupTexture = loadTexture(jup);		
	delete jup;
	Image* sat = loadBMP("saturn.bmp");	
	satTexture = loadTexture(sat);		
	delete sat;
	Image* ura = loadBMP("uranus.bmp");	
	uraTexture = loadTexture(ura);		
	delete ura;
	Image* nep = loadBMP("neptune.bmp");
	nepTexture = loadTexture(nep);		
	delete nep;
	Image* plu = loadBMP("pluto.bmp");	
	pluTexture = loadTexture(plu);		
	delete plu;


	//LIGHTING SETUP
	//enable lighting
	glEnable(GL_LIGHTING);
	//intialize ambient color
	float lightAmb[] = { 0.0, 0.0, 0.0, 0.5 };
	//intialize diffuse color
	float lightDifAndSpec[] = { 1.0, 1.0, 0.0, 0.5 };
	//intialize global ambient  color
	float globAmb[] = { 0.5, 0.5, 0.5, 0.5 };
	//intialze the color that will be used in the lighting types
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
	glEnable(GL_LIGHT0);
	//enable abmient color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	//specify the color position 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	//specify the color angle 
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotAngle);
	//specify the color direction 
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
	//specifies the intensity of the light
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExponent);
}

/******************************************DRAW PLANETS ORBITAL*******************/

void orbitalTrails(void){ 
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	int r = 100;
	glutWireTorus(0.001, mer.getDistance(), r, r);
	glutWireTorus(0.001, ven.getDistance(), r, r);
	glutWireTorus(0.001, ear.getDistance(), r, r);
	glutWireTorus(0.001, mar.getDistance(), r, r);
	glutWireTorus(0.001, jup.getDistance(), r, r);
	glutWireTorus(0.001, sat.getDistance(), r, r);
	glutWireTorus(0.001, ura.getDistance(), r, r);
	glutWireTorus(0.001, nep.getDistance(), r, r);
	glutWireTorus(0.001, plu.getDistance(), r, r);
	glPopMatrix();
}
/***********************************************DRAWTEAMMemeber**************************/
void drawTeamNames(string name , float x , float y , float z){
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glRasterPos3f(0.0, 3, 0.0);
	glColor3ub(255, 255, 255);
	writeBitmapString(GLUT_BITMAP_HELVETICA_12, name);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(x - 2, y+4, z);
	glutSolidOctahedron();
	glPopMatrix();

}

/****************************************DRAW Scene FUNC*********************************/
float camPosX = 0.0, camPosY = zoom, camPosZ = 50.0;
float camToX = 0.0, camToY = 0.0, camToZ = 0.0;
float camDirX = 0.0, camDirY = 1.0, camDirZ = 0.0;
void drawScene(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (changeCamera == 0)gluLookAt(camPosX, camPosY, camPosZ, camToX, camToY, camToZ, camDirX, camDirY, camDirZ);
	if (changeCamera == 1)gluLookAt(0.0, 0.0, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (changeCamera == 2)gluLookAt(0.0, zoom, 0.00001, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	if (bigOrbitActive == 1) orbitalTrails();
	//initialize quadric object to be able to draw shapes
	GLUquadric *quadric = gluNewQuadric();
	/**************************************SUN**************/
	drawPlanet(sun, 0, 0, sunTexture);	
	/****************************************MERCURT*******/
	drawPlanet(mer,0,0,merTexture);
	/*****************************VENUS*******************/
	drawPlanet(ven, 0, 0,venTexture);
	/************************************EARTH*********/
	drawPlanet(ear, 0, 0,earTexture);
	/*************************************MARS**********/
	drawPlanet(mar, 0, 0,marTexture);
	/************************************JUPITER**********/
	glPushMatrix();
	drawPlanet(jup, 0, 0,jupTexture);
	if (smallOrbitActive == 1){
		eur.drawMoonOrbit();
		gan.drawMoonOrbit();
		cal.drawMoonOrbit();
	}
	if (moonsActive == 1){
		eur.drawChildMoon();
		gan.drawChildMoon();
		cal.drawChildMoon();
	}
	glPopMatrix();
	/*************************************SATRUN**********/
	drawPlanet(sat, 0, 0,satTexture);
	/*************************************URANUS**********/
	drawPlanet(ura,0,0,uraTexture);
	/*************************************NEPTON**********/
	drawPlanet(nep,0,0,nepTexture);
	/*************************************PLOTO**********/
	drawPlanet(plu,0,0,pluTexture);
	/*************************************NAYZAK**********/

	if (showTeamNamesB){
		drawTeamNames("Mohamed Abdelrahman ", -68, 48, -50);
		drawTeamNames("Mohamed sobhy ", -68, 45, -50);
		drawTeamNames("Mohamed fadel ", -25, 48, -50);
		drawTeamNames("Mohamed yasser ", -25, 45, -50);
		drawTeamNames("AbdAllah Hasan ", 5, 48, -50);
		drawTeamNames("Abanob Fayez ", 5, 45, -50);
	}
	glutSwapBuffers();
}

void drawScenesInOrder(void){
	
		drawScene();
	
}

void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

/****************************************Animations FUNC*********************************/

void animate(int n){
	float deg360 = 360.0;
	if (isAnimate){
		int x=0;
		 //incremnt rotation of planets around sun
		mer.setOrbitNumber(mer.getOrbitNumber() + mer.getSpeed() + x);
		ven.setOrbitNumber(ven.getOrbitNumber() + ven.getSpeed() + x);
		ear.setOrbitNumber(ear.getOrbitNumber() + ear.getSpeed() + x);
		mar.setOrbitNumber(mar.getOrbitNumber() + mar.getSpeed() + x);
		jup.setOrbitNumber(jup.getOrbitNumber() + jup.getSpeed() + x);
		sat.setOrbitNumber(sat.getOrbitNumber() + sat.getSpeed() + x);
		ura.setOrbitNumber(ura.getOrbitNumber() + ura.getSpeed() + x);
		nep.setOrbitNumber(nep.getOrbitNumber() + nep.getSpeed() + x);
		plu.setOrbitNumber(plu.getOrbitNumber() + plu.getSpeed() + x);
		lun.setOrbitNumber(lun.getOrbitNumber() + lun.getSpeed() + x);
		pho.setOrbitNumber(pho.getOrbitNumber() + pho.getSpeed() + x);
		dei.setOrbitNumber(dei.getOrbitNumber() + dei.getSpeed() + x);
		eur.setOrbitNumber(eur.getOrbitNumber() + eur.getSpeed() + x);
		gan.setOrbitNumber(gan.getOrbitNumber() + gan.getSpeed() + x);
		cal.setOrbitNumber(cal.getOrbitNumber() + cal.getSpeed() + x);
		tit.setOrbitNumber(tit.getOrbitNumber() + tit.getSpeed() + x);
		nix.setOrbitNumber(nix.getOrbitNumber() + nix.getSpeed() + x);
		puc.setOrbitNumber(puc.getOrbitNumber() + puc.getSpeed() + x);
		tri.setOrbitNumber(tri.getOrbitNumber() + tri.getSpeed() + x);

				// if they roate 360 degree we have to reset the value of the orbit number 
		if (mer.getOrbitNumber() > deg360, ven.getOrbitNumber() > deg360, ear.getOrbitNumber() > deg360, mar.getOrbitNumber() > deg360,
			jup.getOrbitNumber() > deg360, sat.getOrbitNumber() > deg360, ura.getOrbitNumber() > deg360, nep.getOrbitNumber() > deg360,
			plu.getOrbitNumber() > deg360, lun.getOrbitNumber() > deg360, pho.getOrbitNumber() > deg360, dei.getOrbitNumber() > deg360,
			eur.getOrbitNumber() > deg360, gan.getOrbitNumber() > deg360, cal.getOrbitNumber() > deg360, tit.getOrbitNumber() > deg360,
			nix.getOrbitNumber() > deg360, puc.getOrbitNumber() > deg360, tri.getOrbitNumber() > deg360){
			
			mer.setOrbitNumber(mer.getOrbitNumber() - deg360);
			ura.setOrbitNumber(ura.getOrbitNumber() - deg360);
			sat.setOrbitNumber(sat.getOrbitNumber() - deg360);
			jup.setOrbitNumber(jup.getOrbitNumber() - deg360);
			mar.setOrbitNumber(mar.getOrbitNumber() - deg360);
			ear.setOrbitNumber(ear.getOrbitNumber() - deg360);
			ven.setOrbitNumber(ven.getOrbitNumber() - deg360);
			dei.setOrbitNumber(dei.getOrbitNumber() - deg360);
			pho.setOrbitNumber(pho.getOrbitNumber() - deg360);
			lun.setOrbitNumber(lun.getOrbitNumber() - deg360);
			nep.setOrbitNumber(nep.getOrbitNumber() - deg360);
			nix.setOrbitNumber(nix.getOrbitNumber() - deg360);
			tit.setOrbitNumber(tit.getOrbitNumber() - deg360);
			gan.setOrbitNumber(gan.getOrbitNumber() - deg360);
			eur.setOrbitNumber(eur.getOrbitNumber() - deg360);
			puc.setOrbitNumber(puc.getOrbitNumber() - deg360);
			tri.setOrbitNumber(tri.getOrbitNumber() - deg360);
		}

						//incremnt rotation of planets around itself
						int y = 5;
						mer.setOrbitAngle(mer.getOrbitAngle() + y);
						ven.setOrbitAngle(ven.getOrbitAngle() + y);
						ear.setOrbitAngle(ear.getOrbitAngle() + y);
						mar.setOrbitAngle(mar.getOrbitAngle() + y);
						jup.setOrbitAngle(jup.getOrbitAngle() + y);
						sat.setOrbitAngle(sat.getOrbitAngle() + y);
						ura.setOrbitAngle(ura.getOrbitAngle() + y);
						nep.setOrbitAngle(nep.getOrbitAngle() + y);
						plu.setOrbitAngle(plu.getOrbitAngle() + y);

					//reset orbit angel if they > 360
						if (mer.getOrbitAngle() > deg360, ven.getOrbitAngle() > deg360, ear.getOrbitAngle() > deg360,
							mar.getOrbitAngle() > deg360, jup.getOrbitAngle() > deg360, sat.getOrbitAngle() > deg360,
							ura.getOrbitAngle() > deg360, nep.getOrbitAngle() > deg360, plu.getOrbitAngle() > deg360){

							mer.setOrbitAngle(mer.getOrbitNumber() - deg360);
							ura.setOrbitAngle(ura.getOrbitAngle() - deg360);
							sat.setOrbitAngle(sat.getOrbitAngle() - deg360);
							jup.setOrbitAngle(jup.getOrbitAngle() - deg360);
							mar.setOrbitAngle(mar.getOrbitAngle() - deg360);
							ear.setOrbitAngle(ear.getOrbitAngle() - deg360);
							ven.setOrbitAngle(ven.getOrbitAngle() - deg360);
							dei.setOrbitAngle(dei.getOrbitAngle() - deg360);
							pho.setOrbitAngle(pho.getOrbitAngle() - deg360);
							lun.setOrbitAngle(lun.getOrbitAngle() - deg360);
							nep.setOrbitAngle(nep.getOrbitAngle() - deg360);
							nix.setOrbitAngle(nix.getOrbitAngle() - deg360);
							tit.setOrbitAngle(tit.getOrbitAngle() - deg360);
							gan.setOrbitAngle(gan.getOrbitAngle() - deg360);
							eur.setOrbitAngle(eur.getOrbitAngle() - deg360);
							puc.setOrbitAngle(puc.getOrbitAngle() - deg360);
							tri.setOrbitAngle(tri.getOrbitAngle() - deg360);
						}
		glutPostRedisplay();
		glutTimerFunc(30, animate, 1);
	}
}

void mouseControl(int button, int state, int x, int y)
{
	

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) exit(0);
	glutPostRedisplay();
}



void keyInput(unsigned char key, int x, int y){
	switch (key){
	case 27: exit(0); break;
	case ' ': if (isAnimate) isAnimate = 0; else{ isAnimate = 1; animate(1); } break;
	case 'o': if (smallOrbitActive) smallOrbitActive = 0; else smallOrbitActive = 1; glutPostRedisplay(); break;
	case 'O': if (bigOrbitActive) bigOrbitActive = 0; else bigOrbitActive = 1; glutPostRedisplay(); break;
	case 'm': if (moonsActive) moonsActive = 0; else moonsActive = 1; glutPostRedisplay(); break;
	case 'M': if (moonsActive) moonsActive = 0; else moonsActive = 1; glutPostRedisplay(); break;
	case 'l': if (showNames) showNames = 0; else showNames = 1; glutPostRedisplay(); break;
	case 'L': if (showNames) showNames = 0; else showNames = 1; glutPostRedisplay(); break;
	case '1': changeCamera = 0; glutPostRedisplay(); break;
	case '2': changeCamera = 1; glutPostRedisplay(); break;
	case '3': changeCamera = 2; glutPostRedisplay(); break;
	case 'x':{
				 if (showTeamNamesB)
					 showTeamNamesB = false;
				 else showTeamNamesB = true;
				 break; 
	}
	}
}
void keySpecialInput(int key, int x, int y){
	switch (key){
	case GLUT_KEY_DOWN:{ if (camPosY > -100) camPosY--; break; }
	case GLUT_KEY_UP:{ if (camPosY <75) camPosY++; break; }
	case GLUT_KEY_LEFT:{if (camPosX < 100)camPosX++; break; }
	case GLUT_KEY_RIGHT:{if (camPosX >-100)camPosX--; break; }
	}
}

void intructions(void){
	cout << "SPACE to play/pause the simulation." << endl;
	cout << "ESC to exit the simulation." << endl;
	cout << "O to show/hide Big Orbital Trails." << endl;
	cout << "o to show/hide Small Orbital Trails." << endl;
	cout << "M/m to show/hide Moons." << endl;
	cout << "L/l to show/hide labels" << endl;
	cout << "1, 2 and 3 to change camera angles." << endl;
	cout << "Scroll to change camera movement" << endl;
}

int main(int argc, char **argv){
	intructions();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(-500, 0);
	glutCreateWindow("Solar System");
	glutDisplayFunc(drawScenesInOrder);
	glutReshapeFunc(resize);
	glutMouseFunc(mouseControl);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(keySpecialInput);
	setup();
	glutMainLoop();
}