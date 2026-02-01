//Miguel Monteiro-Thibault.

// Supermassive black hole Terminal based mass Estimator through Local Luminary Apparent Revolutions.
// 
// This program will calculate the mass of the supermassive black hole Sagittarius A* (also called Sgr A*) at the center 
// of the Milky-Way galaxy using the orbital information of the stars in the Sagittarius A* star cluster 
// who have had their orbits mapped out. By using a modified version of Kepler's Law, a value of the mass of Sagittarius A* can be 
// generated for every star inputted into the database. These values will then be averaged and output in the uncertainty format:
// Mass of Sgr A* = XXXX � YYYY solar masses

#include "Star.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//dual-purpose function. Bool value dictates whether the data gathered is printed to the screen (if the user chooses that option)
//or if the data gathered is forwarded to the calculation functions which calculate the mass of Sagittarius A*.
// 1: data is printed; 0: data is forwarded to function.
// 
//continue flag. If the user chooses not to have the uncertainty calculated, then that function will not be calculated. 
//0: uncertainty NOT calculated; 1: uncertainty calculated.
void read(bool print, bool uncertaintyCalcFlag);

//function which searches and sorts the printed data table. 
void searchAndSort(Star stars[]);
//sorting and searching functions
	void linearSearch(Star stars[]);
	void selectionSort(Star stars[]);

//runs the calculation class member functions.
void runCalc(Star stars[], bool uncertaintyCalcFlag);

void displayAttributions();

//this function displays the results to the user.
int showResults(Star stars[],bool uncertaintyCalcFlag);

const double NUMSTARS = 39; //The number of stars that the program will consider.

int main()
{
	char ch; // menu selection character
	while (true)
	{
		//menu section
		{
			cout << "\x1B[31m" << "\n"; // makes the color of the main menu red because it makes it more pleasing to look at.

			// this is the main menu of the program and asks the user what they would like to do.
			cout << "Welcome to the:\n";
			cout << "Supermassive black hole Terminal-based mass Estimator through Local Luminary Apparent Revolutions.\n";
			cout << "What would you like to do?\n";
			cout << "1 - Print the data table from which the program gathers data.\n";
			cout << "2 - Calculate mass with uncertainty!\n";
			cout << "3 - Calculate the median mass only!\n";
			cout << "4 - Show attributes and citations\n";
			cout << "5 - Quit the program\n";
			cout << "Enter a number 1-5 to make your choice:\n";

			cout << "\x1B[0m"; // this makes the rest of the program have the regular terminal color.

		}

		cin >> ch;

		switch (ch)
		{

		case '1': read(1,0); // summons the function which prints the data from which the program runs.
			break;

		case '2': read(0,1);// summons the meat-and-potatoes of the program. The part that calculates the mass of the supermassive black hole Sgr A* WITH uncertainty.
			break;

		case '3': read(0,0);// summons the same function as above, but in a way that will NOT continue on to calculate the uncertainty.
			break;

		case '4': displayAttributions();
			break;

		case '5': exit(0);
			break;

		default: cout << "Please enter a valid selection. Enter a number 1-5 to make your choice" << endl;

		}

	}

}

void displayAttributions()
{
	cout << "\n\n";

	ifstream read;
	read.open("references.txt");

	string line;

	while (getline(read, line)) //getline outputs the value "true" when a value is read. This loop continues to read until no values are left.
	{
		cout << line << "\n";
	}
	cout << "\n\n";

	read.close(); //always close files
}

