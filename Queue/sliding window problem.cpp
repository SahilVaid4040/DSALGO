#include <iostream>
#include <deque>
using namespace std;
//question is to find the maximum no of the subarray of 3 elements
int main() {
    int arr [] = {1,2,3,1,4,5,2,3,6};
    deque<int>q;
    int i;
    for(i=0; i<3;i++)
    {
    while(!q.empty() && q.back()<arr[i])
    q.pop_back();
    q.push_back(i);
    }
    for(i;i<9;i++)
    {   //printing the first element
        cout<<arr[q.front()]<<" ";
        //removing all the elements that are not in the window
        while(!q.empty() && q.front()<=(i-3))
        q.pop_front();
        //removing the elements that are in the window but not recquired
        while(!q.empty() && arr[q.back()]<=arr[i])
        q.pop_back();
        //expanding the window
        q.push_back(i);
    }
    cout<<arr[q.front()];
    return 0;
}
