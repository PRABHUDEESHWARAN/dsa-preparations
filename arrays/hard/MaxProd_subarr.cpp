#include<bits/stdc++.h>
using namespace std;
/*
Maximum product subarray:
-> here we are given an array of integers and we are supposed to find the maximum 
product that any subarray in the array can produce.
->This problem can be approached with few observations.
        -> if all are positive product of array will be ans.
        -> if even neg and pos then also prod of array.
        -> if odd neg and other pos, then we need to be careful to avoid one particular
        negative integer, and that we can do by findinf product of elements going from 
        front as well as from back in that case we can meet up with all possible neg num
        ommisions, do it with a example to understand.
        -> at any cost if we encounter a zero we fall back the product back to 1 for both
        the prefix as well as suffix product.
*/
int maxProductSubArray(vector<int> arr)
{
    int prefix_sum=1,suffix_sum=1;
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            prefix_sum=1;
        }
        if(arr[n-i-1]==0)
        {
            suffix_sum=1;
        }
        prefix_sum*=arr[i];
        suffix_sum*=arr[n-i-1];
        ans=max(ans,max(prefix_sum,suffix_sum));
    }
    return ans;
}




int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}