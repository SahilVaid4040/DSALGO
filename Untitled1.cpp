#include <cstring>
using namespace std;
template <typename t>
class node
{
public:
	string key;
	t value;
	node<t> *next;
	node(string k,t v)
	{
	key = k;
	value = v;
	}
};
class HashTable
{
int cs;//Current size
int ts;//Total size
node<t>** Bucket;
int Hashfn(string key)
{
int l = key.length();
int ans =0;
int p = 1;
	for(int i=0 ; i<l ; i++)
	{
		ans+=key[l-i-1]*p;
		 p*=37;
		 ans  = ans%ts;
		 
		
	}
	return ans;
}
public:
	HashTable(int ds=7)
	{
	cs =0;
	ts = ds;
	Bucket = new node<t>*[ts];
	for(int i=0 ; i<ts; i++)
	{
	Bucket[i] = NULL;
	}
	}
	void insert(string key,t value)
	{
	int i = Hashfn(key);
	}
};
