// project2.c++: Starter for EECS 672 Project 2

#include "GLFWController.h"
#include "TEMPLATE_Subclass.h"
#include "MonkeyBars.h"
#include "Room.h"
#include "Weights.h"
#include "WeightHolder.h"
#include "Pole.h"
#include "Cylinder.h"
#include "Disk.h"
#include "LiftingBar.h"
#include "SceneElement.h"
#include "Controller_Additions.h"

void createLogo(Controller& c, ShaderIF* sIF)
{
	double k[3]; k[0] = 0.9; k[1] = 1.0; k[2] = 0.4; //lime green
	double kg[3]; kg[0] = 0.3; kg[1] = 0.3; kg[2] = 0.3; //dark gray

	c.addModel(new Disk(sIF, 25, 14, 0.1, 5.0, kg));
	c.addModel(new Pole(sIF, 23.5, 15.0, 0.2, 8.0, 2.0, 0.01, k));

	kg[0] = 0.7; kg[1] = 0.7; kg[2] = 0.7; //light gray
	c.addModel(new Pole(sIF, 18.5, 10.5, 0.2, 8.0, 2.0, 0.01, kg));
}

void createTV(Controller& c, ShaderIF* sIF)
{
	double kb[3]; kb[0] = 0.0; kb[1] = 0.0; kb[2] = 0.0; //black
	double kg[3]; kg[0] = 0.4; kg[1] = 0.4; kg[2] = 0.4; //gray
	//Left TV
	c.addModel(new Pole(sIF, 8.0, 4.0, 0.01, 4.0, 2.5, 0.01, kg));
	c.addModel(new Pole(sIF, 7.7, 3.7, 0.03, 0.3, 3.1, 0.01, kb));
	c.addModel(new Pole(sIF, 12.0, 3.7, 0.03, 0.3, 3.1, 0.01, kb));
	c.addModel(new Pole(sIF, 7.7, 6.5, 0.01, 4.3, 0.3, 0.01, kb));
	c.addModel(new Pole(sIF, 7.7, 3.7, 0.01, 4.3, 0.3, 0.01, kb));
	//Right TV
	c.addModel(new Pole(sIF, 38.0, 4.0, 0.01, 4.0, 2.5, 0.01, kg));
	c.addModel(new Pole(sIF, 37.7, 3.7, 0.03, 0.3, 3.1, 0.01, kb));
	c.addModel(new Pole(sIF, 42.0, 3.7, 0.03, 0.3, 3.1, 0.01, kb));
	c.addModel(new Pole(sIF, 37.7, 6.5, 0.01, 4.3, 0.3, 0.01, kb));
	c.addModel(new Pole(sIF, 37.7, 3.7, 0.01, 4.3, 0.3, 0.01, kb));
}

void createBoxes(Controller& c, ShaderIF* sIF)
{
	double k[3]; k[0] = 0.9; k[1] = 1.0; k[2] = 0.4; //lime green
	double kb[3]; kb[0] = 0.0; kb[1] = 0.0; kb[2] = 0.0; //black

	//Left Box
	c.addModel(new Pole(sIF, 4.0, 0.01, 31.0, 2.5, 1.0, 2.5, k));
	c.addModel(new Pole(sIF, 4.0, 1.01, 31.0, 2.5, 0.1, 2.5, kb));
	//Stacked boxes
	c.addModel(new Pole(sIF, 44.5, 0.01, 34.0, 2.5, 1.0, 2.5, k));
	c.addModel(new Pole(sIF, 44.5, 1.01, 34.0, 2.5, 0.1, 2.5, kb));

	c.addModel(new Pole(sIF, 44.8, 1.12, 34.0, 2.5, 1.0, 2.5, k));
	c.addModel(new Pole(sIF, 44.8, 2.22, 34.0, 2.5, 0.1, 2.5, kb));
	//Right middle box
	c.addModel(new Pole(sIF, 35.0, 0.01, 25.0, 2.5, 1.0, 2.5, k));
	c.addModel(new Pole(sIF, 35.0, 1.01, 25.0, 2.5, 0.1, 2.5, kb));
	//Left middle box
	c.addModel(new Pole(sIF, 22.0, 0.01, 11.0, 2.5, 0.5, 6.0, k));
	c.addModel(new Pole(sIF, 22.0, 0.51, 11.0, 2.5, 0.1, 6.0, kb));
}

