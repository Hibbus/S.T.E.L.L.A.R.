#ifndef STAR_H
#define STAR_H

#include <string>
using namespace std;

class Star
{
	private:
		
		 double MEAN_DISTANCE_TO_BLACK_HOLE = (26673/* (Admin, 2022) light-years */ * 9.4607E+12/*km per light - year*/ * 1000/*meters per km.*/);
		 double UNCERTAINTY_ON_DISTANCE = (42/*(Admin, 2022) light-years */ * 9.4607E+12/*km per light-year*/ * 1000/*meters per km.*/);
		 double PI = 3.1415926;
		 double G = 6.67430E-11; //N*(m^2/kg^2) (Morrison et al, 2022)
		 double Ms = 1988500E+24;//(Williams,n.d) kg. Solar mass. When working with values this large, the approximation of Ms=2E+30 introduces needless uncertainty.



	public:

		string name;
	
		//these variables have to have their values set by the read function. Therefore, they are public. 
		
		double smaAngular=0;

		double uncertaintySmaAngular=0;

		double massSgrA=0;
	
		double uncertaintyMassSgrA=0;

		double period=0;

		double uncertaintyPeriod=0;

		double calculateMass() const;

		double calculateUncertainty() const;
};

#endif
