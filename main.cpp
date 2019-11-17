#include <iostream>

using namespace std;

int main()
{
    int szam,mentett=0,muvelet=0,valtozo=0,a,b;
    cout<<"Adj meg egy szamot: ";
    cin>>szam;
    valtozo=szam;
        do{
            muvelet=szam%10;    //Szam utolso szamjegyenek mentese.
            mentett=(mentett*10) + muvelet; //Szam utolso szamjegyenek felirasa minden ismetlesben 10x no a szam ehez adodik az ujboli metett utolso szamjegy!
            szam=szam/10;   // Szam utolso szamjegyenek elhagyasa.
        }while(szam>0);
        cout<<"A szam szamjegyei fordiott sorrendben: "<<mentett<<endl;
        if(valtozo<mentett){    // A szamok kulonbozeti ertekenek szamitasa.
            a=mentett-valtozo;
        }else{
        a=valtozo-mentett;
        }
        b=(valtozo+mentett)/2;
        cout<<"A szam es a szam inverzenek a kulonbozeti erteke: "<<a<<endl;
    double c,e;
    int d;
        if(( mentett > 0 && mentett/2 == 1 && 0 ) && ( valtozo > 0 && valtozo/2 == 1 && 0 )){   // Megszabjuk hogy a szam csak egesz szamlehet!
            if(mentett+valtozo!=0){
                d=(mentett+valtozo)/2;
                e=(mentett+valtozo)%2;
                c=d+e;
                cout<<"A szam es a szam iverzenek az atlaga egy tizedes pontossaggal: "<<d<<","<<e*5<<endl<<e;  // Kiiratjuk a szamok atlagat
            }                                                                                                       // egy tizedes pontossaggal!
            else{
                cout<<"A szam es a szam iverzenek az atlaga: "<<b<<endl;    // Kiiratjuk a szamok atlagat!
            }
        }
        cout<<endl;
    return 0;
}