void read(bool print, bool uncertaintyCalcFlag)
{
	Star stars[39];

	ifstream read;

	read.open("info.dat");

	if (print == true)
	{
	cout << "Name    Angular semi-major axis (arc-sec)    uncertainty(arc-sec)    Period of orbit (years)    Uncertainty(years)\n"; //this prints a useful label at the top of the console as the values read get printed to the user.
	}

	for (int count = 0; count < NUMSTARS; count++)
	{
		//the section which reads from the file
		{
			//read the star name from the file and then output it.
			read >> stars[count].name;

			//Idea for using the seekg command from (Input/output with files n.d)
			//the seekg command changes the location of the read cursor within the file. the argument 3 specifies six bytes to the right. The "ios::cur" specifies
			//that the read cursor be moved six bytes to the right of wherever it currently is. If this were not there, the cursor would always go to 3 bytes from the beginning of the file.

			read >> stars[count].smaAngular;

			read >> stars[count].uncertaintySmaAngular;

			//The seek command is needed here because we are not reading the subsequent entry in the file. We need to move the read cursor many bytes over.

			read.seekg(69, ios::cur);
			read >> stars[count].period;


			read >> stars[count].uncertaintyPeriod;

			// this portion skips to the beginning of the next line, so that the next star can be read.
			string line;
			getline(read, line);

		}
			if (print == true)
			{
				cout << stars[count].name; cout << setw(25) << stars[count].smaAngular; cout << setw(25) << stars[count].uncertaintySmaAngular;
				cout << setw(25) << stars[count].period; cout << setw(25) << stars[count].uncertaintyPeriod << endl;
			}

		
	}
	//once the read loop is over//

	if (print == false)
	{
		runCalc(stars, uncertaintyCalcFlag);
	}
	else if (print == true)
	{
		char ch;
		do 
		{
			cout << " would you like to sort or search the data table? enter \"y\" for yes or \"n\" for no" << endl;
			cin >> ch;

			if (ch == 'y')
			{
				searchAndSort(stars);
			}
			else if (ch == 'n')
			{
				return;
			}
				
		
		}while (!(ch == 'y' || ch == 'n'));
	}
}

void searchAndSort(Star stars[])
{
	string str;
	do {

		cout << "Type \"search\" if you would like to search for a specific star. Type \"sort\" to sort the table." << endl;

		cin >> str;

		if (str == "search")
		{
			linearSearch(stars);
		}

		if (str == "sort")
		{
			selectionSort(stars);
		}
	}while (!(str == "search" || str == "sort"));
}

void linearSearch(Star stars[])
{
	char repeatCh;
	do
	{
		//linear search because the array is not sorted.
		string searchString;

		cout << "Enter the name of the star you would like to search for:" << endl;

		//get the whole line
		cin >> searchString;

		int pos = -1;
		bool found = 0;
		for (int index = 0; (index < NUMSTARS) && (found == 0); index++)
		{
			if (stars[index].name == searchString)
			{
				found = true;
				pos = index;

				cout << "Name    Angular semi-major axis (arc-sec)    uncertainty(arc-sec)    Period of orbit (years)    Uncertainty(years)\n"; //this prints a useful label at the top of the console as the values read get printed to the user.

				cout << stars[pos].name; cout << setw(25) << stars[pos].smaAngular; cout << setw(25) << stars[pos].uncertaintySmaAngular;
				cout << setw(25) << stars[pos].period; cout << setw(25) << stars[pos].uncertaintyPeriod << endl;

			}

		}
		if (found == 0)
		{
			cout << "That star was not located in the table.\n";
		}
		cout << "Would you like to search again? ";

		do
		{
			cout << "Enter \"y\" for yes and \"n\" for no.\n";
			cin >> repeatCh;

			if (repeatCh == 'n')
			{
				return;
			}

		} while (!(repeatCh == 'y') || !(repeatCh == 'n'));


	} while (repeatCh == 'y');

}

