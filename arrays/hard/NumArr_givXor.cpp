#include<bits/stdc++.h>
using namespace std;
/*
Count number of subarrays with given Xor K.
-> we are following the same method as prefix sum.
in Prefix sum we found remainder by,
                -> rem=sum-target.
But in Xor we do by,
                -> rem=xr^k     the prefix xor is xr and we need subarr with xor k and we know x^k=xr
                                mul by k on both sides,
                                        -> x^k^k=xr^k;
                                        ->x=xr^k;
-> make sure {0,1} is present in the map beforehand.
*/

int count(vector<int> v,int k)
{
    unordered_map<int,int> mpp;
    int prefix_xr=0;
    mpp[prefix_xr]++;
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        prefix_xr^=v[i];
        int rem=prefix_xr^k;
        cnt+=mpp[rem];
        mpp[prefix_xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> v={5, 6, 7, 8, 9};
    int k;
    cin>>k;
    cout<<count(v,k);
    return 0;
}