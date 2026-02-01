#include "Star.h"
#include <cmath>
#include <iostream>
using namespace std;

//these class member functions make the main body of the program less cramped and filled.
double Star::calculateMass() const
{
	double smaTEMP; //linear
	//in order to avoid possibly fudging up the data in the Star object, these functions are to be denoted as constants.
	//They cannot modify external data, so internal variables must be declared which can take the place of the external ones.
	double smaAngularTEMP, periodTEMP, massSgrATEMP;

	//Kepler's Law: M= ((4*(PI)^2)*(sma^3))/(G*(period^2))

	//unit conversions to get all values in SI units:

	smaAngularTEMP = (smaAngular / 3600)/*arc - seconds per degree*/ * (PI / 180);/*convert to radians*/
	smaTEMP = MEAN_DISTANCE_TO_BLACK_HOLE * tan(smaAngularTEMP); /*using trigonometry to find the linear semi-major axis.*/

	periodTEMP = period * 365/*days in a year*/ * 24/*hours per day*/ * 3600;/*seconds per hour*/

	 massSgrATEMP= ((4 * (pow(PI, 2)) * pow(smaTEMP, 3))) / ((G * (pow(periodTEMP, 2))));

	 massSgrATEMP = massSgrATEMP / Ms; //convert from kilograms to solar masses. Useful when dealing with values this large to have a reference.

	 return massSgrATEMP;
}

double Star::calculateUncertainty() const
{
	//temporary internal variables
	double smaAngularTEMP,uncertaintySmaAngularTEMP,periodTEMP,uncertaintyPeriodTEMP, massSgrATEMP,uncertaintyMassSgrATEMP;

	smaAngularTEMP = (smaAngular / 3600)/*arc - seconds per degree*/ * (PI / 180);/*convert to radians*/
	uncertaintySmaAngularTEMP = (uncertaintySmaAngular / 3600)/*arc - seconds per degree*/ * (PI / 180);/*convert to radians*/

	periodTEMP = (period * 365)/*days per year*/ * 24/*hours per day*/ * 60/*minutes per hour*/ * 60; /*seconds per minute*/
	uncertaintyPeriodTEMP = (uncertaintyPeriod * 365)/*days per year*/ * 24/*hours per day*/ * 60/*minutes per hour*/ * 60; /*seconds per minute*/

	//This function will use a calculus-based approach to calculate the uncertainty of the mass.

	double delA, delD, delT, uncertainty; //These variables will hold the partial derivatives of the equation for the mass of the black hole
	//with respect to the angular sma, distance to the black hole and period of the star's orbit respectively.

	delA = (pow(MEAN_DISTANCE_TO_BLACK_HOLE, 3) * (3 * pow(tan(smaAngularTEMP), 2)) * pow(pow(cos(smaAngularTEMP), -1), 2) / pow(periodTEMP, 2));

	delD = ((3 * pow(MEAN_DISTANCE_TO_BLACK_HOLE, 2)) * pow((tan(smaAngularTEMP)), 3)) / (pow(periodTEMP, 2));

	delT = (-2 * (MEAN_DISTANCE_TO_BLACK_HOLE * pow((tan(smaAngularTEMP)), 3))) / (pow(periodTEMP, 3));

	//uncertainty equals the square root of the sum of all partial derivatives squared multiplied by their uncertainties squared.
	//multiplied by the constant (4pi^2/G)

	uncertaintyMassSgrATEMP = ((4 * pow(PI, 2)) / G) * sqrt(pow((delA * uncertaintySmaAngularTEMP), 2) + pow((delD * UNCERTAINTY_ON_DISTANCE), 2) + pow((delT * uncertaintyPeriodTEMP), 2));

	uncertaintyMassSgrATEMP = uncertaintyMassSgrATEMP / Ms;// convert to solar masses.

	return (uncertaintyMassSgrATEMP);
}

