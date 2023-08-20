#include<bits/stdc++.h>
using namespace std;
/*
move zeroes to the end: two pointer approach.
    -> the idea is to keep two pointers i and j.
    -> traverse the given array once and assign i to the first occurence of 0.
    ->initialise j to i+1, and traverse from j = i+1 to end of the array.
    -> if at a particular index arr[j]!=0, the swap arr[i] and arr[j], now i will be pointing at non zero value,
    so increment the value of index i to i+1.
    -> this process continues till j reaches the end of the array.
    */

void moveZeroes(vector<int> &v)
{
    int i,j;
    for(i=0;i<v.size();i++) // setting i to first occurrence of zero.
    {
        if(v[i]==0)
        {
            break;
        }
    }
    for(int j=i+1;j<v.size();j++)
    {
        if(v[j]!=0)
        {
            swap(v[i],v[j]);
            i=i+1;
        }
    }
}
int main()
{
    vector<int> v={0,1,0,0,0,1,1,1,0,1,0,0,1};
    moveZeroes(v);
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}