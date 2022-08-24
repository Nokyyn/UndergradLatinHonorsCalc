/*
* @file Student.cpp
*
* @brief Calculates Latin Honors from grades and GPA
*
* @author Nicholas Enquist
*
* This program was created to determine if a student is eligible for Latin Honors upon
* degree conferral, based on completed course grades. The student may enter grades for courses
* not yet completed to determine minimum grades required to attain certain honor levels.
*
* The Course class contains all relevant information for a single course,
* including the course code, course name, final grade earned in the course and total grade points obtained
*/



#include <string>

using namespace std;

class Course {
private:
	// Instantiate class fields
	string courseCode = "";
	string courseName = "";
	string finalGrade = "";
	double gradePoints = 0.0;

public:

	// Course constructor for setting all fields
	Course(string courseCode, string courseName, string finalGrade) {
		this->courseCode = courseCode;
		this->courseName = courseName;
		this->finalGrade = finalGrade;
		calculateGradePoints();
	}

	// Default, blank constructor
	Course() {}

	// Mutator and Accessor methods for class fields
	void setCourseCode(string courseCode) {
		this->courseCode = courseCode;
	}

	string getCourseCode() {
		return courseCode;
	}

	void setCourseName(string courseName) {
		this->courseName = courseName;
	}

	string getCourseName() {
		return courseName;
	}

	void setFinalGrade(string finalGrade) {
		this->finalGrade = finalGrade;
		calculateGradePoints();
	}

	string getFinalGrade() {
		return finalGrade;
	}

	// Use final grade to calculate grade points
	void calculateGradePoints() {
		/*if ((finalGrade >= 93) && (finalGrade <= 100)) {
			gradePoints = 4.0;
		}
		else if ((finalGrade >= 90) && (finalGrade <= 92)) {
			gradePoints = 3.67;
		}
		else if ((finalGrade >= 87) && (finalGrade <= 89)) {
			gradePoints = 3.33;
		}
		else if ((finalGrade >= 83) && (finalGrade <= 86)) {
			gradePoints = 3.0;
		}
		else if ((finalGrade >= 80) && (finalGrade <= 82)) {
			gradePoints = 2.67;
		}
		else if ((finalGrade >= 77) && (finalGrade <= 79)) {
			gradePoints = 2.33;
		}
		else if ((finalGrade >= 73) && (finalGrade <= 76)) {
			gradePoints = 2.0;
		}
		else if ((finalGrade >= 70) && (finalGrade <= 72)) {
			gradePoints = 1.67;
		}
		else if ((finalGrade >= 67) && (finalGrade <= 69)) {
			gradePoints = 1.33;
		}
		else if ((finalGrade >= 60) && (finalGrade <= 66)) {
			gradePoints = 1.0;
		}
		else {
			gradePoints = 0.0;
		}
		*/

		if ((finalGrade.compare("A") == 0) || (finalGrade.compare("a") == 0)) {
			gradePoints = 4.0;
		}
		else if ((finalGrade.compare("A-") == 0) || (finalGrade.compare("a-") == 0)) {
			gradePoints = 3.67;
		}
		else if ((finalGrade.compare("B+") == 0) || (finalGrade.compare("b+") == 0)) {
			gradePoints = 3.33;
		}
		else if ((finalGrade.compare("B") == 0) || (finalGrade.compare("b") == 0)) {
			gradePoints = 3.0;
		}
		else if ((finalGrade.compare("B-") == 0) || (finalGrade.compare("b-") == 0)) {
			gradePoints = 2.67;
		}
		else if ((finalGrade.compare("C+") == 0) || (finalGrade.compare("c+") == 0)) {
			gradePoints = 2.33;
		}
		else if ((finalGrade.compare("C") == 0) || (finalGrade.compare("c") == 0)) {
			gradePoints = 2.0;
		}
		else if ((finalGrade.compare("C-") == 0) || (finalGrade.compare("c-") == 0)) {
			gradePoints = 1.67;
		}
		else if ((finalGrade.compare("D+") == 0) || (finalGrade.compare("d+") == 0)) {
			gradePoints = 1.33;
		}
		else if ((finalGrade.compare("D") == 0) || (finalGrade.compare("d") == 0)) {
			gradePoints = 1.0;
		}
		else {
			gradePoints = 0.0;
		}
		
	}

	double getGradePoints() {
		return gradePoints;
	}

};