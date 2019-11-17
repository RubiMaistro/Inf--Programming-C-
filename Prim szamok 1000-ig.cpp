#include <iostream>

using namespace std;

int main(){
    int number[1000],a;

        for (int i=2;i<1001;i++){
            number[i]=i;
        }
        for (int i=2;i<1001;i++){
            a=number[i];
            number[i]=i+number[i+1];
        }
        cout<<"Szamok AVOGADRO: "<<endl;

        for (int i=2;i<1001;i++){
            cout<<number[i]<<" ";
        }

  return 0;
}
