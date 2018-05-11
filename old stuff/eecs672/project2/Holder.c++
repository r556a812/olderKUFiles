void createMonkeyBars(Controller& c, ShaderIF* sIF)
{
	double kd[3]; //Lime Green
	kd[0] = 0.9; kd[1] = 1.0; kd[2] = 0.4;
	//Create the big Poles from ground up
	c.addModel(new Pole(sIF, 8.0, 0.0, 6.0, 0.3, 16.0, 0.3, kd));
	c.addModel(new Pole(sIF, 8.0, 0.0, 9.5, 0.3, 16.0, 0.3, kd));
	c.addModel(new Pole(sIF, 8.0, 0.0, 18.0, 0.3, 16.0, 0.3, kd));
	c.addModel(new Pole(sIF, 8.0, 0.0, 21.5, 0.3, 16.0, 0.3, kd));
	c.addModel(new Pole(sIF, 8.0, 0.0, 30.0, 0.3, 16.0, 0.3, kd));
	c.addModel(new Pole(sIF, 8.0, 0.0, 33.5, 0.3, 16.0, 0.3, kd));

	//Creates the connecting poles at the top
	c.addModel(new Pole(sIF, 8.3, 14.0, 6.0, 0.1, 0.15, 28.0, kd));
	c.addModel(new Pole(sIF, 8.3, 15.85, 6.0, 0.1, 0.15, 28.0, kd));

	//Creates the connecting poles from Lwall to big Poles
	c.addModel(new Pole(sIF, 0.0, 14.0, 6.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 6.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 10.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 10.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 14.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 14.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 18.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 18.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 22.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 22.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 26.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 26.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 30.0, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 30.0, 8.3, 0.15, 0.1, kd));

	c.addModel(new Pole(sIF, 0.0, 14.0, 33.9, 8.3, 0.15, 0.1, kd));
	c.addModel(new Pole(sIF, 0.0, 15.85, 33.9, 8.3, 0.15, 0.1, kd));
}

void createRoom(Controller& c, ShaderIF* sIF)
{
	double k[3];
	k[0] = 0.556863; k[1] = 0.137255; k[2] = 0.137255;
	c.addModel(new Floor(sIF, 0.0, 0.0, 0.0, 1.0, 0.0, 40.0, k));
	k[0] = 0.0; k[1] = 0.0; k[2] = 0.0;
	c.addModel(new Floor(sIF, 1.0, 0.0, 0.0, 6.0, 0.0, 40.0, k));
	k[0] = 0.556863; k[1] = 0.137255; k[2] = 0.137255;
	c.addModel(new Floor(sIF, 7.0, 0.0, 0.0, 43.0, 0.0, 40.0, k));
	k[0] = 0.9; k[1] = 0.7; k[2] = 0.2;
	c.addModel(new Floor(sIF, 8.5, 0.01, 6.3, 10.0, 0.0, 3.2, k));
	c.addModel(new Floor(sIF, 8.5, 0.01, 18.3, 10.0, 0.0, 3.2, k));
	c.addModel(new Floor(sIF, 8.5, 0.01, 30.3, 10.0, 0.0, 3.2, k));


	k[0] = 0.752941; k[1] = 0.752941; k[2] = 0.752941;
	c.addModel(new Rwall(sIF, 50, 0, 0, 0, 20, 40, k));
	c.addModel(new Rwall(sIF, 0, 0, 0, 0, 20, 40, k));

	k[0] = 0.184314; k[1] = 0.184314; k[2] = 0.309804;
	c.addModel(new Rwall(sIF, 0.0, 0.0, 0.0, 50.0, 20.0, 0.0, k));
	c.addModel(new Rwall(sIF, 49.99, 15, 0.0, 0, 3, 40, k));
	c.addModel(new Rwall(sIF, 0.01, 15, 0.0, 0, 3, 40, k));


	k[0] = 0.556863; k[1] = 0.137255; k[2] = 0.137255;
	c.addModel(new Rwall(sIF, 49.98, 16, 0.0, 0, 1.0, 40, k));
	c.addModel(new Rwall(sIF, 0.02, 16, 0.0, 0, 1.0, 40, k));



}

