#include <iostream>

using namespace std;

int main()
{
  int number,osszeg=0,a,mentett=0,i=0;
    cout<<"Adj meg egy sz�mot: ";
    cin>>number;
    mentett=number;
        while(number>0)
        {
               a=number%10;
               osszeg=osszeg+a;
               number=number/10;
               i++;
        }
        cout<<"A "<<mentett<<" sz�m sz�mjegyeinek �sszege: "<<osszeg<<endl;
        cout<<"A "<<mentett<<" sz�m sz�mjegyeinek �tlaga: "<<osszeg/i<<endl;
  return 0;
}
