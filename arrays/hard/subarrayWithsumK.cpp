
#include<bits/stdc++.h>
using namespace std;
/*
Subarray with sum K: given an array and a sum k, we need to return al the subarray that form a sum k.
Note: here they want subarray not subsequence.
    -> so for subarray we can just use two pointer method.
    -> incase of subsequence we could use recursion method.

    Intuition: here we are keeping two pointers i and j initialized to zero.

    -> keep on moving the j pointer adding values to sum as well as the data structure.
    -> when sum==k ds answer into ans.
    -> if sum is greater than k then move i pointer forward and decrement sum by that i pointer value as well as pop the data from
    the front of the data that carries the answer. 


*/
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    long long sum=0;
    vector<vector<int>> ans;// answer ds.
    vector<int> ds; // subarray ds
    int n=a.size();
    int i=0,j=0;
    while(i<n && j<n)
    {
        sum+=a[j];
        ds.push_back(a[j]);
        
        if(sum==k)
        {
            ans.push_back(ds);
        }
        else if(sum>k)
        {
            while(sum>k)
            {
                sum-=a[i];
                ds.erase(ds.begin());
                i++;
            }
            if(sum==k)
            {
                ans.push_back(ds);
            }
        }
        j++;
        
    }
    return ans;
}




int main()
{
    long long k=3;
    vector<int> a={1,2,3};
    vector<vector<int>> ans=subarraysWithSumK(a,k);
    cout<<ans.size();
    return 0;
}