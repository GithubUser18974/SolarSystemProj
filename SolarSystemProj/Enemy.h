class Enemy{
private :
	float posX;
	float posY;
	float posZ;
	float radius;
public:
	Enemy(float, float, float,float);
	Enemy();
	float getPosX();
	float getPosY();
	float getPosZ();
	float getradius();
	void setRadius(float);
	void setPosX(float);
	void setPosY(float);
	void setPosZ(float);
};