#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

// Structures
struct Student {
    int id;
    string name;
    int age;
    string email;
    string phone;
    string course;
    int marks;
};

// Array
Student students[100];
int numStudents = 0;

// Function Prototype
void adminPanel();
void teacherPanel();
void addStudent();
void showList();
void updateInfo();
void deleteStudent();
void studentMarks();
void classMarks();
char getGrade();
void printGrades();

// ===================================
// ========= Main Function ===========
// ===================================

int main() {
	
    int choice;
	system("cls");
    // Selecting Options
    cout << "\n==== Learning Management System ====\n" << endl;
    cout << "- Choose your Panel -" << endl << endl;
    cout << "1. Admisson Department" << endl;
    cout << "2. Teacher" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Enter Choice: ";
    cin >> choice;

    while (choice != 1 && choice != 2 && choice != 3) {
        cout << "Please Enter a Valid Number: ";
        cin >> choice;
    }
    
    switch (choice) {
    case 1:
        adminPanel();
        break;
    case 2:
        teacherPanel();
        break;
    }
    
    
    return 0;
}

// =======================================
// ============ Admin Panel ==============
// =======================================

void adminPanel() {
	
	system("cls");
		
    int choice;
    cout << "\n==== Welcome to the Admin Panel ====\n" << endl;
    cout << "Select Option: " << endl << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Show List of Students" << endl;
    cout << "3. Edit Student Information" << endl;
    cout << "4. Delete Student" << endl;
    cout << "5. Return to Main Menu" << endl;
    cout << "6. Exit" << endl << endl;
    cout << "Enter Choice: ";
    cin >> choice;

    while (choice > 6 && choice < 1) {
        cout << "Please Enter a Valid Number: ";
        cin >> choice;
    }
	
    switch (choice) {
    case 1:
        addStudent();
        break;
    case 2:
        showList();
        break;
    case 3:
        updateInfo();
        break;
    case 4:
        deleteStudent();
        break;
    case 5:
        main();
        break;
	default: cout << "\nExited\n";
	}
}

// add student function
void addStudent() {
	
	system("cls");
	
	cout << "\n==== Add Student Information ====\n" << endl;
	cout << "Student-" << numStudents + 1 << endl;
	
	cout << "Enter the Student's Id: ";
	cin >> students[numStudents].id;
	cout << "Enter the Student's Name: ";
	cin >> students[numStudents].name;
	cout << "Enter the Student's Age: ";
	cin >> students[numStudents].age;
	cout << "Enter the Student's Email: ";
	cin >> students[numStudents].email;
	cout << "Enter the Student's Phone: ";
	cin >> students[numStudents].phone;
	cout << "Enter the Student's Course: ";
	cin >> students[numStudents].course;
	
	numStudents++;
	
	char addMore;
	cout << "\n\nDo you want to Add More ?\n Press 'Y' for YES and Any 'Key' to return: ";
	cin >> addMore;
	
	switch(addMore)
	{
		case 'y':
		case 'Y': addStudent();
			break;
		default: adminPanel();
	}
	
}

// Show List of Students
void showList() {
	
	cout << "\n==== Show List of Students ====\n" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student-" << i+1 << "\tName: " << students[i].name << "\tAge: " << students[i].age << "\tEmail: " << students[i].email << "\tPhone: " << students[i].phone << "\tCourse: " << students[i].course << "\tMarks: " << students[i].marks << endl;
	}
	
	char addMore;
	cout << "\n\nDo you want to Return Back ?\n Press 'Y' for YES and Any 'Key' to Exit: ";
	cin >> addMore;
	
	switch(addMore)
	{
		case 'y':
		case 'Y': addStudent();
			break;
	}
	
}

// Update Student Information
void updateInfo() {
	
	int id;
	cout << "\n==== Update Information ====\n" << endl;
	cout << "Enter the Student's Id: ";
	cin >> id;
	
	int index = -1;
	for(int i = 0; i < numStudents; i++)
	{
		if(students[i].id == id) {
			index = i;
			break;
		}
	}
	if (index != -1)
	{
	cout << "Enter the Student's new  Id: ";
	cin >> students[index].id;
	cout << "Enter the Student's new  Name: ";
	cin >> students[index].name;
	cout << "Enter the Student's new  Age: ";
	cin >> students[index].age;
	cout << "Enter the Student's new  Email: ";
	cin >> students[index].email;
	cout << "Enter the Student's new  Phone: ";
	cin >> students[index].phone;
	cout << "Enter the Student's new  Course: ";
	cin >> students[index].course;	
	} else {
		cout << "Student Not Found" << endl;
	}
	
	char addMore;
	cout << "\n\nDo you want to Update More ?\n Press 'Y' for YES and Any 'Key' to return: ";
	cin >> addMore;
	
	switch(addMore)
	{
		case 'y':
		case 'Y': updateInfo();
			break;
		default: adminPanel();
	}
	
}

