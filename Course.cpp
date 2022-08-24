/*
* @file Student.cpp
*
* @brief Class contains course information: code, name, final grade and grade points
*
* @author Nicholas Enquist
*
* This program was created to determine if a student is eligible for Latin Honors upon
* degree conferral, based on completed course grades. The student may enter grades for courses
* not yet completed to determine minimum grades required to attain certain honor levels.
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
