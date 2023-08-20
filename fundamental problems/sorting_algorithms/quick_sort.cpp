#include<bits/stdc++.h>
using namespace std;
/*
quick sort:
this sorting algorithm involves sorting the given array by choosing a pivot element and placing it in the
correct position.
    -> so, how can we place the chosen pivot element in the correct position.
    -> the idea is to place all the elements greater than the pivot on the right of pivot and all the elements 
    smaller than the pivot in the left of the pivot.
->After partitioning the partition function returns the index of the pivot which has now been placed in the correct 
position.
->we now use the pivot index to again call the quick sort for the subarray to the left of the pivot and to the right
of the pivot.
-> 


*/
int partition(vector<int> &v,int start,int end)
{
    int pivot=v[start];
    int i=start;
    int j=end;

    while(i<j)
    {
        while(v[i]<=pivot && i<end) // finding the next greatest element than the pivot.
        {
            i++;
        }
        while(v[j]>pivot && j>start)// finding the next smallest element than the pivot.
        {
            j--;
        }

        if(i<j)
        {
            swap(v[i],v[j]); // swapping the smaller and the greater element which has been found till i<j.
        }
    }
    swap(v[j],v[start]);// swapping the the pivot the value at index j, as the j and i has crossed each other.
    return j;

}

void quick_sort(vector<int> &v,int start,int end)
{
    if(start<end)
    {
        int pivot=partition(v,start,end);// getting pivot after putting element greater than pivot to pivot's right
        // elements lesser than pivot to pivot's left.

        //calling quick sort for left partition.
        quick_sort(v,start,pivot-1);
        //calling quick sort for right partition.
        quick_sort(v,pivot+1,end);
        
    }
}
int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,9,8};
    int start=0;
    int end=v.size()-1;
    quick_sort(v,start,end);
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}