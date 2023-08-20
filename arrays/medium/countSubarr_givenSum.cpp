#include<bits/stdc++.h>
using namespace std;
/*
Count of subarrays with given sum.

Here we can use the same method used in the "longest subarray with given sum" where we have used prefix sum method.

*/
int count(vector<int> v,int t)
{
    unordered_map<int,int>mpp;
    int psum=0,cnt=0;
    for(int i=0;i<v.size();i++)
    {
        psum+=v[i];
        
        if(psum==t)
        {
            cnt++;
        }
        int rem=psum-t;
        cnt+=mpp[rem];
        mpp[psum]++;


    }
    return cnt;
}

int main()
{

    vector<int> v={1,2,3,2,3,5,1,2,4};
    int target=13;
    cout<<count(v,target);
    return 0;
}