#include<iostream>
#include "Hashtable.h"
using namespace std;
int main()
{
Hashtable<int>h(7);
h.Insert("Mango",100);
h.Insert("Apple",170);
h.Insert("Guava",140);
h.Insert("Banana",130);

h.print();
h.Insert("Chiku",120);
int *f = h.search("Mango");
if(f){
	cout<<*f<<" is the price\n";
}
else
{
cout<<"Not found\n";
}

h.print();
h.Erase("Mango");
h.print();
return 0;
}
