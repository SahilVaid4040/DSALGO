#include <iostream>
using namespace std;
int main() {
    int buildings[] = {0,2,1,3,0,1,2,1,2,1};
    int n = 10;
    //precomputing left tallest including the bulding itself
    int left_tallest[10];
    int tallest =0;
    for(int i=0; i<10 ; i++)
    {   tallest = max(tallest,buildings[i]);
        left_tallest[i] = tallest;
    }
    tallest =0;
    //Precomputing the right tallest buliding
    int right_tallest[10];
    for(int i=9; i>=0; i--)
    {
        tallest = max(tallest,buildings[i]);
        right_tallest[i] = tallest;
    }
    int ans =0;
    for(int i=0 ; i<10; i++)
    {
        ans+= min(left_tallest[i],right_tallest[i])-buildings[i];
    }
    cout<<ans;
    return 0;
}
