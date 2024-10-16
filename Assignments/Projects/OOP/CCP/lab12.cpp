#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("data.txt");
    if (!file) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string name;
    int age;
    string mobile;

    try {
        file >> name;
        if (name.length() == 0) {
            throw 'c';  
        }

        file >> age;
        if (!file) {
            throw 1; 
        }

        file >> mobile;
        if (mobile.length() != 10) {
            throw 0.0;  
        }

        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Mobile: " << mobile << endl;
    }
    catch (char c) {
        cout << "Invalid name." << endl;
    }
    catch (int n) {
        cout << "Invalid age." << endl;
    }
    catch (...) {
        cout << "Invalid mobile number." << endl;
    }

    file.close();
    return 0;
}