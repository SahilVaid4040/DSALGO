#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class Car{
    public:
    int x;
    int y;
    int id;
    Car(int x,int y,int id)
    {
        this->x = x;
        this->y = y;
        this->id = id;
    }
    int distance()
    {
        return x*x + y*y;
    }
    void print()
    {
        cout<<"ID :"<<id<<" location: "<<x<<","<<y<<endl;
    }
};
//Functor Object behaving as function
class CarCompare
{
    public:
    bool operator ()(Car a,Car b)
    {
        return a.distance()>b.distance();
    }
};
int main() {
    int x[] = {5,6,17,18,9,11,0,3};
    int y[] = {1,-2,8,9,10,91,1,2};
    priority_queue<Car,vector<Car>,CarCompare> pq;
    //Inserting cars in queue
    for(int i=0 ; i<8 ; i++)
    {   Car c(x[i],y[i],i);
        pq.push(c);
    }
    while(!pq.empty())
    {
        Car c = pq.top();
        c.print();
        pq.pop();
    }
    return 0;
}
