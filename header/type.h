#include <iostream>
#include <string>

using namespace std;

void test(string in_text,int &i)
{
    i=0;
        while( in_text[i] )
        {
        //Have digit in text?
        if( isdigit(in_text[i]) )
        {
            i++;
            //isdigit == true;
            int j=0;
            bool is_double = false;
            while( in_text[j] )
            {
                if( in_text[j] == '.' ) is_double = true;
                j++;
            }
            //Double
            if( is_double==true )
                {
                    cout<<"\n  You entered text is type of double.\n";
                break;
                }
            //Intiger
            else if( is_double==false )
                {
                    cout<<"\n  You entered text is type of intiger.\n";
                break;
                }

        }
        //Have alpha in text?
        if( isalpha(in_text[i]) )
        {
            i++;
            //isalpha == true;
            int j=0;
            bool is_sentence = false;
            while( in_text[j] )
            {
                //Simple testing
                //If have a space in_text is a sentence
                if( in_text[j] == ' ' )
                {
                    //Have a space
                    //Sentence
                    is_sentence = true;
                }
                j++;
            }
            //Character
            if( j==0 )
            {
                cout<<"\n  You entered text is a character.\n";
            break;
            }
            //Sentence
            else if( is_sentence == false )
            {
                cout<<"\n  You entered text is word.\n";
            break;
            }
            //A word
            else if( is_sentence == true )
            {
                cout<<"\n  You entered text is a sentence.\n";
            break;
            }
        }
        i++;
    }
    //If not enter ...
    if(i == 0 || (i==1 && in_text[i-1]==' '))
    {
        cout<<"  You didn't enter anything.\n  Try again:\n\n  ";
        getline(cin,in_text);
        test(in_text,i);
    }
}
