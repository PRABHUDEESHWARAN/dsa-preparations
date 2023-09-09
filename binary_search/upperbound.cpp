#include<bits/stdc++.h>
using namespace std;
/*
Implement upper bound in binary search: given a sorted array and an element X, we need to find the upper bound of that element in 
the array, if there is no upper bound 3element in the array then return the length of the array.

What is upper bound?..
        -> The upper bound of a given element in the given sorted array is,
                -> The smallest index element in the array which is greater than X.
*/
int upperBound(vector<int> &arr,int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=n; // init ans to n if there are no suitable answers in the given array.
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>x)
        {
            high=mid-1;
            ans=mid;
        }
        else if(arr[mid]<=x)
        {
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8,9, 15, 19};
    int n = 6, x = 9;
    int ind = upperBound(arr, n, x);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}