#include <iostream>
#include <vector>
using namespace std;
class Heap
{
    vector<int>v;
    bool Min_heap;
    bool compare(int a, int b)
    {
        if(Min_heap)
        {
            return a<b;
        }
        else
        {
            return a>b;
        }
    }
    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i+1;
        int min_index = i;
        if(left<v.size()&&compare(v[left],v[i]))
        {
            min_index = left;
        }
        if(right<v.size()&&compare(v[right],v[min_index]))
        {
            min_index = right;
        }
        if(min_index!=i)
        {
        swap(v[i],v[min_index]);
        heapify(min_index);
        }
    }
    public:
    Heap(bool type  = true)
    {
        Min_heap =  type;
        //blocking the 0th index
        v.push_back(-1);
    }
    void push(int data)
    {
        //Pushing the data into the vector
        v.push_back(data);
        //Taking the data to the the right place
        int index = v.size()-1;
        int parent = index/2;
        while(index>1 &&compare(v[index],v[parent]))
        {
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }

    }
    bool isEmpty()
    {
        return v.size() ==1;
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        int last = v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
};
int main() {
    Heap H(false);
    H.push(1);
    H.push(2);
    H.push(3);
    H.push(4);
    H.push(5);
    while(!H.isEmpty())
    {
        cout<<H.top()<<"\n";
        H.pop();
    }
    return 0;
}
