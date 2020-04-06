#include <iostream>
using namespace std;
template<typename t>
class Queue
{
    int cs;
    int ms;
    int f;
    int r;
    t* arr;
    public:
    Queue(int size)
    {
        arr = new t[size];
        f =0;
        ms = size;
        r = ms-1;
        cs = 0;
        
    }
    bool isFull()
    {
        return (cs==ms);
    }
    bool isEmpty()
    {
        return cs==0;
    }
    void Push(t data)
    {
        if(!isFull())
        {
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }
    void Pop()
    {
        if(!isEmpty())
        {
            f = (f+1)%ms;
            cs--;
        }
    }
    t getFront()
    {
        return arr[f];
    }
};
int main()
{   Queue<int>Q(5);
    for(int i=1 ; i<=5 ; i++)
    Q.Push(i*i);
    for(int i=1 ; i<=3 ; i++)
    {
    cout<<Q.getFront()<<" ";
    Q.Pop();
    }
    for(int i=7 ; i<=9 ; i++)
    {
    Q.Push(i*i);
    }
    for(int i=1 ; i<=3 ; i++)
    {
    cout<<Q.getFront()<<" ";
    Q.Pop();
    }

    return 0;
}