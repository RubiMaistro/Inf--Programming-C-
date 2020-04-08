#include <iostream>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

int globN=100;

int main()
{
    setlocale(LC_ALL, "hun");

    srand(time(NULL));
    int array[globN];
    int i=0;

    for(int i=0; i<globN; i++)
    {
        array[i] = rand() % 10000 + 1;
        cout<<array[i]<<endl;
    }
    cout<<"\nElsõ elfut."<<endl;
    /*for(int i=0; i<globN; i++)
    {
        for(int j=0; j<=globN; j++)
        {
            int exchange = 0;
            if(array[i]<array[j])
            {
                exchange = array[i];
                array[i] = array[j];
                array[j] = exchange;
            }
        }
    }
    cout<<"\nRendezés lefut."<<endl;
    for(int i=0; i<globN; i++)
    {
        cout<<array[i]<<endl;
    }
    cout<<"\nMásodik lefut."<<endl;*/

    int size = sizeof(array)/sizeof(array[0]);

    sort(array, array+size);

    cout<<"Array after sort using.\n";

    for(int i=0; i<globN; i++)
    {
        cout<<array[i]<<endl;
    }


    return 0;
}
