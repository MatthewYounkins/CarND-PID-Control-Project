#include "PID.h"
#include <stdio.h>

#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

//void PID::Init(double Kp, double Ki, double Kd, double fM, double fp) {
void PID::Init(double Kp, double Ki, double Kd, double fM, double Kq, int lapNum) {

	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->fM = fM;
	this->Kq = Kq;
//	this->fp = fp;
	
	p_error = 0;
	i_error = 0;
	d_error = 0;
	rightTurnSum = 0;
	lapNum = 0;
	//newLap = 0;
	
}

double PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	q_error = cte*cte;
	if(cte < 0) q_error = -q_error;
	i_error = i_error*fM + cte;
	return i_error;
	
}

double PID::TotalError() {
	double offset = 0;
	if(p_error>3) offset = 10*(p_error-3);
	if(p_error<-3) offset = 10*(3+p_error);
	std::cout << "Connected!!!" << std::endl;
	return -.1*Kp*p_error - offset - .01*Ki*i_error -Kd*d_error - .000000001*Kq*q_error;
}

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