void createYogaMats(Controller& c, ShaderIF* sIF)
{
	double ks[3]; ks[0] = 0.0; ks[1] = 0.0; ks[2] = 0.0;
	double kg[3]; kg[0] = 0.5; kg[1] = 1.0; kg[2] = 0.5;
	double ky[3]; ky[0] = 1.0; ky[1] = 1.0; ky[2] = 0.5;
	//Create the 1st mat
	c.addModel(new Pole(sIF, 20, 2, 0.01, 3, 6, 0.01, ky));
	//Create the holes in corner and the hooks
	c.addModel(new Cylinder(sIF, 20.3, 7.5, 0.0, 0.1, 0.1, ks));
	c.addModel(new Disk(sIF, 20.3, 7.5, 0.1, 0.1, ks));
	c.addModel(new Cylinder(sIF, 22.7, 7.5, 0.0, 0.1, 0.1, ks));
	c.addModel(new Disk(sIF, 22.7, 7.5, 0.1, 0.1, ks));
	//Create the 2nd mat
	c.addModel(new Pole(sIF, 24, 2, 0.01, 3, 6, 0.01, kg));
	//Create the holes in corner and the hooks
	c.addModel(new Cylinder(sIF, 24.3, 7.5, 0.0, 0.1, 0.1, ks));
	c.addModel(new Disk(sIF, 24.3, 7.5, 0.1, 0.1, ks));
	c.addModel(new Cylinder(sIF, 26.7, 7.5, 0.0, 0.1, 0.1, ks));
	c.addModel(new Disk(sIF, 26.7, 7.5, 0.1, 0.1, ks));
	//Create the 3rd mat
	c.addModel(new Pole(sIF, 28, 2, 0.01, 3, 6, 0.01, ky));
	//Create the holes in corner and the hooks
	c.addModel(new Cylinder(sIF, 28.3, 7.5, 0.0, 0.1, 0.1, ks));
	c.addModel(new Disk(sIF, 28.3, 7.5, 0.1, 0.1, ks));
	c.addModel(new Cylinder(sIF, 30.7, 7.5, 0.0, 0.1, 0.1, ks));
	c.addModel(new Disk(sIF, 30.7, 7.5, 0.1, 0.1, ks));
}

void createLights(Controller& c, ShaderIF* sIF)
{
	double kb[3]; kb[0] = 0.0; kb[1] = 0.0; kb[2] = 0.0; //black
	c.addModel(new Pole(sIF, 25, 16, 10, 0.2, 5, 0.2, kb));
	c.addModel(new Pole(sIF, 25, 16, 30, 0.2, 5, 0.2, kb));

	double ky[3]; ky[0] = 204.0; ky[1] = 204.0; ky[2] = 0.0; //yellow
	c.addModel(new Pole(sIF, 24.8, 15.8, 9.8, 0.6, 0.6, 0.6, ky));
	c.addModel(new Pole(sIF, 24.8, 15.8, 29.8, 0.6, 0.6, 0.6, ky));

}

void set3DViewingInformation(double xyz[6])
{
	ModelView::setMCRegionOfInterest(xyz);

	double delta_mcX = xyz[1] - xyz[0];
	double delta_mcY = xyz[3] - xyz[2];
	double delta_mcZ = xyz[5] - xyz[4];

	double maxDelta = delta_mcX;
	if (delta_mcY > maxDelta)
	{
		maxDelta = delta_mcY;
	}
	if (delta_mcZ > maxDelta)
	{
		maxDelta = delta_mcZ;
	}

	double distEyeCenter = maxDelta*1.5;
	double xmid = 0.5 * (xyz[0] + xyz[1]);
	double ymid = 0.5 * (xyz[2] + xyz[3]);
	double zmid = 0.5 * (xyz[4] + xyz[5]);

	cryph::AffPoint center(xmid, ymid, zmid);
	cryph::AffPoint eye(xmid, ymid, zmid+distEyeCenter);

	cryph::AffVector up = cryph::AffVector::yu;

	// Set values for eye-center-up to produce a reasonable off-axis
	// view of your scene, then:
	// Notify the ModelView of our MC->EC viewing requests:
	ModelView::setEyeCenterUp(eye, center, up);

	double ecZpp, ecZmin, ecZmax;

	ecZpp = -(distEyeCenter - 0.5 * maxDelta);
	ecZmin = ecZpp - maxDelta;
	ecZmax = ecZpp + 0.5 * maxDelta;

	// Set values for ecZpp, ecZmin, ecZmax that make sense in the context of
	// the EC system established above, then:

	ModelView::setProjection(PERSPECTIVE);
	ModelView::setProjectionPlaneZ(ecZpp);
	ModelView::setECZminZmax(ecZmin, ecZmax);
}

int main(int argc, char* argv[])
{
	//Named after my gym
	Controller_Additions c("THE SUMMIT", MVC_USE_DEPTH_BIT);
	c.reportVersions(std::cout);

	ShaderIF* sIF = new ShaderIF("shaders/basic.vsh", "shaders/phong.fsh");
	c.setShader(sIF);

	//Add Models to the scene
	const char* mat = "mat2.tga";
	const char* wood = "floor.tga";
	c.addModel(new Room(sIF, mat, wood));

	double kd[3]; kd[0] = 0.9; kd[1] = 1.0; kd[2] = 0.4;//Lime Green
	c.addModel(new MonkeyBars(sIF, 0.0, 8.0, 6.0, 34, 12.0, kd));
	c.addModel(new MonkeyBars(sIF, 50.0, 42.0, 6.0, 34, 12.0, kd));

	c.addModel(new Weights(sIF, 8.4));
	c.addModel(new Weights(sIF, 41.9));

	c.addModel(new WeightHolder(sIF, 12, 34.5));
	c.addModel(new WeightHolder(sIF, 12, 1.0));
	c.addModel(new WeightHolder(sIF, 38, 34.5));
	c.addModel(new WeightHolder(sIF, 38, 1.0));

	//Extra models to help fill the scene
	createYogaMats(c, sIF);
	createBoxes(c, sIF);
	createTV(c, sIF);
	createLogo(c, sIF);
	createLights(c, sIF);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	double xyz[6];
	c.getOverallMCBoundingBox(xyz);
	set3DViewingInformation(xyz);

	c.run();

	delete sIF;

	return 0;
}
