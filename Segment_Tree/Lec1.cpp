#include <iostream>
#define inf 1e9;
using namespace std;
int query(int *tree,int s,int e,int qs,int qe,int index){
    //complete overlap
    if(qs<=s && qe>=e){
        return tree[index];
    }
    //no overlap
    if(qs>e || qe<s){
        return inf;
    }
    int mid = (s+e)/2;
    int ans1 = query(tree,s,mid,qs,qe,2*index);
    int ans2 = query(tree,mid+1,e,qs,qe,2*index+1);
    return min(ans1,ans2);
}
void updatenode(int* tree,int s,int e,int i,int increment,int index){
    //no overlap
    if(i<s || i>e){
        return;
    }
    if(s==e){
        tree[index]+=increment;
        return;
    }
    int mid = (s+e)/2;
    updatenode(tree,s,mid,i,increment,2*index);
    updatenode(tree,mid+1,e,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}
void build_tree(int* a,int s,int e,int* tree,int index){
    if(s==e)
    {
        tree[index] = a[s];
        return;
    }
    int mid = (s+e)/2;
    build_tree(a,s,mid,tree,2*index);
    build_tree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index+1],tree[2*index]);
    return;
}
void Update_range(int *tree,int s,int e,int us,int ue,int increment,int index){
    if(ue<s || us>e){
        return;
    }
    if(s==e){
        tree[index]+=increment;
        return;
    }
    int mid = (s+e)/2;
    Update_range(tree,s,mid,us,ue,increment,2*index);
    Update_range(tree,mid+1,e,us,ue,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}
int main() {
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    int* tree = new int[4*n+1];
    build_tree(a,0,n-1,tree,1);
    //cout<<query(tree,0,n-1,2,4,1);    
    //updatenode(tree,0,n-1,3,10,1);
    //cout<<query(tree,0,n-1,1,2,1);
    Update_range(tree,0,n-1,0,3,10,1);
    cout<<query(tree,0,n-1,0,n-1,1);
    return 0;
}

