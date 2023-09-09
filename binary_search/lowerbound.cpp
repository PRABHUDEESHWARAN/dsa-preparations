#include<bits/stdc++.h>
using namespace std;
/*
LowerBound in binary search : given a sorted array and an integer x we need to find the lowerbound of the integer x in the array,
if lowerbound not found in array then return length of the array.

What is lowerbound?
    -> given a sorted array and a value x, the lowerbound is\
                -> the smallest index value that is greater than or equal to x.
*/
int lowerBound(vector<int> arr,int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}