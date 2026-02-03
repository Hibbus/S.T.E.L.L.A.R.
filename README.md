Hello all users!
	Thank you for using S.T.E.L.L.A.R.! S.T.E.L.L.A.R. is an abbreviation of 
Supermassive black hole Terminal-based mass Estimator through Local Luminary Apparent Revolutions.  The purpose of this program is to permit users to calculate the mass of Sagittarius A* using many stars. This modular program uses multiple files to aid in the working of the file.

This program relies on the use of Kepler’s third law. Kepler’s third law is a way of describing the orbit of a smaller body around a parent body. As it turns out, this is greatly beneficial. Since supermassive black holes, such as Sagittarius A* at the center of the Milky-Way galaxy, are extremely hard to directly observe, it is easier to observe the orbits of some nearby stars and their properties as they orbit the black hole. 

<img width="1128" height="324" alt="image" src="https://github.com/user-attachments/assets/60dfdf4d-bff1-408e-a416-f332df5a07da" />


A study of some 39 stars orbiting Sagittarius A*  was used as the basis for this program, however the modular nature of the program means that it is extremely simple to expand the amount of stars being studied.

# How Does the Program Work?
S.T.E.L.L.A.R. Works quite simply by accessing a table of stellar orbital information gathered from stars within close distance of Sgr. A* such that we can measure their orbits. 
```
S1     0.595  0.024  0.556  0.018  119.14 0.21 342.04  0.32 122.3   1.4  2001.80   0.15  166.0     5.8  e 14.7  1.75 
S2     0.1255 0.0009 0.8839 0.0019 134.18 0.40 226.94  0.60  65.51  0.57 2002.33   0.01   16.00    0.02 e 13.95 1.13 
S4     0.3570 0.0037 0.3905 0.0059  80.33 0.08 258.84  0.07 290.8   1.5  1957.4    1.2    77.0     1.0  e 14.4  1.25 
S6     0.6574 0.0006 0.8400 0.0003  87.24 0.06  85.07  0.12 116.23  0.07 2108.61   0.03  192.0     0.17 e 15.4  1.58 
S8     0.4047 0.0014 0.8031 0.0075  74.37 0.30 315.43  0.19 346.70  0.41 1983.64   0.24   92.9     0.41 e 14.5  1.18 
S9     0.2724 0.0041 0.644  0.020   82.41 0.24 156.60  0.10 150.6   1.0  1976.71   0.92   51.3     0.70 e 15.1  1.65 
S12    0.2987 0.0018 0.8883 0.0017  33.56 0.49 230.1   1.8  317.9   1.5  1995.59   0.04   58.9     0.22 e 15.5  2.37 
S13    0.2641 0.0016 0.4250 0.0023  24.70 0.48  74.5   1.7  245.2   2.4  2004.86   0.04   49.00    0.14 e 15.8  3.25 
S14    0.2863 0.0036 0.9761 0.0037 100.59 0.87 226.38  0.64 334.59  0.87 2000.12   0.06   55.3     0.48 e 15.7  2.16 
S17    0.3559 0.0096 0.397  0.011   96.83 0.11 191.62  0.21 326.0   1.9  1991.19   0.41   76.6     1.0  l 15.3  3.00 
S18    0.2379 0.0015 0.471  0.012  110.67 0.18  49.11  0.18 349.46  0.66 1993.86   0.16   41.9     0.18 e 16.7  2.28 
S19    0.520  0.094  0.750  0.043   71.96 0.35 344.60  0.62 155.2   2.3  2005.39   0.16  135.     14.   e 16.   2.57 
S21    0.2190 0.0017 0.764  0.014   58.8  1.0  259.64  0.62 166.4   1.1  2027.40   0.17   37.00    0.28 l 16.9  1.60 
S22    1.31   0.28   0.449  0.088  105.76 0.95 291.7   1.4   95.   20.   1996.9   10.2   540.     63.   e 16.6  2.78 
S23    0.253  0.012  0.56   0.14    48.0  7.1  249.   13.    39.0   6.7  2024.7    3.7    45.8     1.6  e 17.8  2.08 
S24    0.944  0.048  0.8970 0.0049 103.67 0.42   7.93  0.37 290.   15.   2024.50   0.03  331.     16.   l 15.6  1.54 
S29    0.428  0.019  0.728  0.052  105.8  1.7  161.96  0.80 346.5   5.9  2025.96   0.94  101.0     2.0  e 16.7  3.32 
S31    0.449  0.010  0.5497 0.0025 109.03 0.27 137.16  0.30 308.0   3.0  2018.07   0.14  108.      1.2  e 15.7  3.16 
S33    0.657  0.026  0.608  0.064   60.5  2.5  100.1   5.5  303.7   1.6  1928.    12.    192.0     5.2  e 16.   2.21 
S38    0.1416 0.0002 0.8201 0.0007 171.1  2.1  101.06  0.24  17.99  0.25 2003.19   0.01   19.2     0.02 l 17.   2.48 
S39    0.370  0.015  0.9236 0.0021  89.36 0.73 159.03  0.10  23.3   3.8  2000.06   0.06   81.1     1.5    16.8  3.27 
S42    0.95   0.18   0.567  0.083   67.16 0.66 196.14  0.75  35.8   3.2  2008.24   0.75  335.     58.   e 17.5  1.65 
S54    1.20   0.87   0.893  0.078   62.2  1.4  288.35  0.70 140.8   2.3  2004.46   0.07  477.    199.   e 17.5  2.60 
S55    0.1078 0.0010 0.7209 0.0077 150.1  2.2  325.5   4.0  331.5   3.9  2009.34   0.04   12.80    0.11   17.5  1.61 
S60    0.3877 0.0070 0.7179 0.0051 126.87 0.30 170.54  0.85  29.37  0.29 2023.89   0.09   87.1     1.4  e 16.3  1.65 
S66    1.502  0.095  0.128  0.043  128.5  1.6   92.3   3.2  134.   17.   1771.    38.    664.     37.   e 14.8  1.70 
S67    1.126  0.026  0.293  0.057  136.0  1.1   96.5   6.4  213.5   1.6  1705.    22.    431.     10.   e 12.1  1.43 
S71    0.973  0.040  0.899  0.013   74.0  1.3   35.16  0.86 337.8   4.9  1695.    21.    346.     11.   e 16.1  1.87 
S83    1.49   0.19   0.365  0.075  127.2  1.4   87.7   1.2  203.6   6.0  2046.8    6.3   656.     69.   e 13.6  1.82 
S85    4.6    3.30   0.78   0.15    84.78 0.29 107.36  0.43 156.3   6.8  1930.2    9.8  3580.   2550.   l 15.6  1.50 
S87    2.74   0.16   0.224  0.027  119.54 0.87 106.32  0.99 336.1   7.7   611.   154.   1640.    105.   e 13.6  1.38 
S89    1.081  0.055  0.639  0.038   87.61 0.16 238.99  0.18 126.4   4.0  1783.    26.    406.     27.   l 15.3  1.16 
S91    1.917  0.089  0.303  0.034  114.49 0.32 105.35  0.74 356.4   1.6  1108.    69.    958.     50.   e 12.2  1.33 
S96    1.499  0.057  0.174  0.022  126.36 0.96 115.66  0.59 233.6   2.4  1646.    16.    662.     29.   e 10.   1.31 
S97    2.32   0.46   0.35   0.11   113.0  1.3  113.2   1.4   28.   14.   2132.    29.   1270.    309.   e 10.3  1.22 
S145   1.12   0.18   0.50   0.25    83.7  1.6  263.92  0.94 185.   16.   1808.    58.    426.     71.   l 17.5  1.46 
S175   0.414  0.039  0.9867 0.0018  88.53 0.60 326.83  0.78  68.52  0.40 2009.51   0.01   96.2     5.0  e 17.5  2.72 
R34    1.81   0.15   0.641  0.098  136.0  8.3  330.   19.    57.0   8.0  1522.    52.    877.     83.   e 14.   1.35 
R44    3.9    1.4    0.27   0.27   131.0  5.2   80.5   7.1  217.   24.   1963.    85.   2730.   1350.   e 14.   1.11 

Title: An Update on Monitoring Stellar Orbits in the Galactic Center 
Authors: Gillessen S., Plewa P.M., Eisenhauer F., Sari R., Waisberg I., 
         Habibi M., Pfuhl O., George E., Dexter J., von Fellenberg S., Ott T., 
         Genzel R. 
Table: Orbital parameters of the 40 stars for which we were able to determine orbits
================================================================================
Byte-by-byte Description of file: apjaa5c41t3_mrt.txt
--------------------------------------------------------------------------------
   Bytes Format Units     Label    Explanations
--------------------------------------------------------------------------------
   1-  4 A4     ---       Star     Star Name
   6- 13 F8.4   arcsec    a        semi-major axis of the orbit, from Sag A* (1)
  15- 20 F6.4   arcsec  e_a        Uncertainty in a
  22- 27 F6.4   ---       e        eccentricity (1)
  29- 34 F6.4   ---     e_e        Uncertainty in e
  36- 41 F6.2   deg       i        inclination
  43- 46 F4.2   deg     e_i        Uncertainty in i
  48- 53 F6.2   deg       {Omega}  position angle of the ascending node
  55- 59 F5.2   deg     e_{Omega}  Uncertainty in {Omega}
  61- 66 F6.2   deg       w        longitude of the pericenter
  68- 72 F5.2   deg     e_w        Uncertainty in w
  74- 80 F7.2   yr        Tp       epoch of pericenter passage, fractional year (2)
  82- 87 F6.2   yr      e_Tp       Uncertainty in Tp
  89- 95 F7.2   yr        Per      ?="" Orbital period (1, 2)
  97-103 F7.2   yr      e_Per      ?="" Uncertainty in Per
 105-105 A1     ---       SpT      [el] spectral type. 'e': early-type stars,
                                    'l': late-type stars
 107-111 F5.2   mag       Kmag     K-band magnitude
 113-116 F4.2   ---       r        Global rescaling factor
--------------------------------------------------------------------------------
Note (1): Object S111 formally has a negative semi major axis, indicative for 
    a hyperbolic orbit with e > 1 and no solution for an orbital period.
Note (2): Time is measured in Julian years of 365.25 days since J2000.0. 
--------------------------------------------------------------------------------
```
This table displays many different pieces of information for each star. S.T.E.L.L.A.R. however only needs to read semi-major axis, orbital period and uncertainty of both those values. Unfortunately semi-major axis is given in arc-seconds which are transformed into linear measurements by S.T.E.L.L.A.R. using an accepted value for the distance of Earth to Sgr A*. The difference in distance between Earth and the stars was assumed to be negligibly different to that of Sgr A*.

