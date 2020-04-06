#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	unordered_map<string,int> mymap;
	mymap["Mango"]  = 100;
	mymap["Guava"] = 200;
	mymap["Kiwi"] = 500;
	for(auto node:mymap)
	{
	cout<<node.first<<" "<<node.second<<endl;
	}	
	return 0;
}