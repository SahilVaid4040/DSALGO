#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class circle
{
    public:
    int radius;
    int centre;
    circle(int r,int c)
    {
        radius =r;
        centre =c;
    }
};
bool compare(circle a,circle b)
{
    return (a.centre+a.radius)<(b.centre+b.radius);
}
int Intersecting_Circles(vector<circle>v)
{
    sort(v.begin(),v.end(),compare);
    int ans=0;
    for(int i=0; i<(v.size()-1); i++)
    {
        if((v[i].centre+v[i].radius)>(v[i+1].centre-v[i+1].radius))
        {   i++;
            ans++;
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d ",&n);
    vector<circle>v;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d ",&a);
        int b;
        scanf("%d ",&b);
        circle c(a,b);
        v.push_back(c);
    }
    cout<<Intersecting_Circles(v);
    return 0;
}
