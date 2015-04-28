#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

FILE *fid;
string filename = "072014BushlandH.csv";

int readData(){
	fid = fopen(filname,r);
	while(fscanf()){}
}

class Daily{
public:
  Daily(void);
  ~Daily(void);
  double ET(void);//mm
  double Rn;
  double Tmax;
  double Tmin;
  double RHmax;
  double RHmin;
  double uz;
  double z;
  double ZZ;
private:
  double Tmean(void){return (Tmin+Tmax)/2;} //degree C
  double u2(void){return uz*4.87/log(67.8*z-5.42)}; //m/s, m
  double delta(void){return 4098*(0.6108*exp(17.27*Tmean()/(Tmean()+237.7)))/(Tmean()+273.3)^2;} //kpa/C
  double P(void){return 101.3*((293-0.0065*ZZ)/293)^5.26;}//kpa, m
  double gamma(void){return 0.000665*P;}
  double DT(void){return delta/(delta+gamma*(1+0.34*u2));}
  double PT(void){return gamma/(delta+gamma*(1+0.34*u2));}
  double TT(void){return (900/(Tmean+273))*u2;}
  double e_T(double T){return 0.6108*exp(17.27*T/(T+237.3));}
  double e_s(void){return (e_T(Tmin)+e_T(Tmax))/2;}
  double e_a(void){return (e_T(Tmin)*RHmax/100+e_T(Tmax)*RHmin/100)/2;}
  
}
Daily::Daily(void){
}
Daily::~Daily(void){
}
Daily::ET(void){
}
void main(){
}
