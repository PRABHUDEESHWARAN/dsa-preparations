#include<bits/stdc++.h>
using namespace std;
/*
Binary Search: Given an array we need to perform the binary search and return the index of the element to be searched
if not found return -1;
-> we will have three pointer low,mid high.
->we will recursively call the search function with trimmed down search space, here search space is the elements
between the low and high.
-> trimming conditions:
    -> if(v[mid]==target) return mid as asnwer.
    -> if(v[mid]>target) then our target is within the mid range so trim down high to mid-1.
    -> if(v[mid]<target) then our target is after the mid range ,so trim up the low to mid+1.
    -> we do all this if(low<=high) as only on that condition our search space exists.


*/
void find(vector<int> v,int n,int target,int low,int mid,int high)
{
    if(low<=high)
    {
        if(v[mid]==target)
        {
            cout<<" element "<<target<< " at "<<mid;
            return;
        }
        else if(v[mid]<target)
        {
            low=mid+1;
            find(v,n,target,low,(low+high)/2,high);
        }
        else if(v[mid]>target)
        {
            high=mid-1;
            find(v,n,target,low,(low+high)/2,high);
        }
    }
}
void binary_search(vector<int> v,int n,int target)
{
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    find(v,n,target,low,mid,high);
    
}


int main()
{


    vector<int> v={1,2,3,4,5,6,7,8,9};
    int n=v.size();
    int target=6;
    binary_search(v,n,target);
    return 0;
}