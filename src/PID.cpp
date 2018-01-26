#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_i, double Ki_i, double Kd_i) {
	Kp=Kp_i;
	Ki=Ki_i;
	Kd=Kd_i;

	p_error=0;
	i_error=0;
	d_error=0;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	cout<<"P: "<<Kp*p_error<<endl;
	cout<<"I: "<<Ki*i_error<<endl;
	cout<<"D: "<<Kd*d_error<<endl;
	return Kp*p_error + Ki*i_error + Kd*d_error;
}

