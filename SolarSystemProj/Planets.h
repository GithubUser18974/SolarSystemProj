#include <string>
class Planets{

private :
	std::string name;
	float radius;
	float distance;
	float speed;
	float rotatAngle;
	float orbitNumber;
	float orbitAngle;
public:
	Planets(std::string name, float radius, float distance, float orbitNumber, float speed, float orbitAngle);
	Planets();
	void setName(std::string name);
	std::string getName();
	void setSpeed(float speed);
	float getSpeed();
	void setRadius(float radius);
	float getRadius();
	void setDistance(float distance);
	float getDistance();
	void setOrbitNumber(float orbitNumber);
	float getOrbitNumber();
	void setOrbitAngle(float orbitNumber);
	float getOrbitAngle();
	void drawChildMoon();
	void drawMoonOrbit();
	void detectCollision();
};