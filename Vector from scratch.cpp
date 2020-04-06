#include <iostream>
using namespace std;

template <typename t>
class vector
{
    t *arr;
    int s;
    //l is defined as the no of size of array reserved(l is not always equal to s)
    //l has to be in the power of 2
    int l;
    t *arr1;
public:
//default constructor
vector()
{   s=0;
    l=0;
    arr = new t [0];
}
vector(vector &v)
{
    s = v.s;
    l = v.l;
    arr = new t[l];
    //copying the contents
    for(int i=0 ; i<s ; i++)
    {
        arr[i] = v.arr[i];
    }
    
}
void operator =(vector &v)
{
   s = v.s;
    l = v.l;
    arr = new t[l];
    //copying the contents
    for(int i=0 ; i<s ; i++)
    {
        arr[i] = v.arr[i];
    }
}
void reserve(int num)
{   if(num>l){
    arr1 = new int [l];
    for(int i=0; i<s ; i++)
    arr1[i] = arr[i];
    delete arr;
    arr = new t [num];
    for(int i=0; i<s ; i++)
    arr[i] = arr1[i];
    delete arr1;
    l = num;
    
    }
}
//the return type is change to & so it is returned by refrence
t& operator [](int i)
{
    return arr[i];
}
void push_back(t elememt)
{
    if(l==0)
    {   
        l++;
        s++;
        arr = new t [1];
        arr[0] = elememt;

    }
    else if(l==s)
    {
        //copy the contents into a new array
        arr1 = new t[s];
        for(int i=0; i<s ; i++)
        {
            arr1[i] = arr[i];        
        }
        delete arr;
        l*=2;
        arr = new t[l];
        //copy the contents of array into the new array
        for(int i=0; i<s ; i++)
        {
            arr[i] = arr1[i];        
        }
        delete arr1;
        arr[s] = elememt;
        s++;
    }
    else
    {
        arr[s] = elememt;
        s++;
    }
}
t pop_back()
{
    if((s-1)==(l/2))
    {
        arr1 = new int [s-1];
        for(int i = 0 ; i<(s-1) ; i++)
        arr1[i] = arr[i];
        delete arr;
        l/=2;
        arr = new int[l];
        for(int i = 0 ; i<(s-1) ; i++)
        arr[i] = arr1[i];
        delete arr1;
        s--;
    }
    else
    {
        arr1 = new int [s-1];
        for(int i = 0 ; i<(s-1) ; i++)
        arr1[i] = arr[i];
        delete arr;
        arr = new int[l];
        for(int i = 0 ; i<(s-1) ; i++)
        arr[i] = arr1[i];
        delete arr1;
        s--;
    }
}
void print()
{
    for(int i=0 ; i<s ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void operator +(vector &v)
{   arr1 = new t [l];
    for(int i=0; i<s ; i++)
    arr1[i] = arr[i];
    delete arr;
    //deciding the length(not size) of the new vector
    if(l>v.l)
    {
        l*=2;
    }
    else
    l = 2*(v.l);
    arr = new t [l];
    for(int i=0; i<s ; i++)
    arr[i] = arr1[i];
    for(int i=0; i<(v.s); i++)
    arr[s+i] = v.arr[i];
    s+=v.s;
    delete arr1;
    //merge two vectors
}
int size()
{
    return s;
}
};
int main() {
    vector<int>v;
    v.push_back(1);
    
    v.print();
    v.push_back(1);
    v.print();
    v.pop_back();
    v.print();
    
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(2);
    v1.print();
    v+v1;
    v.print();
    cout<<v.size()<<endl;
    v1=v;
    v1.print();
    vector<int>v2(v);
    v2.reserve(20);
    v2.print();
    cout<<v2[1]<<endl;
    v2[1]+=1;
    v2.print();
    return 0;
}
