#include <iostream>
using namespace std;
int main() {    int csum=0;
    int maxsum = 0;
    int arr[] = {35,-11,45,13,-5,-43};
    for(int i=0; i<6 ; i++)
        {
            csum = csum + arr[i];
            if(csum<0)
            csum=0;
            if(csum>maxsum)
            maxsum = csum;
        }
        cout<<maxsum;
    return 0;
}
