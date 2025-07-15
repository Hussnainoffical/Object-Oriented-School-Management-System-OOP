#include <iostream>
#include <string>
using namespace std;

class Database {
 protected:
    long long int contact;
    string address, name, fathername;

public:
    Database() {}

    void setContact(long long int contact1) {
        contact = contact1;
    }

    void setAddress( string address1) {
        address = address1;
    }

    void setName( string name1) {
        name = name1;
    }

    void setFatherName( string fathername1) {
        fathername = fathername1;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Address: " << address << endl;
        cout << "Father's Name: " << fathername << endl;
    }
};

class Teacher : public Database {
   private:
    
    string subject;
   static int teacherid ;
    string password;
public:
    Teacher() {}

    
   void setpassword(string password1){
   	password=password1;
   }
    string getpassword(){
   	return password;
   }
    void setSubject( string subject1) {
        subject = subject1;
       
    }
    void  teacherid1(){
    	 teacherid++;
	}
    int getTeacherId() {
        return teacherid;
    }

    string getSubject() {
        return subject;
    }

    void displayInfo() {
        cout << "Teacher's Information:" << endl;
        Database::displayInfo();
       cout<<"ID is. "<<teacherid<<endl;
        cout << "Subject: " << subject << endl;
    }
   
   
};
class Course {
private:

    string name;
    string code;
    int enrolledStudents; 
 	public:
 
    
    void setName( string name1) {
        name = name1;
    }

    void setCode( string code1) {
        code = code1;
    }

    string getName()  {
        return name;
    }

    string getCode()  {
        return code;
    }

    
     int getEnrolledStudents()  {
        return enrolledStudents;
    }

    void enrollStudent() {
        enrolledStudents++;
    }
  
};
class Student : public Database {
   private:
   static int rollnumber ;
    int class4;
    int fees;
    bool hasPaid;
    string password;
 Course* enrolledCourse;
public:
    Student() {}
    void setpassword(string password1){
   	password=password1;
   }
   string getpassword(){
   	return password;
   }
    void setClass(int class2) {
      
  class4 = class2;
 
  setFees();
  hasPaid = false; 
}
    void increaseroll()
{
	 rollnumber++;
}
    void setFees() {
      
        switch (class4) {
            case 1:
            case 2:
                fees = 1000;
                break;
            case 3:
            case 4:
                fees = 1500;
                break;
            case 5:
            case 6:
                fees = 2000;
                break;
            case 7:
            case 8:
                fees = 2500;
                break;
            case 9:
            case 10:
                fees = 3000;
                break;
        }
    }

    int getRollNumber() {
        return rollnumber;
    }

    int getFees() {
        return fees;
    }

    bool hasPaidFees() {
        return hasPaid;
    }

    void markFeesPaid() {
        hasPaid = true;
    }

    void displayInfo() {
        cout << "Student's Information:" << endl;
        Database::displayInfo();
        cout << "Roll Number: " << getRollNumber() << endl;
        cout << "Class: " << class4 << endl;
    }

    int getClass() {
        return class4;
    }
      void enrollCourse(Course* course) {
        enrolledCourse = course;
        enrolledCourse->enrollStudent(); // Increment the enrolled student count in the course
    }

   
};


int Student::rollnumber = 0;
int Teacher::teacherid = 0;

