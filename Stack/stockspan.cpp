#include <iostream>
#include <stack>
using namespace std;
//stock span problem
void stockspan(int *arr,int n)
{
    stack<int>s;
    int ans[100];
    int price;
    for(int day=0 ; day<n ; day++)
    {
        price = arr[day];
        while(s.empty()==false && arr[s.top()]<price)
        s.pop();
        
    int betterday  = s.empty() ? 0 : s.top();
    int span  = day - betterday;
    ans[day] = span;
    s.push(day);
    }
    for(int i=0 ; i<n ; i++)
    cout<<ans[i]<<" ";
    

}
int main() {
    int n =7;
    int arr[]  = {100,80,60,70,60,75,85};
    stockspan(arr,7);
    return 0;
}
