#include <iostream>
#include <vector>

bool isPrime(int n);
void getPrime(int x);

int main(){

    std::cout<<" Prime numbers!\n Enter how many prime number want you calculate: ";
    int x;
    std::cin>>x;
    getPrime(x);

  return 0;
}

void getPrime(int x)
{
    int number[x],n=0,i=0;
    std::cout<<" Primes: ";
    while(i<x)
    {
        n++;
        while(!isPrime(n))
            n++;
        if(isPrime(n))
        {
            std::cout<<n<<" ";
            i++;
        }
    }

}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

return true;
}
