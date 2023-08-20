#include<bits/stdc++.h>
using namespace std;
/* 
merge sort: here we are using the divide and conquer strategy.
here we are finding the mid index and calling the merge sort func again with divided ranges from start to mid 
and from mid+1 to end.

then when the indexes are divided and sent and reach a point where there is only one element in the array it means 
that the array with one element is already sorted therefore,
        -> we introduce the base condition as to return when start==end as single element has both start and end same.
        -> Next we send the indexes to the merge function which merges the two subarrays into sorted format.
        -> after the merging is over we replace the original array from start to end with the current sorted part 
        which is stored in temp.
        ->this process continues...till the original array is sorted fully.
*/


void merge(vector<int> &v,int start,int mid,int end)
{
    int i1=start;
    int i2=mid+1;
    int t=0;
    vector<int> temp;
    while(i1<=mid && i2<=end)
    {
        if(v[i1]<=v[i2])
        {
            temp.push_back(v[i1]);
            i1++;
        }
        else{
            temp.push_back(v[i2]);
            i2++;
        }
    }
    while(i1<=mid)
    {
        temp.push_back(v[i1++]);
    }
    while(i2<=end)
    {
        temp.push_back(v[i2++]);
    }

    for(int i=start;i<=end;i++)
    {
        v[i]=temp[i-start];
    }
    
}

void merge_sort(vector<int> &v,int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid=floor((start+end)/2);//finding mid index.
    merge_sort(v,start,mid);
    merge_sort(v,mid+1,end);
    merge(v,start,mid,end);
}


int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,9,8};
    int start=0;
    int end=v.size()-1;
    merge_sort(v,start,end);
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}