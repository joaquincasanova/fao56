#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>

#define PI 3.1459265
#define boltz 4.903e-9// MJ K-4 m-2 day-1

using namespace std;

string filename = "072014BushlandH.csv";

class Daily{
public:
  Daily(void);
  ~Daily(void);

  int D;
  int M;
  int Y;
  double Tmax;//C
  double Tmin;//C
  double RHmax;//%
  double RHmin;//%
  double uz;//m/s
  double z;//m
  double ZZ;//m
  double lat;//deg
  double alb;
  double Kc;
  double Rnin;//MJ/m2/day

  double Rn(void){
    if(Rnin<0){
      return Rns()-Rnl();
      }else{
      return Rnin;
    };
  }

  double ET(void){return Kc*ET_o();}//mm

private:
  double Tmean(void){return (Tmin+Tmax)/2;} //degree C
  double u2(void){return uz*4.87/log(67.8*z-5.42);} //m/s, m
  double delta(void){return 4098*(0.6108*exp(17.27*Tmean()/(Tmean()+237.7)))/pow(Tmean()+273.3,2);} //kpa/C
  double P(void){return 101.3*pow(((293-0.0065*ZZ)/293),5.26);}//kpa, 
  double gamma(void){return 0.000665*P();}
  double DT(void){return delta()/(delta()+gamma()*(1+0.34*u2()));}
  double PT(void){return gamma()/(delta()+gamma()*(1+0.34*u2()));}
  double TT(void){return (900/(Tmean()+273))*u2();}
  double e_T(double T){return 0.6108*exp(17.27*T/(T+237.3));}
  double e_s(void){return (e_T(Tmin)+e_T(Tmax))/2;}
  double e_a(void){return (e_T(Tmin)*RHmax/100+e_T(Tmax)*RHmin/100)/2;}
  double ET_rad(void){return DT()*Rng();}
  double ET_wind(void){return PT()*TT()*(e_s()-e_a());}
  double ET_o(void){return ET_wind()+ET_rad();}

  int J(void){return D-32+(int)(275*M/9)+2*(int)(3/(M+1))+(int)(M/100-(Y%4)/4+0.975);}
  double dr(void){return 1+0.033*cos(2*PI/365*J());}
  double dec(void){return 0.409*sin(2*PI/365*J()-1.39);}
  double phi(void){return PI/180*lat;}
  double omega_s(void){return acos(-tan(phi())*tan(dec()));}
  double Rs(void){return 24*60/PI*0.0820*dr()*(omega_s()*sin(phi())*sin(dec())+sin(omega_s())*cos(phi())*cos(dec()));}
  double Rso(void){return (0.75+(2e-5)*ZZ)*Rs();}
  double Rns(void){return Rso()*(1.0-alb);}
  double Rnl(void){return boltz*(pow(Tmin+273.16,4)+pow(Tmax+273.16,4))/2*(0.34-0.14*sqrt(e_a()))*(1.35*Rs()/Rso()-0.35);}
  double Rng(void){return 0.408*Rn();}

};

Daily::Daily(void){
}

Daily::~Daily(void){
}

class Canopy{
public:
private:
};
double Canopy::CWSI(void){
  return (Tcan-Twet)/(Tdry-Twet);
}

double Canopy::Tdry(){
}

double Canopy::Twet(){
}

double Canopy::Tcan(){
}

double Canopy::fdhc(){
}

double Canopy::LAI(){
}

int main(void){

  Daily Day;

  cout << "D ";
  cin >> Day.D;
  cout << "M ";
  cin >> Day.M;
  cout << "Y ";
  cin >> Day.Y;
  cout << "Tmax ";
  cin >> Day.Tmax;//C
  cout << "Tmin ";
  cin >> Day.Tmin;//C
  cout << "RHmax ";
  cin >> Day.RHmax;//%
  cout << "RHmin ";
  cin >> Day.RHmin;//%
  cout << "uz ";
  cin >> Day.uz;//m/s
  cout << "z ";
  cin >> Day.z;//m
  cout << "ZZ ";
  cin >> Day.ZZ;//m
  cout << "lat ";
  cin >> Day.lat;//deg
  cout << "alb ";
  cin >> Day.alb;
  cout << "Kc ";
  cin >> Day.Kc;
  cout << "Rnin ";
  cin >> Day.Rnin;//
  cout << Day.Rn() << std::endl;
  cout << "ET " << std::endl; 
  cout << Day.ET() << std::endl;

  return 0;
}
