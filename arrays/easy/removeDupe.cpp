#include<bits/stdc++.h>
using namespace std;
/*
remove duplicates from array.
given an array remove  duplicate values from the array.

here if we are asked to return the count of the elements after removing the duplicates, 
    -> we can use a two pointer approach. i and j.
    ->initialise i=0 and j=1.
    ->iterate j from 1 to end of the array and if arr[j]!=arr[i], the arr[j] takes the place next to the arr[i].
    ,that is arr[i+1].
    -> this continues till j reaches the end of the array.
    ->At the end the i index will denote the total number of elements present after removal of duplicates.
    so return i+1.

    ->for printing or returning the array after removal, use frequency array or map.
*/
int count(vector<int> arr)
{
    int i=0;
    for(int j=1;j<arr.size();j++)
    {
        if(arr[i]!=arr[j])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}
int remove_duplicates(vector<int> &arr)
{

    int i=0;
    for(int j=1;j<arr.size();j++)
    {
        if(arr[i]!=arr[j])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
    
}
int main()
{
    vector<int> v={1,1,1,1,2,2,2,2,2,3,3};
    //count of elem after removing dupes.
    cout<<count(v)<<endl;
    int len=remove_duplicates(v);
    for(int i=0;i<len;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}