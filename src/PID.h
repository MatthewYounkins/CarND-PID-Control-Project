#ifndef PID_H
#define PID_H



class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double q_error;
  int	 lapNum;
  //int	 newLap;
  double rightTurnSum;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double fM;
  double Kq;
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
  void Init(double Kp, double Ki, double Kd, double fM, double Kq, int lapNum);

  /*
  * Update the PID error variables given cross track error.
  */
  double UpdateError(double cte);
  
  int UpdateLap(double steering_angle);
  
  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
