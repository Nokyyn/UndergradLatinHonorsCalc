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
* Student class contains all relevant information for a single student
* Including name, school name, all courses completed and current GPA
*/

#include <string>
#include <vector>
#include "Course.cpp"

using namespace std;

class Student {
private:
	string studentName = "";
	string schoolName = "";
	vector<Course> courses;
	double GPA = 0.0;
	double totalGradePoints = 0.0;
	int numCoursesCompleted = 0;

public:

	// Mutator and Accessor methods for class fields
	void setStudentName(string studentName) {
		this->studentName = studentName;
	}

	string getStudentName() {
		return studentName;
	}

	void setSchoolName(string schoolName) {
		this->schoolName = schoolName;
	}

	string getSchoolName() {
		return schoolName;
	}

	// Adds a course to the student's course vector and updates their current GPA
	void addCourse(Course course) {
		courses.push_back(course);
		
		totalGradePoints += course.getGradePoints();
		numCoursesCompleted++;
		GPA = totalGradePoints / numCoursesCompleted;
	}

	// Remove a course from the course vector and updates GPA
	void removeCourse(string courseCode) {
		for (unsigned int i = 0; i < courses.size(); i++) {
			if (courses.at(i).getCourseCode().compare(courseCode) == 0) {
				totalGradePoints -= courses.at(i).getGradePoints();
				numCoursesCompleted--;

				// If numCoursesCompleted would result in dividing by 0, set GPA to 0.0
				if (numCoursesCompleted > 0) {
					GPA = totalGradePoints / numCoursesCompleted;
				}
				else {
					GPA = 0.0;
				}
								courses.erase(courses.begin() + i);
			}
		}
	}

	vector<Course> getCourses() {
		return courses;
	}

	double getGPA() {
		return GPA;
	}
};