int main() {
    system("COLOR CF");
    int choice;
    bool a = true;
    Student* records = new Student[100];
    int recordcount = 0;
    Teacher* teachers = new Teacher[100];
    int teachercount = 0;
    Course* courses = new Course[100];
    int courseCount = 0;
    int recordCapacity = 100;
    int teacherCapacity = 100;
    int courseCapacity = 100;
    int totalFees = 0;
    while (a) {
        cout << "-----------------------------" << endl;
        cout << "UMT School Management System" << endl;
        cout << "-----------------------------" << endl;
        cout << "\t1. Add a new student" << endl;
        cout << "\t2. Add a new teacher" << endl;
        cout << "\t3. Principal Login" << endl;
        cout << "\t4. Student Login" << endl;
        cout << "\t5. Teacher Login" << endl;
        cout << "\t0. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore();
        switch (choice) {
        case 1: {
            if (recordcount >= recordCapacity) {
                cout << "Student list is full!" << endl;
                break;
            }
            long long int contact;
            string address, name, fathername;
            int class4;
            cout << "Enter student contact number: ";
            cin >> contact;
            cout << "Enter student address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student's father name: ";
            getline(cin, fathername);
            cout << "Enter student's class: ";
            cin >> class4;
            while (class4 < 1 || class4 > 10) {
                cout << "Invalid class entered. Please enter a class between 1 and 10: ";
                cin >> class4;
            }
            records[recordcount].setContact(contact);
            records[recordcount].setAddress(address);
            records[recordcount].setName(name);
            records[recordcount].setFatherName(fathername);
            records[recordcount].setClass(class4);
            records[recordcount].increaseroll();
            recordcount++;
            break;
        }
        case 2: {
            if (teachercount >= teacherCapacity) {
                cout << "Teacher list is full!" << endl;
                break;
            }
            long long int contact;
            string address, name, fathername, subject, password;
            cout << "Enter teacher contact number: ";
            cin >> contact;
            cout << "Enter teacher address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter teacher name: ";
            getline(cin, name);
            cout << "Enter teacher's father name: ";
            getline(cin, fathername);
            cout << "Enter subject: ";
            getline(cin, subject);
            cout << "Set password: ";
            getline(cin, password);
            teachers[teachercount].setContact(contact);
            teachers[teachercount].setAddress(address);
            teachers[teachercount].setName(name);
            teachers[teachercount].setFatherName(fathername);
            teachers[teachercount].setSubject(subject);
            teachers[teachercount].setpassword(password);
            teachers[teachercount].teacherid1();
            teachercount++;
            break;
        }
        case 3: {
            string username, password;
            cout << "Enter admin username: ";
            getline(cin, username);
            cout << "Enter admin password: ";
            getline(cin, password);
            static string adminPassword = "admin321";
            if (username == "admin" && password == adminPassword) {
                bool adminMenu = true;
                while (adminMenu) {
                    int adminChoice;
                    cout << "\nPrincipal Menu:\n";
                    cout << "1. Change admin password\n";
                    cout << "2. View all students\n";
                    cout << "3. View all teachers\n";
                    cout << "4. Add a new course\n";
                    cout << "0. Logout\n";
                    cout << "Enter your choice: ";
                    if (!(cin >> adminChoice)) {
                        cout << "Invalid input. Returning to main menu.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                        break;
                    }
                    cin.ignore();
                    switch (adminChoice) {
                    case 1: {
                        cout << "Enter new admin password: ";
                        getline(cin, adminPassword);
                        cout << "Admin password changed successfully!\n";
                        break;
                    }
                    case 2: {
                        for (int i = 0; i < recordcount; i++) {
                            records[i].displayInfo();
                            cout << "-------------------\n";
                        }
                        break;
                    }
                    case 3: {
                        for (int i = 0; i < teachercount; i++) {
                            teachers[i].displayInfo();
                            cout << "-------------------\n";
                        }
                        break;
                    }
                    case 4: {
                        if (courseCount >= courseCapacity) {
                            cout << "Course list is full!" << endl;
                            break;
                        }
                        string courseName, courseCode;
                        cout << "Enter course name: ";
                        getline(cin, courseName);
                        cout << "Enter course code: ";
                        getline(cin, courseCode);
                        courses[courseCount].setName(courseName);
                        courses[courseCount].setCode(courseCode);
                        courseCount++;
                        cout << "Course added successfully!\n";
                        break;
                    }
                    case 0:
                        adminMenu = false;
                        break;
                    default:
                        cout << "Invalid option.\n";
                    }
                }
            } else {
                cout << "Invalid admin credentials!\n";
            }
            break;
        }
        case 4: {
            string password;
        	int rollnumber;
        	cout<<"Enter you roll number "<<endl;
        	cin>>rollnumber;
        	cout<<"Enter your Password "<<endl;
        	cin>>password;
        	 bool found=false;
        	for(int i=0;i<recordcount;i++)
        	{   
        		if(records[i].getpassword()==password&&records[i].getRollNumber()==rollnumber)
        		{
        			found=true;
        			records[i].displayInfo();
        			int choice4;
        		    
        cout << "Press 1 to change name." << endl;
        cout << "Press 2 to change class." << endl;
        cout << "Press 3 to change password." << endl;
        cout << "Enter your choice: ";
        cin >> choice4;

        if (choice4 == 1) {
            string newName;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            records[i].setName(newName);
            cout << "Name changed successfully!" << endl;
        } else if (choice4 == 2) {
            int newClass;
            cout << "Enter new class: ";
            cin >> newClass;
            records[i].setClass(newClass);
             totalFees += records[recordcount].getFees();
            cout << "Class changed successfully!" << endl;
        } else if (choice4 == 3) {
            string newPassword;
            cout << "Enter new password: ";
            cin >> newPassword;
            records[i].setpassword(newPassword);
            cout << "Password changed successfully!" << endl;
        }else if(choice4==4){
            
        	    if (  records[i].getClass()>= 8 &&  records[i].getClass() <= 10){
				
                cout << "Press 1 to view available courses" << endl;
                cout << "Press 2 to enroll in a course" << endl;
                cout << "Enter your choice: ";
                int studentChoice;
                cin >> studentChoice;

                switch (studentChoice) {
                    case 1: {
                        // View available courses code
                        cout << "Available courses:" << endl;
                        for (int i = 0; i < courseCount; i++) {
                            cout << courses[i].getName() << " (" << courses[i].getCode() << ")" << endl;
                        }
                        break;
                    }

                    case 2: {
                        
                        cout << "Enter the course code to enroll: ";
                        string courseCode;
                        cin >> courseCode;

                      
                        int courseIndex = -1;
                        for (int i = 0; i < courseCount; i++) {
                            if (courses[i].getCode() == courseCode) {
                                courseIndex = i;
                               if (  courseIndex> 0 &&  courseIndex <= courseCount) {
            records[recordcount].enrollCourse(&courses[ courseIndex]);
            cout << "Student enrolled in the course successfully!" << endl;
        } else {
            cout << "Invalid course selection." << endl;
        }
								break;
                            }
                        }

                        if (courseIndex != -1) {
                           
                            cout << "Enrollment successful!" << endl;
                        } else {
                            cout << "Course not found!" << endl;
                        }
                        break;
                    }

	}
}else {
    cout << "You are not eligible to enroll in any courses." << endl;
}
		}else if(choice4==0){
        	break;
		} 
		else {
            cout << "Invalid choice!" << endl;
        }

        break;
        			
				}
			}
		if(!found){
			cout<<"Invalid password or username "<<endl;
		}
        }
        case 5: {
         
		    	string password;
        	int rollnumber;
        	cout<<"Enter you ID "<<endl;
        	cin>>rollnumber;
        	cout<<"Enter your Password "<<endl;
        	cin>>password;
        	 bool found=false;
			for(int i=0;i<teachercount;i++)
        	{   
        		if( teachers[i].getpassword()==password&& teachers[i].getTeacherId()==rollnumber)
        		{
        			found=true;
        			 teachers[i].displayInfo();
        				int choice5;
        				          cout << "Press 1 to change name." << endl;
            cout << "Press 2 to change subject." << endl;
            cout << "Press 3 to change password." << endl;
            cout << "Enter your choice: ";
            cin >> choice5;

            if (choice5 == 1) {
                string newName;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newName);
                teachers[i].setName(newName);
                cout << "Name changed successfully!" << endl;
            } else if (choice5 == 2) {
                string newSubject;
                cout << "Enter new subject: ";
                cin.ignore();
                getline(cin, newSubject);
                teachers[i].setSubject(newSubject);
                cout << "Subject changed successfully!" << endl;
            } else if (choice5 == 3) {
                string newPassword;
                cout << "Enter new password: ";
                cin >> newPassword;
                teachers[i].setpassword(newPassword);
                cout << "Password changed successfully!" << endl;
            } else {
                cout << "Invalid choice!" << endl;
            }

            break;
				}
			}
		if(!found){
			cout<<"Invalid password or username "<<endl;
		}
			
        }
        
		case 0:
            a = false;
            break;
        default:
            cout << "Invalid option.\n";
        }
    }
    // Clean up memory
    delete[] records;
    delete[] teachers;
    delete[] courses;
    return 0;
}

