#include <iostream>
#include <typeinfo>

using namespace std;

class DivideByZero{
public :
    string message = "The number is being divvided by zero\n";
};

class InvalidInput{

public:
    string message = "Input is Invalid\n";
};

int main(){

    float a , b , r;

    try{
    cout<<"Enter the Numerator : ";
    cin>>a;
    cout<<"Enter the Dunominator : ";
    cin>>b;

    if( b == 0 ){
        DivideByZero D;
        throw D;
    }
    if( type_info(a) != typeid(float) || typeid(b) != typeid(float))

        InvalidInput sd;
        throw sd;

    }catch( DivideByZero d){
        cout<<d.message;
    }
    catch(InvalidInput I){
        cout<<I.message;
    }
    

    return 0;
}