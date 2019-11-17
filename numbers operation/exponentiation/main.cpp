#include <iostream>

using namespace std;

int main()
{
  int szam,hatvany,kapott_szam=1;
    cout<<"Adj meg egy szamot: ";
    cin>>szam;
    cout<<"Add meg hanyadik hatvanyra akarod emelni a szamot: ";
    cin>>hatvany;
        while(hatvany>=1)
            {
                kapott_szam=kapott_szam*szam;
                hatvany--;
            }
            cout<<"A szam hatvanya: "<<kapott_szam;
            cout<<endl;
  return 0;
}
