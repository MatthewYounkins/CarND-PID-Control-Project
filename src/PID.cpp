#include "PID.h"
#include <stdio.h>


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

//void PID::Init(double Kp, double Ki, double Kd, double fM, double fp) {
void PID::Init(double Kp, double Ki, double Kd, double fM, double Kq, double score) {

	this->Kp = Kp;				//proportional muliplier
	this->Ki = Ki;				//integral muliplier
	this->Kd = Kd;				//derivative muliplier
	this->fM = fM;				//forget-Me term; to ignore integrals that were many iterations ago.
	this->Kq = Kq;				//quadratic term; to introduce nonlinear penalty for deviating far from center.
	this->score = score;		//inverted cost term
//	this->fp = fp;
	
	p_error = 0;				//initializing proportional error
	i_error = 0;				//initializing integral error
	d_error = 0;				//initializing derivative error
	score = 0;					//an inverted cost term - maximizing score is an approximation of 'best' control
}

double PID::UpdateScore(double cte, double speed, double angle) {
	//Score!!!
	//Score++:  0.02*speed.  	If you're going 50MPH, score++ per iteration.
	//Score--:  0.2 *cte^2		CTE is, perhaps , distance from center in meters.  If you're 2.24m off track, score--.
	//Score--:  0.02*cte^4		Very nonlinear, intended to severely penalize curbs.  if you're 2.66m off track, score--.
	//Score--:  .0025*angle^2	Intended to penalize oscillation; if you're steering at 20 degree, score--.		 	 
	
	score += .02 * speed - cte * cte * .2 - cte * cte * cte * cte * .02 - .0025* angle * angle;
	return score;
}
	


double PID::UpdateError(double cte) {
	d_error = cte - p_error;			//derivative of error
	p_error = cte;						//proportional error
	q_error = cte*cte;					//quadratic term (non-linear proportional gain)
	if(cte < 0) q_error = -q_error;		//don't forget to make the quadratic term the correct sign
	i_error = i_error*fM + cte;			//integral error:  here I use the old error, multiplied by a forget-me term, then integrate new error.
	return i_error;						//I use this somewhere else.  
	
}

double PID::TotalError() {
	double offset = 0;							//this is actually an additional penalty for being more than 3 meters off of centerline.
	if(p_error>3) offset = 10*(p_error-3);
	if(p_error<-3) offset = 10*(3+p_error);
	
	// This returns 'total error', which is the sum of all of the errors multiplied by proportions.  Magic numbers are used to make input numbers 
	// more manageable - with the coefficients below the input numbers are all between 0 and 10.
	
	return -.1*Kp*p_error - offset - .01*Ki*i_error -Kd*d_error - .000000001*Kq*q_error;
}


/*  The function below doesn't work for some reason.

int PID::UpdateLap(double angle) {
	//newLap = 0;
	rightTurnSum = rightTurnSum *.8;
	if(angle > 0.3) rightTurnSum = rightTurnSum + angle;
	if(rightTurnSum > 3) {
	//	newLap = 1;
		lapNum++;
	}
	return lapNum;
}

*/