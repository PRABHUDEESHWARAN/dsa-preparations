#include<bits/stdc++.h>
using namespace std;

/*
Find the longest subarray with the given sum which contains only positives.
-> the better approach is to use the prefix sum method.
->the optimal approach would be to use two pointer approach.
-> If there are negatives  then the prefix method is the optimal solution.
->if there are only positives then two pointer is the optimal solution.
*/


//using two pointer approach.
int l_subSum(vector<int> v,int t)
{
    int maxLen=0,n=v.size();
    int i=0,j=0;
    int currsum=v[0];
    while(j<n)
    {
        //if currsum>t then decrement the currsum till it is <t by incrementing the i pointer and subtracting its
        //value from currsum.
        while(i<=j && currsum>t)
        {
            currsum-=v[i];
            i++;
        }

        //if currsum==target, update the maxLen value by comparing with curr subarray length.
        if(currsum==t)
        {
            maxLen=max(maxLen,j-i+1);
        }

        //now we can go to the next index by incrementing j.
        j++;
        if(j<n)currsum+=v[j];
        
    }






    return maxLen;
}


// using prefixsum approach.
// the idea here is if the sum till the current index is not target then we can find if any 
//subarray with the current index as the last value could form a sum of the given target by subtracting
//the target from psum and checking if that remainder sum has occured before in previous iterations.
//If there is a sum of the remainder present then we can update length of mlen.

int prefix_sum_app(vector<int> v,int target)
{
    int psum=0,mlen=0; //declare prefidx sum and max len.
    unordered_map<int,int>mpp; // map for accessing previous sum and their index of occurrence values.
    for(int i=0;i<v.size();i++)
    {
        psum+=v[i];
        if(mpp.find(psum)==mpp.end())// if sum is not present already then we add value to the map.
        {
            mpp[psum]=i;
        }
        if(psum==target)// if the psum till the current index equals to the target then update mlen.
        {
            mlen=max(mlen,i+1);
        }
        else{
            int rem=psum-target; //reverse mathematics.
            if(mpp.find(rem)!=mpp.end())
            {
                mlen=max(mlen,i-mpp[rem]);
            }
        }
    }
    return mlen;
}
int main()
{

    vector<int> v={1,2,3,2,3,5,1,2,4};
    int target=13;
    cout<<l_subSum(v,target)<<endl;
    cout<<prefix_sum_app(v,target);
    return 0;
}