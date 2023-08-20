#include<bits/stdc++.h>
using namespace std;
/*
Rearrange the given array in alternating pos and neg.
here we are using two pointer approach by pointing the pos and neg places for the upcoming elements to
be inserted.
-> if a neg element appears then we place it in the neg pointer and incr neg pointer by two places.
-> the same goes for the pos number.
-> here we will be using an extra array with space of O(N).
*/
vector<int> rearrange(vector<int> &v)
{
    int pos=0;
    vector<int> temp(v.size(),0);
    int neg=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<0)
        {
            temp[neg]=v[i];
            neg+=2;
        }
        else if(v[i]>0)
        {
            temp[pos]=v[i];
            pos+=2;
        }
    }
    v.clear();
    for(int ch:temp)
    {
        v.push_back(ch);
    }

    return v;
}
int main()
{
    vector<int> v={-1,2,3,-4,-5,4,-1,7};
    rearrange(v);
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}