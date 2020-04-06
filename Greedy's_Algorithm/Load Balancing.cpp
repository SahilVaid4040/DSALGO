#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int c;
    //no of containers
    scanf("%d",&c);
    int s;
    //no of specimen
    //each container can have at most two specimens
    //task is to reduce imbalance(avg-weight is ith container)
    scanf("%d",&s);
    vector<int>specimen;
    for(int i=0; i<s; i++)
    {   int t;
        scanf("%d",&t);
        specimen.push_back(t);
    }
    float avg =0.0;
    for(int i=0; i<s; i++)
    {
        avg+=specimen[i];
    }
    avg= avg/c;
    int remain = (2*c)-s;
    for(int i=0; i<remain; i++)
    {
        specimen.push_back(0);
    }
    sort(specimen.begin(),specimen.end());
    s = specimen.size();
    float ans=0;
    int i=0;
    while(i<(s/2))
    {
        ans+=(abs(avg-(specimen[i]+specimen[s-1-i])));
        i++;
    }
    cout<<ans;
    return 0;
}
