#include<bits/stdc++.h>
using namespace std;
/*
Longest Subarray with Sum zero:
    -> for this problem we can use the prefix sum method using a map.
    -> if the current prefix sum is equal to zero we update length variable.
    -> if not then, we check if there is prev subb array possible with sum zero with curr element as
    last member of the subarray.
*/

int Maxlen(vector<int> v,int target)
{
    unordered_map<int,int>mpp;
    int psum=0;
    int len=0;
    for(int i=0;i<v.size();i++)
    {
        psum+=v[i];
        if(psum==0)
        {
            len=max(len,i+1);
        }
        else{
            int rem=psum-target;
            if(mpp.find(rem)!=mpp.end())
            {
                len=max(len,i-mpp[rem]);
            }
        }
        if(mpp.find(psum)==mpp.end())
        {
            mpp[psum]=i;
        }
        else if(mpp[psum]>i)
        {
            mpp[psum]=i;
        }
    }
    return len;
}

int main()
{
    vector<int> v={1, 3, -5, 6, -2};
    int target=0;
    cout<<Maxlen(v,target);
    return 0;
}