#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;	//error that will be multiplied by proportional gain
  double i_error;	//error that will be 
  double d_error;
  double q_error;	
  

  /*
  * Coefficients
  */ 
  double Kp;		//Proportional multiplier
  double Ki;		//Integral multiplier
  double Kd;		//Derivative multiplier
  double fM;		//A 'forget-me' term, that will be applied to an integral.  We don't care if whether we were tracking left three laps ago.
  double Kq;		//A quadratic multiplier term.  This is to introduce a non-linear penalty for deviating far from center.  
  double score;		//An inverted-cost function.  
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  //void Init(double Kp, double Ki, double Kd, double fM, double fp);
  void Init(double Kp, double Ki, double Kd, double fM, double Kq, double score);

  
  double UpdateScore(double cte, double speed, double angle);	//the score is basically an inverted cost function - it's a measure of goodness
  
  /*
  * Update the PID error variables given cross track error.
  */
  double UpdateError(double cte);
  
  

  /*
  * Calculate the total PID error.
  */
  double TotalError();

	
	//These variables are for a function that I can't get to work correctly yet...
	//int	 lapNum;
	//int	 newLap;
	//double rightTurnSum;
	//int UpdateLap(double steering_angle);
  
  
};

#endif /* PID_H */
