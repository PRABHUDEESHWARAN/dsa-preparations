#include<bits/stdc++.h>
using namespace std;
/*
Majority element N/3 times.
->Here we need to return the element that appears >=N/3 times.
->For any given array there can only two majority elements.
-> we can use the same approach used for N/2 times.

-> Initiate two candidates c1 and c2 and their powers p1 and p2.
-> Now while iterating through the array if,
            ->p1==0 and v[i]!=c2 => c1=v[i] and init p1=1;
            else if,
            ->p2==0 and v[i]!=c1 => c2=v[i] and init p2=1;
            else if,
            ->v[i] ==c1 then inc power of c1.
            else if,
            ->v[i] ==c2 then inc power of c2.
            else,
            p1-- and p2--;
*/

void majority(vector<int> v,int n)
{
    // here there will be two candidates and each candidate will have power.
    int c1=INT_MIN;
    int c2=INT_MIN;
    int p1=0,p2=0;
    for(int i=0;i<n;i++)
    {
        if(p1==0 && c2!=v[i])
        {
            c1=v[i];
            p1=1;
        }
        else if(p2==0 && c1!=v[i]) 
        {
            c2=v[i];
            p2=1;
        }
        else if(v[i]==c1)
        {
            p1++;
        }
        else if(v[i]==c2)
        {
            p2++;
        }else{
            p1--;
            p2--;
        }
    }
    int k=n/3,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==c1)cnt1++;
        if(v[i]==c2)cnt2++;
    }
    if(cnt1>k) cout<<c1<<" ";
    if(cnt2>k)cout<<c2;

}


int main()
{
    vector<int> v1={11,33,33,11,33,11};
    vector<int> v2={1,2,2,3,2};
    majority(v1,v1.size());
    return 0;
}