#include <iostream>
#include <cstring>
using namespace std;
template<typename t>
class node
{
public:
string key;
t value;
node<t> *next;
node(string k, t v)
{
key = k;
value = v;
}
 ~node()
 {
 if(next!=NULL)
 {
 delete next;
 }
 }
};
template<typename t>
class Hashtable
{
int cs;
int ts;
node<t>** bucket;
int Hashfn(string key)
{
int l = key.length();
	int p =1;
	int ans=0;
	for(int i=0; i<l ; i++)
	{
	ans+=key[l-1-i]*p;
	p*=37;
	p%=ts;
	ans%=ts;
	}
	return ans;
}
void rehash()
{
node<t>**oldbucket = bucket;
int oldts = ts;
ts*=2;
cs=0;
bucket  = new node<t>*[ts];
for(int i=0 ;i<ts; i++)
{
bucket[i] = NULL;
}
for(int i=0 ;i<oldts; i++)
{
	node<t>*  temp= oldbucket[i];
if(temp!=NULL)
{
	while(temp!=NULL)
	{
	Insert(temp->key,temp->value);
	temp = temp->next;
	}
	delete oldbucket[i];
}
}
delete [] oldbucket;
}
public:
	Hashtable(int ds =7)
	{
		cs=0;
		ts = ds;
		bucket = new node<t>* [ts];
	//Make all  indexes NULL
	for(int i=0; i<ts; i++)
	{
	bucket[i] = NULL;
	}
	}
	void Insert(string key,t value)
	{
	int i =  Hashfn(key);
	node<t>* n = new node<t>(key,value);
	//Chaining by insertion at head
	n->next = bucket[i];
	bucket[i] = n;
	cs++;
	//Load factor and rehashing
	float Load_Factor = (float)cs/ts;
	if(Load_Factor>0.7)
	{
	cout<<"Load Factor is "<<Load_Factor<<"\n";
	rehash();
	}
	}
	void print()
	{
		node<t>*temp;
		for(int i=0; i<ts; i++)
		{
		temp = bucket[i];
		cout<<"Bucket "<<i<<" ";
		while(temp!=NULL)
		{
		cout<<temp->key<<" ";
		temp = temp->next;
		}
		cout<<"\n";
		}
	}
	t* search(string k)
	{
	int i = Hashfn(k);
	node<t>*temp = bucket[i];
	while(temp!=NULL)
	{
		if(temp->key==k){
			return &(temp->value);
		}
		else
	temp = temp->next;
	}
	return NULL;
	}
	void Erase(string k)
	{
	int f = Hashfn(k);
	node<t>* head  = bucket[f];
	if(head->key==k)
	{
	node<t>*n = head->next;
	head->next = NULL;
	bucket[f] = n;
	delete head;
	}
	else{
	while(head->next->key!=k && head!=NULL)
	{
	head = head->next;
	}
	if(head!=NULL)
	{
	node<t>*n  = head->next;
	head->next = n->next;
	n->next=  NULL;
	delete n;
	cs--;
	}
	}
	}
	};
