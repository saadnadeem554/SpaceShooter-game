//--------------------------draw enemy function---------------//
void drawenemy(bool started)
{
	if(started==true)
		return;

//---------------rectangle---------------//
		if(level == 1 && phase == 1)
		{
			no_alpha = 4;
			alphacount = 4;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			beta[0] = new Beta();

			alpha[2] = new Alpha();
			alpha[3] = new Alpha();

			//alpha = new Alpha[4];



			//beta = new Beta;
			no_beta = 2;
			betacount = 2;



			//gamma = new Gamma;
			//gamma->draw(600, 200);
			no_gamma = 4;
			gammacount = 4;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			beta[1] = new Beta();

			gamma[0]->draw(300, 200);
			gamma[1]->draw(350, 200);
			gamma[2]->draw(400, 200);
			gamma[3]->draw(450, 200);


			beta[0]->draw(300, 150);
			beta[1]->draw(450, 150);
			alpha[0]->draw(300, 100);
			alpha[1]->draw(350, 100);
			alpha[2]->draw(400, 100);
			alpha[3]->draw(450, 100);

		}

//-----------------------------circle---------------//
		if(level == 2 && phase == 1)
		{
			no_alpha = 4;
			alphacount=4;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			alpha[3] = new Alpha();
			//alpha[4] = new Alpha();

			//alpha = new Alpha[4];
			alpha[0]->draw(300, 100);
			alpha[1]->draw(350, 80);
			alpha[2]->draw(410, 80);
			alpha[3]->draw(460, 100);

			//beta = new Beta;
			no_beta = 2;
			betacount = 2;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[0]->draw(290, 150);
			beta[1]->draw(470, 150);


			//gamma = new Gamma;
			//gamma->draw(600, 200);
			no_gamma = 4;
			gammacount = 4;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[0]->draw(300, 200);
			gamma[1]->draw(350, 220);
			gamma[2]->draw(410, 220);
			gamma[3]->draw(460, 200);
		}

//-----------------------------------triangle-------------------------//
		if(level == 1 && phase == 3)
		{
			no_alpha = 3;
			alphacount = 3;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			//alpha[3] = new Alpha();
			//alpha[4] = new Alpha();

			//alpha = new Alpha[4];
			alpha[0]->draw(350, 100);
			alpha[1]->draw(250, 150);
			alpha[2]->draw(450, 150);
			//alpha[3]->draw(460, 100);

			//beta = new Beta;
			no_beta = 3;
			betacount = 3;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[0]->draw(150, 200);
			beta[1]->draw(50, 250);
			beta[2]->draw(550, 200);



			//gamma = new Gamma;
			//gamma->draw(600, 200);
			no_gamma = 4;
			gammacount = 4;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[0]->draw(650, 250);
			gamma[1]->draw(200, 250);
			gamma[2]->draw(500, 250);
			gamma[3]->draw(350, 250);
		}

//------------------------------cross---------------//
		if(level == 1 && phase == 2)
		{
			no_alpha = 3;
			alphacount = 3;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();

			alpha[0]->draw(150, 100);
			alpha[1]->draw(350, 200);
			alpha[2]->draw(550, 300);



			no_beta = 3;
			betacount = 3;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();


			beta[0]->draw(550, 100);
			beta[1]->draw(450, 150);
			beta[2]->draw(250, 250);



			no_gamma = 3;
			gammacount = 3;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[0]->draw(250, 150);
			gamma[1]->draw(450, 250);
			gamma[2]->draw(150, 300);

		}

//---------------diamond--------------//
		if(level == 2 && phase == 2)
		{
			no_alpha = 3;
			alphacount = 3;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();




			alpha[0]->draw(240, 100);
			alpha[1]->draw(300, 100);
			alpha[2]->draw(360, 100);



			no_beta = 6;
			betacount = 6;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[3] = new Beta();
			beta[4] = new Beta();
			beta[5] = new Beta();


			beta[0]->draw(200, 150);
			beta[1]->draw(175, 200);
			beta[2]->draw(150, 250);
			beta[3]->draw(400, 150);
			beta[4]->draw(425, 200);
			beta[5]->draw(450, 250);


			no_gamma = 7;
			gammacount = 7;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[4] = new Gamma();
			gamma[5] = new Gamma();
			gamma[6] = new Gamma();


			gamma[0]->draw(250, 355);
			gamma[1]->draw(350, 355);
			gamma[2]->draw(300, 380);

			gamma[3]->draw(200, 330);
			gamma[4]->draw(400, 330);
			gamma[5]->draw(150, 305);
			gamma[6]->draw(450, 305);

		}

//-------------------------------heart---------------------//

		if(level == 2 && phase == 3)
		{
			no_alpha = 5;
			alphacount = 5;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			alpha[3] = new Alpha();
			alpha[4] = new Alpha();


			alpha[0]->draw(150, 100);
			alpha[1]->draw(250, 125);
			alpha[2]->draw(350, 125);
			alpha[3]->draw(450, 100);
			alpha[4]->draw(300, 175);



			no_beta = 6;
			betacount = 6;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[3] = new Beta();
			beta[4] = new Beta();
			beta[5] = new Beta();


			beta[0]->draw(150, 150);
			beta[1]->draw(150, 200);
			beta[2]->draw(150, 250);
			beta[3]->draw(450, 150);
			beta[4]->draw(450, 200);
			beta[5]->draw(450, 250);


			no_gamma = 7;
			gammacount = 7;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[4] = new Gamma();
			gamma[5] = new Gamma();
			gamma[6] = new Gamma();


			gamma[0]->draw(250, 375);
			gamma[1]->draw(350, 375);
			gamma[2]->draw(300, 400);

			gamma[3]->draw(200, 350);
			gamma[4]->draw(400, 350);
			gamma[5]->draw(150, 325);
			gamma[6]->draw(450, 325);

		}

//--------------------level 3--------------//
//---------------rectangle filled---------//
		if(level == 3 && phase == 1)
		{
			no_alpha = 6;
			alphacount = 6;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			alpha[3] = new Alpha();
			alpha[4] = new Alpha();
			alpha[5] = new Alpha();

			alpha[0]->draw(300, 200);
			alpha[1]->draw(350, 100);
			alpha[2]->draw(400, 200);
			alpha[3]->draw(450, 150);

			alpha[4]->draw(350, 150);
			alpha[5]->draw(400, 150);


			no_beta = 2;
			betacount = 2;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[0]->draw(350, 200);
			beta[1]->draw(450, 100);


			no_gamma = 4;
			gammacount = 4;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[0]->draw(300, 100);
			gamma[1]->draw(300, 150);
			gamma[2]->draw(400, 100);
			gamma[3]->draw(450, 200);

		}

//-----------------filled triangle----------//
		if(level == 3 && phase == 2)
		{
			no_alpha = 3;
			alphacount = 3;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();


			alpha[0]->draw(350, 250);
			alpha[1]->draw(250, 150);
			alpha[2]->draw(550, 200);


			no_beta = 5;
			betacount = 5;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[3] = new Beta();
			beta[4] = new Beta();


			beta[0]->draw(650, 250);
			beta[1]->draw(50, 250);
			beta[2]->draw(450, 150);
			beta[3]->draw(300, 200);
			beta[4]->draw(400, 200);



			no_gamma = 4;
			gammacount = 4;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[0]->draw(150, 200);
			gamma[1]->draw(200, 250);
			gamma[2]->draw(500, 250);
			gamma[3]->draw(350, 100);
		}


//--------------------------filled cross---------------//
		if(level == 3 && phase == 3)
		{
			no_alpha = 3;
			alphacount = 3;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();

			alpha[0]->draw(150, 100);
			alpha[1]->draw(350, 200);
			alpha[2]->draw(550, 300);



			no_beta = 3;
			betacount = 3;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();


			beta[0]->draw(550, 100);
			beta[1]->draw(450, 150);
			beta[2]->draw(250, 250);



			no_gamma = 3;
			gammacount = 3;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[0]->draw(250, 150);
			gamma[1]->draw(450, 250);
			gamma[2]->draw(150, 300);

		}


//-------------------------filled----circle---------------//
		if(level == 3 && phase == 4)
		{
			no_alpha = 6;
			alphacount=6;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			alpha[3] = new Alpha();
			alpha[4] = new Alpha();
			alpha[5] = new Alpha();



			alpha[0]->draw(300, 200);
			alpha[1]->draw(350, 80);
			alpha[2]->draw(410, 80);
			alpha[3]->draw(410, 220);
			alpha[4]->draw(350, 170);
			alpha[5]->draw(410, 170);



			no_beta = 4;
			betacount=4;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[3] = new Beta();

			beta[0]->draw(290, 150);
			beta[1]->draw(460, 200);
			beta[2]->draw(350, 130);
			beta[3]->draw(410, 130);




			no_gamma = 4;
			gammacount=4;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[0]->draw(300, 100);
			gamma[1]->draw(350, 220);
			gamma[2]->draw(460, 100);
			gamma[3]->draw(470, 150);
		}


//--------------filled-diamond--------------//
		if(level == 3 && phase == 5)
		{
			no_alpha = 7;
			alphacount = 7;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			alpha[3] = new Alpha();
			alpha[4] = new Alpha();
			alpha[5] = new Alpha();
			alpha[6] = new Alpha();






			alpha[0]->draw(240, 100);
			alpha[1]->draw(300, 100);
			alpha[2]->draw(360, 100);
			alpha[3]->draw(225, 250);
			alpha[4]->draw(300, 250);
			alpha[5]->draw(375, 250);
			alpha[6]->draw(300, 150);





			no_beta = 7;
			betacount = 7;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[3] = new Beta();
			beta[4] = new Beta();
			beta[5] = new Beta();
			beta[6] = new Beta();



			beta[0]->draw(200, 150);
			beta[1]->draw(175, 200);
			beta[2]->draw(150, 250);
			beta[3]->draw(400, 150);
			beta[4]->draw(425, 200);
			beta[5]->draw(450, 250);
			beta[6]->draw(300, 200);



			no_gamma = 8;
			gammacount = 8;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[4] = new Gamma();
			gamma[5] = new Gamma();
			gamma[6] = new Gamma();
			gamma[7] = new Gamma();



			gamma[0]->draw(250, 355);
			gamma[1]->draw(350, 355);
			gamma[2]->draw(300, 380);

			gamma[3]->draw(200, 330);
			gamma[4]->draw(400, 330);
			gamma[5]->draw(150, 305);
			gamma[6]->draw(450, 305);
			gamma[7]->draw(300, 305);


		}

//----------------------filled heart-------------------//
		if(level == 3 && phase == 6)
		{
			no_alpha = 8;
			alphacount = 8;
			alpha[0] = new Alpha();
			alpha[1] = new Alpha();
			alpha[2] = new Alpha();
			alpha[3] = new Alpha();
			alpha[4] = new Alpha();
			alpha[5] = new Alpha();
			alpha[6] = new Alpha();
			alpha[7] = new Alpha();



			alpha[0]->draw(150, 100);
			alpha[1]->draw(250, 125);
			alpha[2]->draw(350, 125);
			alpha[3]->draw(450, 100);
			alpha[4]->draw(300, 175);
			alpha[5]->draw(360, 315);
			alpha[6]->draw(360, 265);
			alpha[7]->draw(360, 215);



			no_beta = 9;
			betacount = 9;
			beta[0] = new Beta();
			beta[1] = new Beta();
			beta[2] = new Beta();
			beta[3] = new Beta();
			beta[4] = new Beta();
			beta[5] = new Beta();
			beta[6] = new Beta();
			beta[7] = new Beta();
			beta[8] = new Beta();



			beta[0]->draw(150, 150);
			beta[1]->draw(150, 200);
			beta[2]->draw(150, 250);
			beta[3]->draw(450, 150);
			beta[4]->draw(450, 200);
			beta[5]->draw(450, 250);
			beta[6]->draw(280, 225);
			beta[7]->draw(280, 275);
			beta[8]->draw(280, 325);



			no_gamma = 10;
			gammacount = 10;
			gamma[0] = new Gamma();
			gamma[1] = new Gamma();
			gamma[2] = new Gamma();
			gamma[3] = new Gamma();
			gamma[4] = new Gamma();
			gamma[5] = new Gamma();
			gamma[6] = new Gamma();
			gamma[7] = new Gamma();
			gamma[8] = new Gamma();
			gamma[9] = new Gamma();



			gamma[0]->draw(250, 375);
			gamma[1]->draw(350, 375);
			gamma[2]->draw(300, 400);

			gamma[3]->draw(200, 350);
			gamma[4]->draw(400, 350);
			gamma[5]->draw(150, 325);
			gamma[6]->draw(450, 325);
			gamma[7]->draw(210, 275);
			gamma[8]->draw(210, 225);
			gamma[9]->draw(210, 175);


		}
}
