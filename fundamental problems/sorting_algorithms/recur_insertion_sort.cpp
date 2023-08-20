#include<bits/stdc++.h>
using namespace std;

/*
    recursive insertion sort: here also we place current index elements in the correct position by swapping to the
    left but using recursion.

    -> the outer for loop in insertion sort which will iterate the array from 0 to n-1 is replaced by the recursion
    call here.
    -> the placing of the curr index element in  its correct position to the left is performed  by the while loop 
    here.
    -> base condition: when the current index crosses the length of array we break the loop.
*/


void recur_insertion_sort(vector<int> &v,int currIdx,int n)
{
    //base condition.
    if(currIdx>n) // return when the curr index has passed the length of the array.
    {
        return;
    }
    int i=currIdx;
    while(i>0)
    {
        if(v[i]<v[i-1])
        {
            swap(v[i],v[i-1]);
        }
        i--;
    }

    return recur_insertion_sort(v,currIdx+1,n); // passing next index so that sort can occur from that index to the left
    // of that index.
}
int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,9,8,6};
    recur_insertion_sort(v,0,v.size()-1); // sending the index rather than position.
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}