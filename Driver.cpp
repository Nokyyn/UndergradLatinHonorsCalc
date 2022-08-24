/*
* @file Driver.cpp
*
* @brief Calculates Latin Honors from grades and GPA
*
* @author Nicholas Enquist
*
* This program was created to determine if a student is eligible for Latin Honors upon
* degree conferral, based on completed course grades. The student may enter grades for courses
* not yet completed to determine minimum grades required to attain certain honor levels.
*/

#include "HonorsCalculator.cpp"

int main() {
	
	HonorsCalculator calc;
	calc.runCalculator();

	return 0;
}