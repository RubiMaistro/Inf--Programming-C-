#include <sstream>

using namespace std;

int convStrInt(int &x,string &str){
    int length=0;
    while(length<str.size()){ length++; }   //count string characters

    if(length > 10){                        //length testing
        cout<<"This is too length for type int.\n";
    }else{
        stringstream line(str);
        line>>x;
    }
}

double convStrDouble(double &db, string &str){
    int length=0;
    while(length<str.size()){ length++; }   //count string characters

    if(false){                              //testing, but here not important, but this always false
        cout<<"This is too length for type double.\n";  //and IDK how to test the double
    }else{
        stringstream line(str);
        line>>db;
    }
}

long convStrLong(long &lng, string &str){
    int length=0;
    while(length<str.size()){ length++; }   //count string characters

    if(length > 10){                        //length testing
        cout<<"This is too length for type long.\n";
    }else{
        stringstream line(str);
        line>>lng;
    }
}

