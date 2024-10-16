#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

    string name,id,age;

    // cout<<"Enter your name : ";
    // getline(cin,name);

    // cout<<"Enter you id : ";
    // getline(cin,id);


    // cout<<"Enter your age : ";
    // getline(cin,age);


    // ofstream Myfile("oeer.txt",ios::app);
    // Myfile<<name<<"\t"<<id<<"\t"<<age<<"\n";
    // Myfile.close();

    ifstream myFile("oeer.txt");
    
    while(!myFile.eof()){
        myFile>>name;
        myFile>>id;
        myFile>>age;

        cout<<name <<" "<<id<<" "<<age<<endl;
        name.empty();
        id.empty();
        age.empty();
    }
    
    

    return 0;
}