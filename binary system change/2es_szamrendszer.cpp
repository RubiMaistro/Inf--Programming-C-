#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int x=0;
    cout<<"Enter a number: ";
    cin>>x;

    int number = x;
    int i=1, sec[100];
    int marad=0;
    sec[0]=1;
    while(number >=1){
        sec[i] = number%2;
        number/=2;
        i++;
    }
    cout<<"Your number in binary system: ";
    for(i--;i!=0;i--){
        cout<<sec[i];
    }
    cout<<endl<<endl;
    int y=0;
    cout<<"Enter a number(max 10 caracter): ";
    cin>>y;

    int j=0, ten[100], ten_number=0;
    int number1=y;
    while(number1 !=0){
        ten[j] = number1%10;
        number1/=10;
        j++;
    }
    j--;
    int sqrt = j;
    for(int k=j;k>=0;k--){
        if(ten[k]==1){
        ten_number += pow(2,sqrt);
        }
        sqrt--;
    }
    cout<<"Your number in 10th system: "<<ten_number<<endl;


return 0;
}
