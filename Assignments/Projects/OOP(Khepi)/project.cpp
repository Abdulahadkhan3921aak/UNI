#include <iostream>
#include <string>
using namespace std;

class Academic {
public:
    string* courses;
    char* grades;
    int courseCount;

    Academic() : courses(nullptr), grades(nullptr), courseCount(0) {}

    void inputAcademicInfo() {
        cout << "Enter the number of courses: ";
        cin >> courseCount;
        cin.ignore();

        courses = new string[courseCount];
        grades = new char[courseCount];

        for (int i = 0; i < courseCount; i++) {
            cout << "Enter course name for course " << i + 1 << ": ";
            getline(cin, courses[i]);
            cout << "Enter grade for course " << i + 1 << ": ";
            cin >> grades[i];
            cin.ignore();
        }
    }

    ~Academic() {
        delete[] courses;
        delete[] grades;
    }
};

class Extracurricular {
public:
    string* achievements;
    int achievementCount;
    string* games;
    int gameCount;
    string hobbies;

    Extracurricular() : achievements(nullptr), achievementCount(0), games(nullptr), gameCount(0), hobbies("") {}

    void inputExtracurricularInfo() {
        cout << "Enter the number of achievements: ";
        cin >> achievementCount;
        cin.ignore();

        achievements = new string[achievementCount];

        for (int i = 0; i < achievementCount; i++) {
            cout << "Enter achievement " << i + 1 << ": ";
            getline(cin, achievements[i]);
        }

        cout << "Enter the number of games played: ";
        cin >> gameCount;
        cin.ignore();

        games = new string[gameCount];

        for (int i = 0; i < gameCount; i++) {
            cout << "Enter game " << i + 1 << ": ";
            getline(cin, games[i]);
        }

        cout << "Enter your hobby: ";
        getline(cin, hobbies);
    }

    ~Extracurricular() {
        delete[] achievements;
        delete[] games;
    }
};

class DisplayInfo {
public:
    string name;
    string age;
    string id;
    string* courses;
    int* grades;
    int courseCount;
    string* achievements;
    int achievementCount;
    string* games;
    int gameCount;
    string hobbies;

    void displayAllInfo() {
        cout << "\n\t*Personal Information*\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Registration Number: " << id << "\n";

        cout << "\n\t*Academic Information*\n";
        if (courseCount > 0) {
            for (int i = 0; i < courseCount; i++) {
                cout << "Course " << i + 1 << ": " << courses[i] << " (Grade: " << grades[i] << ")\n";
            }
        }
        else {
            cout << "No academic information available.\n";
        }

        cout << "\n\t*Extracurricular Information*\n";
        if (achievementCount > 0) {
            for (int i = 0; i < achievementCount; i++) {
                cout << "Achievement " << i + 1 << ": " << achievements[i] << "\n";
            }
        }
        else {
            cout << "No achievements available.\n";
        }

        if (gameCount > 0) {
            cout << "Games Played: ";
            for (int i = 0; i < gameCount; i++) {
                cout << games[i];
                if (i != gameCount - 1)
                    cout << ", ";
            }
            cout << "\n";
        }
        else {
            cout << "No games played.\n";
        }

        cout << "Hobbies: " << hobbies << "\n";
    }
};

class Student {
public:
    string id;
    DisplayInfo displayInfo;
    Academic academicInfo;
    Extracurricular extracurricularInfo;

    void addPersonalInfo() {
        cout << "Enter your name: ";
        getline(cin, displayInfo.name);
        cout << "Enter your age: ";
        getline(cin, displayInfo.age);
        cout << "Enter your registration number: ";
        getline(cin, id);
    }

    void addAcademicInfo() {
        academicInfo.inputAcademicInfo();
    }

    void addExtracurricularInfo() {
        extracurricularInfo.inputExtracurricularInfo();
    }

    void displayAllInfo() {
        displayInfo.displayAllInfo();
    }
};

int main() {
    int studentCount = 0;
    const int maxStudents = 100;
    Student* students[maxStudents];

    bool isRunning = true;
    while (isRunning) {
        cout << "\n-------------------------\n";
        cout << "Student Information System\n";
        cout << "-------------------------\n";
        cout << "1. Register new student\n";
        cout << "2. Add information for existing student\n";
        cout << "3. Delete student information\n";
        cout << "4. Search student information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (studentCount >= maxStudents) {
                cout << "Maximum student limit reached!\n";
                break;
            }

            students[studentCount] = new Student();
            students[studentCount]->addPersonalInfo();
            students[studentCount]->addAcademicInfo();
            students[studentCount]->addExtracurricularInfo();
            studentCount++;
            break;
        }
        case 2: {
            cout << "Enter the registration number to add information: ";
            string regNumber;
            getline(cin, regNumber);
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i]->id == regNumber) {
                    students[i]->addPersonalInfo();
                    students[i]->addAcademicInfo();
                    students[i]->addExtracurricularInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Registration number not found!\n";
            }
            break;
        }
        case 3: {
            cout << "Enter the registration number to delete information: ";
            string regNumber;
            getline(cin, regNumber);
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i]->id == regNumber) {
                    delete students[i];
                    students[i] = students[studentCount - 1];
                    studentCount--;
                    found = true;
                    cout << "Information deleted successfully!\n";
                    break;
                }
            }
            if (!found) {
                cout << "Registration number not found!\n";
            }
            break;
        }
        case 4: {
            cout << "Enter the registration number to search information: ";
            string regNumber;
            getline(cin, regNumber);
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i]->id == regNumber) {
                    students[i]->displayAllInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Registration number not found!\n";
            }
            break;
        }
        case 5: {
            isRunning = false;
            break;
        }
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }

    return 0;
}