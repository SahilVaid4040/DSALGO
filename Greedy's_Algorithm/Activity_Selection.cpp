#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Activity
{
    public:
    Activity(int a,int b)
    {
        starting_time =a;
        ending_time =b;
    }
    int starting_time;
    int ending_time;
};
bool compare(Activity a,Activity b)
{
    return a.ending_time<b.ending_time;
}
void Activity_Selection(vector<Activity>v)
{
    Activity a= v[0];
    cout<<a.starting_time<<" "<<a.ending_time<<"\n";
    for(int i=0;i<v.size() ; i++)
    {
        if(v[i].starting_time>=a.ending_time)
        {
            a = v[i];
            cout<<a.starting_time<<" "<<a.ending_time<<"\n";
        }
    }
}
int main() {
    int n;
    scanf("%d ",&n);
    vector<Activity>v;
    for(int i=0; i<n; i++)
    {   int a;
        int b;
        scanf("%d %d",&a,&b);
        Activity s(a,b);
        v.push_back(s);
    }
    sort(v.begin(),v.end(),compare);
    Activity_Selection(v);
    return 0;
}