The functions that allow S.T.E.L.L.A.R. to calculate mass and uncertainty are defined as class member functions of the *star* class, simplifying the main S.T.E.L.L.A.R. cpp file and improving readability.
```
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
```
This calculates the mass of Sgr A* relying on *one* of the stars in the data set. S.T.E.L.L.A.R. relies on an average value when displaying the information to the user.

The next job is to calculate mass uncertainty (once again for only one star, is averaged before output) which is a much more complicated affair. The uncertainty formula for the mass compounds with uncertainties elsewhere and therefore complex equations are needed. The uncertainty equation for Sgr A*'s mass appears as follows:

<img width="682" height="162" alt="image" src="https://github.com/user-attachments/assets/e7d7057e-6567-424a-af31-e28f87e0a8bb" />

Since the program cannot perform differential calculus the equation was simplified to:

<img width="926" height="206" alt="image" src="https://github.com/user-attachments/assets/21c8fee2-d5ff-4209-bad6-e8f968afef12" />

Which gives us our value!

After computing these values for each of the stars in the study the program is ready to output the average values which you can find a preview of below:

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/01071cd7-f653-4a8f-95f8-f9c93b6df8c8" />


Despite some outliers, we notice that the generated value is remarkably close to the real value! (4.154 million M⨀ compared to 4.2 million M⨀). We only really lack precision due to loss of sig figs throughout calculation.
Uncertainty values are large (1.2 million M⨀) and due to lack of precision in data. Through searching for more precise data, the generated values could be made more precise!

