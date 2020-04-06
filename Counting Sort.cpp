#include <iostream>
using namespace std;
int main() {
    int arr[] = {-1,3,4,9,5,3,7,8};
    //size of frecquency array is max-min+1 ie. total renge of elements in array +1 for zero
    int n = 11;
    int freq[11]={0};
    for(int i = 0 ; i<8 ; i++)
    {
        freq[arr[i]-arr[0]]++;
    }
    //frecquency of every number starting from min to max is added in the frecuency array;
    int j;
    for(int i = 0 ; i< n ; i++)
    {       //cout<<freq[i];
            j =freq[i];
            for(int k = 0 ; k<j ; k++)
            cout<<(i + arr[0])<<endl;
    }
    
    
    return 0;
}
