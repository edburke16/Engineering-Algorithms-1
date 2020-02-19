// Edward Burke 
// ID: 001602259 
#include <iostream>
#include <string>
using namespace std;

// Class representing a person 
class Person {
	// Person's name 
	string fullname;
	// Person's address 
	string address;
	// Person's age 
	int age;
public:
	// Requests input for Person attributes 
	void readPersonInfo();
	// Displays Person attributes 
	void printPersonInfo();
	// Returns Person age 
	int personAge();
	// Returns Person name 
	string personName();
};

// Requests input for Person attributes 
void Person::readPersonInfo() {
	cout << "Name? ";
	cin >> fullname;
	cout << "Address? ";
	cin >> address;
	cout << "Age? ";
	cin >> age;
}

// Displays Person attributes 
void Person::printPersonInfo() {
	cout << "Name: " << fullname << "\nAddress: " << address << "\nAge: " << age << "\n";
}

// Returns Person age 
int Person::personAge() {
	return age;
}

// Returns Person name 
string Person::personName() {
	return fullname;
}

// Class for a Students, dereived from Person 
class Student :  public Person {
	// Student ID 
	string ID;
	// Student major 
	string major;
	// Student GPA 
	float gpa;
public:
	// Requests input for Student attributes 
	void readStudentInfo();
	// Displays Student attributes 
	void printStudentInfo();
	// Returns Student GPA 
	float studentGPA();
};

// Requests input for Student attributes 
void Student::readStudentInfo() {
	readPersonInfo();
	cout << "ID? ";
	cin >> ID;
	cout << "Major? ";
	cin >> major;
	cout << "GPA? ";
	cin >> gpa;
}

// Displays Student attributes 
void Student::printStudentInfo() {
	printPersonInfo();
	cout << "Student ID: " << ID << "\nMajor: " << major << "\nGPA: " << gpa << "\n";
}

// Returns Student GPA 
float Student::studentGPA() {
	return gpa;
}

// Class for Courses 
class Course {
	// Course ID 
	string ID;
	// Course title 
	string title;
	// Course credits 
	int credits;
public:
	Course() {
		cout << "ID? ";
		cin >> ID;
		cout << "Title? ";
		cin >> title;
		cout << "Credits? ";
		cin >> credits;
	};
	// Displays Course attributes 
	void printCourseInfo();
};

// Displays Course attributes 
void Course::printCourseInfo() {
	cout << "Course ID: " << ID << "\nTitle: " << title << "\nCredits: " << credits;
}

// Class for Course Sections, derived from Course 
class CourseSection : public Course {
	// Section size (used for roster size) 
	int sectionSize;
	// List of Students in the Course Section 
	Student* roster;
public:
	// Constructor 
	CourseSection(string ID, string title, int credits, int sectionSize) {
		CourseSection::sectionSize = sectionSize;
		CourseSection::roster = new Student[sectionSize];
		// Creating an list of dummy Students to be filled in later 
		Student dummy;
		for (int i = 0; i < sectionSize; i++) {
			roster[i] = dummy;
		}
	}
	// Destructor 
	~CourseSection() {
		delete roster;
	};
	// Requests input of attributes 
	void fillRosterInfo();
	// Displays attributes 
	void printSectionInfo();
	// Displays average GPA 
	void printAverageGPA();
	// Displays info of youngest student 
	void printYoungestStudent();
};

// Request input for all the Students in roster 
void CourseSection::fillRosterInfo() {
	for (int i = 0; i < sectionSize; i++) {
		cout << "Student " << i + 1 << ":\n";
		roster[i].readStudentInfo();
	}
}

// Displays course attributes 
void CourseSection::printSectionInfo() {
	for (int i = 0; i < sectionSize; i++) {
		roster[i].printStudentInfo();
	}
}

// Displays average Student GPA 
void CourseSection::printAverageGPA() {
	float sum = 0;
	for (int i = 0; i < sectionSize; i++) {
		sum += roster[i].studentGPA();
	}
	cout << "Average GPA: " << (sum / sectionSize) << "\n";
}

// Displays Youngest Student info 
void CourseSection::printYoungestStudent() {
	int youngest = 1000;
	int index;
	for (int i = 0; i < sectionSize; i++) {
		if (roster[i].personAge() < youngest) {
			youngest = roster[i].personAge();
			index = i;
		}
	}
	cout << "Youngest Student: ";
	roster[index].printStudentInfo();
}

// Test code 
int main() {
	Person testPerson1;

	testPerson1.readPersonInfo();
	cout << "Should reprint data\n";
	testPerson1.printPersonInfo();
	cout << "Should print age:\n";
	cout << testPerson1.personAge() << "\n";
	cout << "Should print name:\n";
	cout << testPerson1.personName() << "\n";

	Student testStudent1;

	testStudent1.readStudentInfo();
	cout << "Should reprint data\n";
	testStudent1.printStudentInfo();
	cout << "Should print GPA\n";
	cout << testStudent1.studentGPA() << "\n";

	cout << "Should ask for Course info\n";
	Course testCourse1;

	cout << "Should reprint data\n";
	testCourse1.printCourseInfo();

	CourseSection testCourseSection1 = CourseSection("ID", "Title", 5, 2);
	cout << "Should ask for 2 Students' worth of data\n";
	testCourseSection1.fillRosterInfo();
	cout << "Should reprint data\n";
	testCourseSection1.printSectionInfo();
	cout << "Should print average GPA\n";
	testCourseSection1.printAverageGPA();
	cout << "Should print youngest Student\n";
	testCourseSection1.printYoungestStudent();
}