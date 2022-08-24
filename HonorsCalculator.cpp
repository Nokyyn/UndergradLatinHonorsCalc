/*
* @file HonorsCalculator.cpp
* 
* @brief Calculates Latin Honors from grades and GPA
* 
* @author Nicholas Enquist
* 
* This program was created to determine if a student is eligible for Latin Honors upon
* degree conferral, based on completed course grades. The student may enter grades for courses
* not yet completed to determine minimum grades required to attain certain honor levels.
* 
* Use the "Save student information" option to save all currently entered information to a text file,
* including: Student Name, School Name, Courses entered
* 
* "Returning Users" must enter their name exactly as it was originally entered, case insensitive, which will 
* attempt to load their saved information
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Student.cpp"

using namespace std;

class HonorsCalculator {
private:
	Student student;
	vector<string> honors = { "None", "Cum Laude", "Magna Cum Laude", "Summa Cum Laude" };
	string filename;
	bool isRunning = true;
	bool setupComplete = false;

public:

	// Run initial setup
	void welcomeSetup() {
		string studentName;
		string schoolName;
		int userOption = 0;

		while (!setupComplete) {
			cout << "==========================================================" << endl;
			cout << "Welcome to the Undergraduate University Honors Calculator!" << endl;
			cout << "==========================================================" << endl << endl;
			cout << "1: New Student" << endl;
			cout << "2: Returning Student" << endl << endl;
			cout << "Please make a selection: ";
			cin >> userOption;
			if (cin) {
				switch (userOption) {
				
					// New User: Get student and school names
				case 1:
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Please enter the student's name: ";
					getline(cin, studentName);
					cout << "Please enter the name of the school: ";
					getline(cin, schoolName);

					student.setStudentName(studentName);
					student.setSchoolName(schoolName);
					setupComplete = true;
					break;

					// Returning User: Get student name and attempt to read from that student's saved text file
				case 2:
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Please enter the student's name: ";
					getline(cin, studentName);
					filename = studentName + " Honors Evaluation.txt";
					if (loadStudentData(filename)) {
						setupComplete = true;
					}
					system("CLS");
					break;

				default:
					cout << "Invalid selection!" << endl;
					system("PAUSE");
					system("CLS");
					break;

				}
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input!" << endl;
				system("PAUSE");
				system("CLS");
			}

		}
		

	}

	// load returning student's data from saved text file
	bool loadStudentData(string filename) {
		vector<string> lines;
		string line;

		// Attempt to open file
		ifstream inputFile(filename);
		if (!inputFile.is_open()) {  // Report an error if file fails to open
			std::cerr << "Could not open file - '" << filename << "'" << endl;
			system("PAUSE");
			return false;
		}

		// Read each line from the file and store it in a string vector
		while (getline(inputFile, line)) {
			lines.push_back(line);
		}

		// Close the file
		inputFile.close();

		// Populate student information
		student.setStudentName(lines.at(0));
		student.setSchoolName(lines.at(1));

		Course course;
		int courseData= 0;

		// Courses contain 3 pieces of data: course code, course name and final grade
		// courseData counter is used to correctly populate these pieces
		for (unsigned int i = 2; i < lines.size(); i++) {
			switch (courseData) {
			case 0:
				course.setCourseCode(lines.at(i));
				courseData++;
				break;

			case 1:
				course.setCourseName(lines.at(i));
				courseData++;
				break;

			case 2:
				course.setFinalGrade(lines.at(i));
				courseData = 0;
				student.addCourse(course);
				break;
			}
		}

		return true;
	}

	// Display program header
	void displayHeader() {
		// Clear screen, display header and student information
		system("CLS");
		cout << "==========================================================" << endl;
		cout << "         Undergraduate University Honors Calculator       " << endl;
		cout << "==========================================================" << endl;
		cout << student.getStudentName() << " | " << student.getSchoolName() << 
			" | GPA: " << fixed << setprecision(3) << setw(3) << student.getGPA() << endl;
		cout << "Current Latin Honors: " << calculateHonors() << endl << endl;;

	}

	// Calculate and return current honors
	string calculateHonors() {
		string currentHonors = "";

		if ((student.getGPA() >= 3.500) && (student.getGPA() <= 3.699)) {
			currentHonors = honors.at(1);
		}
		else if ((student.getGPA() >= 3.700) && (student.getGPA() <= 3.849)) {
			currentHonors = honors.at(2);
		}
		else if ((student.getGPA() >= 3.850) && (student.getGPA() <= 4.000)) {
			currentHonors = honors.at(3);
		}
		else {
			currentHonors = honors.at(0);
		}

		return currentHonors;
	}

	// Create a new course, obtain its information, and add it to the student's course list
	void addCourse() {
		string courseCode;
		string courseName;
		string finalGrade;

		// Prompt user for course information
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;
		cout << "Enter the course code (ex: IT-101): ";
		getline(cin, courseCode);
		cout << "Enter the course name (ex: Intro to Tech): ";
		getline(cin, courseName);
		cout << "Enter the final letter grade (ex: A, B+, C-): ";
		cin >> finalGrade;

		// Create course and add to student's course list
		Course course(courseCode, courseName, finalGrade);
		student.addCourse(course);
	}

	void removeCourse() {
		string courseCode;

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;
		cout << "Enter the course code to remove (ex: IT-101): ";
		getline(cin, courseCode);

		student.removeCourse(courseCode);		
	}

	// Display student's name, school name, all courses entered, total GPA and current latin honors
	void displayStudentInfo() {
		cout << endl;
		cout << "Student name: " << student.getStudentName() << endl;
		cout << "School: " << student.getSchoolName() << endl << endl;
		cout << "------------------- Courses Completed --------------------" << endl;
		
		for (unsigned int i = 0; i < student.getCourses().size(); i++) {
			cout << student.getCourses().at(i).getCourseCode() << ": " <<
				student.getCourses().at(i).getCourseName() << " | " <<
				"Final Grade: " << student.getCourses().at(i).getFinalGrade() << endl;
		}

		cout << endl << "GPA: " << student.getGPA() << endl;
		cout << "Current Latin Honors: " << calculateHonors() << endl << endl;

		// Pause to allow review of current student record
		system("PAUSE");
	}

	void saveStudentInfo() {
		filename = student.getStudentName() + " Honors Evaluation.txt";
	
		// Attempt to open the file; create it, if it doesn't exist
		ofstream writer(filename, ios::trunc);

		// If the file fails to open, or create, return with an error and terminate
		if (!writer) {
			cout << "Error Opening File!" << endl;
			return;
		}

		// Write student info to the file
		writer << student.getStudentName() << endl;
		writer << student.getSchoolName() << endl;
		
		for (unsigned int i = 0; i < student.getCourses().size(); i++) {
			writer << student.getCourses().at(i).getCourseCode() << endl;
			writer << student.getCourses().at(i).getCourseName() << endl;
			writer << student.getCourses().at(i).getFinalGrade() << endl;
		}

		writer.close();
	}

	void displayOptions() {
		int userChoice = 0;
		cout << "1: Enter new course results" << endl;
		cout << "2: Display student information" << endl;
		cout << "3: Remove course results" << endl;
		cout << "4: Save student information" << endl;
		cout << "5: Exit" << endl << endl;
		cout << "Please make a selection: ";
		cin >> userChoice;
		if (cin) {
			switch (userChoice) {
			case 1:
				addCourse();
				break;

			case 2:
				displayStudentInfo();
				break;

			case 3:
				removeCourse();
				break;

			case 4:
				saveStudentInfo();
				break;

			case 5:
				isRunning = false;
				break;
				
			default:
				cout << endl << "Invalid selection. Please try again." << endl;
			}
			
		}
		else {
			cout << endl << "Invalid input! Please select a valid option." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("PAUSE");
		}
	}

	// Execute the honors calculator
	void runCalculator() {

		// Run initial setup
		welcomeSetup();

		// Begin execution loop
		while (isRunning) {
			displayHeader();
			displayOptions();
		}
	}

};
