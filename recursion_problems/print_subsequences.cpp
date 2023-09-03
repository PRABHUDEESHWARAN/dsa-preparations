#include<bits/stdc++.h>
using namespace std;

/*
Print Subsequences / powerset: given an array we need to print all the possible  subsequences.
we can do this by recursion and one another method,
lets see the recursive way here.
---> here we use the concept of take and not take.
    -> when we take an element we find the possible pairs by further recursive calls,
    -> when we dont take an element we find the possible pairs by further recursive calls.
*/
void powerset(int i,int n,vector<int> v,vector<int> ls)
{
    if(i==n)
    {
        for(auto it:ls)
        {
            cout<<it<<" ";
        }
        if(ls.size()==0)
        {
            cout<<"{ }";
        }
        cout<<endl;
        return;
    }
    ls.push_back(v[i]); // take the current index and call the recursion.
    powerset(i+1,n,v,ls);
    ls.pop_back(); // call recursion without the current element.
    powerset(i+1,n,v,ls);

}
int main()
{
    vector<int> v={3,2,1};
    vector<int> ls;
    powerset(0,3,v,ls);
    return 0;
}