void createWeights(Controller& c, ShaderIF* sIF)
{
	double k[3];
	double kr[3];
	double kg[3];
	double kb[3];
	kr[0] = 1.0; kr[1] = 0.0; kr[2] = 0.0; //Red weights
	kg[0] = 0.2; kg[1] = 1.0; kg[2] = 0.5; //Green weights
	kb[0] = 0.0; kb[1] = 0.0; kb[2] = 1.0; //Blue weights
	k[0] = 0.90; k[1] = 0.91; k[2] = 0.98; //Silver

	/************ Create the weight lifting bars ************/

	/***** BAR #1 *****/
	c.addModel(new Cylinder(sIF, 8.4, 6, 30, 33.8, 0.1, k));
	c.addModel(new Cylinder(sIF, 8.4, 6, 28.75, 30, 0.2, k));
	c.addModel(new Cylinder(sIF, 8.4, 6, 33.8, 35.05, 0.2, k));
	c.addModel(new Disk(sIF, 8.4, 6, 28.75, 0.2, k));
	c.addModel(new Disk(sIF, 8.4, 6, 35.05, 0.2, k));
	/***** BAR #2 *****/
	c.addModel(new Cylinder(sIF, 8.4, 1, 18, 21.8, 0.1, k));
	c.addModel(new Cylinder(sIF, 8.4, 1, 16.75, 18, 0.2, k));
	c.addModel(new Cylinder(sIF, 8.4, 1, 21.8, 23.05, 0.2, k));
	c.addModel(new Disk(sIF, 8.4, 1, 16.75, 0.2, k));
	c.addModel(new Disk(sIF, 8.4, 1, 23.05, 0.2, k));
	/***** BAR #3 *****/
	c.addModel(new Cylinder(sIF, 8.4, 5, 6, 9.8, 0.1, k));
	c.addModel(new Cylinder(sIF, 8.4, 5, 4.75, 6, 0.2, k));
	c.addModel(new Cylinder(sIF, 8.4, 5, 9.8, 11.05, 0.2, k));
	c.addModel(new Disk(sIF, 8.4, 5, 4.75, 0.2, k));
	c.addModel(new Disk(sIF, 8.4, 5, 11.05, 0.2, k));


/********** Creaete the weights on the bars **********/

	/********** BAR #1 *********/
	//Red Weight
	c.addModel(new Cylinder(sIF, 8.4, 6, 29.6, 29.9, 0.8, kr));
	c.addModel(new Cylinder(sIF, 8.4, 6, 33.9, 34.2, 0.8, kr));
	//Disk for ends of Red
	c.addModel(new Disk(sIF, 8.4, 6, 29.6, 0.8, kr));
	c.addModel(new Disk(sIF, 8.4, 6, 29.9, 0.8, kr));
	c.addModel(new Disk(sIF, 8.4, 6, 33.9, 0.8, kr));
  c.addModel(new Disk(sIF, 8.4, 6, 34.2, 0.8, kr));
	//Green Weight
	c.addModel(new Cylinder(sIF, 8.4, 6, 29.4, 29.6, 0.6, kg));
	c.addModel(new Cylinder(sIF, 8.4, 6, 34.2, 34.4, 0.6, kg));
	//Disk for ends of Green
	c.addModel(new Disk(sIF, 8.4, 6, 29.4, 0.6, kg));
	c.addModel(new Disk(sIF, 8.4, 6, 34.4, 0.6, kg));

	/********** BAR #3 *********/
	//Red Weight
	c.addModel(new Cylinder(sIF, 8.4, 5, 5.7, 6.0, 0.8, kr));
	c.addModel(new Cylinder(sIF, 8.4, 5, 9.8, 10.1, 0.8, kr));
	//Disk for ends of Red
	c.addModel(new Disk(sIF, 8.4, 5, 5.7, 0.8, kr));
	c.addModel(new Disk(sIF, 8.4, 5, 6.0, 0.8, kr));
	c.addModel(new Disk(sIF, 8.4, 5, 9.8, 0.8, kr));
  c.addModel(new Disk(sIF, 8.4, 5, 10.1, 0.8, kr));
	//Blue Weight
	c.addModel(new Cylinder(sIF, 8.4, 5, 5.55, 5.7, 0.68, kb));
	c.addModel(new Cylinder(sIF, 8.4, 5, 10.1, 10.25, 0.68, kb));
	//Disk for ends of Green
	c.addModel(new Disk(sIF, 8.4, 5, 5.55, 0.68, kb));
	c.addModel(new Disk(sIF, 8.4, 5, 10.25, 0.68, kb));

}
