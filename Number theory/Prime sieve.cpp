 #include <iostream>
using namespace std;
int main()
{
    bool sieve[400] ={false};
	sieve[2] = true;
    for(int i =3 ; i<400 ; i+=2)
	sieve[i] = true;
    for(int i=3 ; i<400 ; i+=2)
    {  
        if(sieve[i])
        {
// i^2 will be the first number not checked for all numbers lest than i^2 there will be a number less than i which would be a divisor
//we add 2i instead of i beacause since i is odd i^2  is odd and i^2+i  is even and checking for even numbers makes no sense
            for(int j=i*i ; j<400 ; j+=2*i)
            {
                sieve[j] = false;
            }
        }

    }
    sieve[0] =false;
    sieve[1] = false;
    for(int i=2 ; i<400 ; i++)
    {
        if(sieve[i])
        printf("%d ",i);
    }

    return 0;
}