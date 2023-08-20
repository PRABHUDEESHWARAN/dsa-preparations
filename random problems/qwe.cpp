// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    vector<int> v,q;
    unordered_set<int> s;
    for(int i=0;i<a;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
    }
    for(int i=0;i<a-1;i++)
    {
        int max=v[i];
        for(int j=i+1;j<a;j++)
        {
            if(v[j]>max && s.find(v[j])==s.end())
            {
                max=v[j];
                
            }
        }
        s.insert(max);
        q.push_back(max-v[i]);
    }
    for(int ch:q)
    {
        cout<<ch<<" ";
    }
    sort(q.begin(),q.end(),greater<int>());
    for(int ch:q)
    {
        cout<<ch<<" ";
    }
    cout<<q[0]+q[1];
    return 0;
}