void selectionSort(Star stars[])
{

	char repeat;do
	{
		cout << "Would you like to sort by semi-major axis, semi-major axis uncertainty, period of orbit or uncertainty of the period of the orbit?\n"
			<< "type \"A\", \"AU\", \"P\", or \"PU\" to choose the options respectively.\n";

		char ch;
		do
		{
			cin >> ch;
			switch (ch)
			{
			case'A':
			{
				//******************************************************************************
				//SORT BY SMA ANGULAR
				int minIndex; double minValue;
				for (int start = 0; start < (NUMSTARS - 1); start++)
				{
					minIndex = start; minValue = stars[start].smaAngular;
					for (int index = start + 1; index < NUMSTARS; index++)
					{
						if (stars[index].smaAngular < minValue)
						{
							minValue = stars[index].smaAngular;
							minIndex = index;
						}
					}
					swap(stars[minIndex], stars[start]);
				}}
			break;
			//******************************************************************************

			case'AU':
			{
				//******************************************************************************
				//SORT BY SMA ANGULAR UNCERTAINTY
				int minIndex; double minValue;
				for (int start = 0; start < (NUMSTARS - 1); start++)
				{
					minIndex = start; minValue = stars[start].uncertaintySmaAngular;
					for (int index = start + 1; index < NUMSTARS; index++)
					{
						if (stars[index].uncertaintySmaAngular < minValue)
						{
							minValue = stars[index].uncertaintySmaAngular;
							minIndex = index;
						}
					}
					swap(stars[minIndex], stars[start]);
				}}
			break;
			//******************************************************************************

			case'P':
			{
				//******************************************************************************
				//SORT BY PERIOD OF ORBIT
				int minIndex; double minValue;
				for (int start = 0; start < (NUMSTARS - 1); start++)
				{
					minIndex = start; minValue = stars[start].period;
					for (int index = start + 1; index < NUMSTARS; index++)
					{
						if (stars[index].period < minValue)
						{
							minValue = stars[index].period;
							minIndex = index;
						}
					}
					swap(stars[minIndex], stars[start]);
				}}
			break;
			//******************************************************************************

			case'PU':
			{
				//******************************************************************************
				//SORT BY ORBITAL PERIOD UNCERTAINTY.
				int minIndex; double minValue;
				for (int start = 0; start < (NUMSTARS - 1); start++)
				{
					minIndex = start; minValue = stars[start].uncertaintyPeriod;
					for (int index = start + 1; index < NUMSTARS; index++)
					{
						if (stars[index].uncertaintyPeriod < minValue)
						{
							minValue = stars[index].uncertaintyPeriod;
							minIndex = index;
						}
					}
					swap(stars[minIndex], stars[start]);				
				}}
			break;
			//******************************************************************************


			default: cout << "Invalid selection";
				break;
			}

		} while (!((ch == 'A') || (ch == 'AU') || (ch == 'P') || (ch == 'PU')));

		//output sorted table. 

		cout << "Name    Angular semi-major axis (arc-sec)    uncertainty(arc-sec)    Period of orbit (years)    Uncertainty(years)\n"; //this prints a useful label at the top of the console as the values read get printed to the user.

		for (int count = 0; count < NUMSTARS; count++)
		{
			cout << stars[count].name; cout << setw(25) << stars[count].smaAngular; cout << setw(25) << stars[count].uncertaintySmaAngular;
			cout << setw(25) << stars[count].period; cout << setw(25) << stars[count].uncertaintyPeriod << endl;
		}


		cout << "Would you like to sort again? enter \"y\" for yes or \"n\" for no" << endl;

		do
		{
			cin >> repeat;

			if (repeat == 'y')
			{
				break;
			}
			else if (repeat == 'n')
			{
				return;
			}
			else
			{
				cout << "Invalid entry\n";
			}
		} while (!(repeat == 'y' || repeat == 'n'));
	}while (repeat == 'y');

}


// this function will use a for loop to run through the star data array, activating every object's "calculate mass" function and, if the user requested
// to calculate uncertainty, the "calculateUncertainty" function as well.
void runCalc(Star stars[], bool uncertaintyCalcFlag)
{
	for (int count = 0; count < NUMSTARS; count++)
	{
		stars[count].massSgrA=stars[count].calculateMass();
		
		if (uncertaintyCalcFlag == true)
		{
			stars[count].uncertaintyMassSgrA=stars[count].calculateUncertainty();
		}
	}

	showResults(stars, uncertaintyCalcFlag);
}



int showResults(Star stars[], bool uncertaintyCalcFlag)
{
	cout << endl << "star:				Mass of Sgr A* (Msolar):			";
	if (uncertaintyCalcFlag == true)
	{
		cout<<"Uncertainty on Mass of Sgr A * (Msolar) : " << endl;
	}
	else { cout << endl; }
	double sumOfMedianMass=0; double sumOfMassUncertainty=0; double finalMass; double finalUncertainty;

	for (int count = 0; count < NUMSTARS; count++)
	{

		sumOfMedianMass += stars[count].massSgrA;

		cout << stars[count].name << "				" << stars[count].massSgrA << "					";



		if (uncertaintyCalcFlag == true)
		{
			sumOfMassUncertainty += stars[count].uncertaintyMassSgrA;
			cout << stars[count].uncertaintyMassSgrA << endl;
		}
		else
		{
			cout << endl;
		}


	}

	finalMass = (sumOfMedianMass / NUMSTARS);

	//values cast to float type so that they may have the "setprecision" stream modifier added to them.

	if (uncertaintyCalcFlag == true)
	{
		finalUncertainty = (sumOfMassUncertainty /NUMSTARS);

		cout << setprecision(2);

		cout << "The median mass of Sagittarius A* was calculated to be: "<< finalMass << " solar masses with an uncertainty of " << finalUncertainty << " solar masses.\n";
		return(1);

	}

	cout << "The median mass of Sagittarius A* was calculated to be: " <<setprecision(5)<< finalMass << " solar masses\n";
	return(0);

}
