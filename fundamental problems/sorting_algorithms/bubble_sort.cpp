#include<bits/stdc++.h>
using namespace std;
// bubble sort: put max/min in last using adjacent swaps.
// The idea is to iterate through the given array and at each iteration we will be sending the min/max element to the last.
// and the next iteration will be only till the unsorted part i.e
// for i->0  loop from 0 to n-1  after this loop last element of the array will be the maximum ele of the array.
//next loop for i->1 loop from 0 to n-2 becoz in the prev loop last position is occupied.
void bubble_sort(vector<int> &v,int n)
{

for(int i=n-1;i>=0;i--)
{
    for(int j=0;j<i;j++) // we go <i becoz when we are swapping we would go only till last before element.   i-1=n-2 i=n-1 .
    {
        if(v[j]>v[j+1])
        {
            int temp=v[j];
            v[j]=v[j+1];
            v[j+1]=temp;
        }
    }
}
    return;
}
int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,9,8,6};
    bubble_sort(v,v.size());
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}