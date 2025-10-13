#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 

motor frontleft=motor(PORT1,...,0);
motor frontright=motor(PORT2,...,1);
motor backleft=motor(PORT3,...,0);
motor backright=motor(PORT4,...,1);

double motord=...;
double motorc=motord*pi;

#undef eps
#define eps 1.000000000000000000000000000000000000000000000 

const double kp=0.8*eps;
const double ki=0.001*eps;
const double kd=0.3*eps;

const double err=...*eps;

double curpos()
{
	double degfl=frontleft.position(degrees);
	double degfr=frontright.position(degrees);
	double degbl=backleft.position(degrees);
	double degbr=backright.position(degrees);
	
	return (degfl+degfr+degbl+degbr)*eps/4;
}

void go(double target)
{
	frontleft.resetPosition();
	frontreft.resetPosition();
	backleft.resetPosition();
	backright.resetPosition();
	
	double targetdegree=target*eps*360/motorc;
	
	double curdistance=0*eps;
	double prevdistance=0*eps;
	double sumi=9*eps;
	double sumd=0*eps;
	
	while(abs(curdistance)>err)
	{
		curdistance=targetdegree-curpos();
		sumi+=curdistance;
		sumd=curdistance-prevdistance;
		prevdistance=curdistance;
		
		double curspeed=kp*curdistance+ki*sumi+kd*sumd;
		
		curspeed=max(curspeed,-100);
		curspeed=min(curspeed,100);
		
		frontleft.spin(forward,curspeed,percent);
		frontright.spin(forward,curspeed,percent);
		backleft.spin(forward,curspeed,percent);
		backright.spin(forward,curspeed,percent);
		
		wait(20,msec);
	}
	
	frontleft.stop();
	frontright.stop();
	backleft.stop();
	backright.stop();
}