// Delete Student
void deleteStudent()
{
	
	system("cls");
	int id;
	cout << "\n==== Delete Student From List ====\n" << endl;
	cout << "Enter the Student's Id: ";
	cin >> id;
	
	int index = -1;
	for(int i = 0; i < numStudents; i++)
	{
		if(students[i].id == id) 
		{
			index = i;
		}
	}
	
	if (index != -1) 
	{
		for(int i = index; i < numStudents; i++)
		{
			students[i] = students[i + 1];	
		}
		cout << "\nStudent Deleted from the List\n";
		numStudents--;
	} else {
		cout << "Students Not Found\n";
	}
	
	char delMore;
	cout << "\n\nDo you want to Delete More ?\n Press 'Y' for YES and Any 'Key' to return: ";
	cin >> delMore;
	
	switch(delMore)
	{
		case 'y':
		case 'Y': deleteStudent();
			break;
		default: adminPanel();
	}
}


// =======================================
// ============ Teacher Panel ============
// =======================================
void teacherPanel() {
	
	system("cls");
	
    int choice;
    cout << "\n====Welcome to the Teacher Panel====\n" << endl;
    cout << "Select Option: \n" << endl;
    cout << "1. Enter Marks for a Student" << endl;
    cout << "2. Enter Marks for Complete Class" << endl;
    cout << "3. Print List and Grades of Students" << endl;
    cout << "4. Return to Main Menu" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice > 3 && choice < 1) {
        cout << "Please Enter a Valid Number: ";
        cin >> choice;
    }
    
    switch(choice)
    {
    	case 1: studentMarks();
    		break;
    	case 2: classMarks();
    		break;
    	case 3: printGrades();
    		break;
    	case 4: main();
    		break;
    	default: cout << "Exiting ......";
	}
}

// Student Marks Individual
void studentMarks() 
{
	cout << "\n==== Student Marks ====\n" << endl;
	cout << "Marks must be in range 0 - 100\n";
	int id;
	cout << "Enter the Student's Id: " << endl;
	cin >> id;
	
	int index = -1;
	for (int i = 0; i < numStudents; i++)
	{
		if(students[i].id == id)
		{
			index = i;
			break;
		}
	}
	
	if (index != -1) {
		cout << "Name: " << students[index].id << "\t Name: " << students[index].name << endl;
		cout << "Enter Marks of Selected Student: ";
		cin >> students[index].marks;
	} else {
		cout << "\nWrong Id\n";
	}
	
	char addMore;
	cout << "\n\nDo you want to Update More ?\n Press 'Y' for YES and Any 'Key' to return: ";
	cin >> addMore;
	
	switch(addMore)
	{
		case 'y':
		case 'Y': studentMarks();
			break;
		default: teacherPanel();
	}

}

// Whole Class
void classMarks()
{
	system("cls");
	cout << "\n ==== Marking of All Students ====\n" << endl;
	cout << "Marks must be in range 0 - 100\n";
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Name: " << students[i].id << "\t Name: " << students[i].name << endl;
		cout << "Enter Marks: ";
		cin >> students[i].marks;
	}
	
	cout << "\nAll Student Marks Added Successfully\n";
	char choice;
	cout << "Do you want to Return Back 'Y' or Exit 'Any Key': ";
	cin >> choice;
	
	if (choice == 'Y' || choice == 'y')
	{
		teacherPanel();	
	}
	
}

char getGrade(int marks)
{
	char grades[5] = {'A', 'B', 'C', 'D', 'F'};
	if (marks >= 80) 
		return grades[0];
	else if (marks >= 70)
		return grades[1];
	else if (marks >= 60)
		return grades[2];
	else if (marks >= 50)
		return grades[3];
	else 
		return grades[4];
}

void printGrades() 
{
	system("cls");
	cout << "\n==== Grading List ====\n" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student: " << i + 1 << "\tId: " << students[i].id << "\tName: " << students[i].name << "\tMarks: " << students[i].marks << "\tGrade: " << getGrade(students[i].marks) << endl;	
	}
	cout << endl;
	int choice;
	cout << "Do you want to Return Back 'Y' or Exit 'Any Key': ";
	cin >> choice;
	
	if (choice == 'Y' || choice == 'y')
	{
		teacherPanel();	
	}
}
