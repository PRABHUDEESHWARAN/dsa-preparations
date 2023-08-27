#include<bits/stdc++.h>
using namespace std;
/*
Count Inversion: Using merge sort.
    Given an array on N integers count the number of inversions in the array.

    -> An inversion is defined as for i<j a pair {v[i],v[j]} where v[i]>v[j].

    -> Here we are using the merge sort algorithm to find the count of inversions.
    -> here the intuition is that if we have two sorted arrays and an element in the
    left array is greater than an element in the right array, then all the elements
    to the right that particular element in the left array will be greater than the 
    element in the right array so we can just add up the no of right elements to our answer.

    -> have a look on how this is done using merge sort.
    */


int merge(vector<int> &v, int start,int mid,int end)
{
    vector<int> temp;
    int i=start;
    int j=mid+1;
    int ans=0;
    while(i<=mid && j<=end)
    {
        if(v[j]<v[i])
        {
            temp.push_back(v[j]);
            j++;
            ans+=mid-i+1; // only line we add to find count.
        }
        else{
            temp.push_back(v[i]);
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=end)
    {
        temp.push_back(v[j]);
        j++;
    }
    for(int k=start;k<=end;k++)
    {
        v[k]=temp[k-start];
    }
    return ans;
}
int mergesort(vector<int> &v,int start,int end)
{
    int ans=0;
    if(start>=end)
    {
        return ans;
    }
    int mid=(start+end)/2;
    ans+=mergesort(v,start,mid);
    ans+=mergesort(v,mid+1,end);
    ans+=merge(v,start,mid,end);
    return ans;
}



int main()
{
    vector<int> v={5,4,3,2,1};
    int start=0;
    int end=v.size()-1;
    int ans=mergesort(v,start,end);
    cout<<ans;
    return 0;
}