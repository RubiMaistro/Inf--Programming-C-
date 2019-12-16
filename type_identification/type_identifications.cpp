#include "type.h"

using namespace std;

/* Using test function:
    test ( enter variable , step counter ) */

int main()
{
    setlocale(LC_ALL, "" );
    string in_text;
    cout<<" Enter something:\n\n  ";
    getline(cin,in_text);
    int i=0;
    typeTest(in_text,i);

return 0;
}
