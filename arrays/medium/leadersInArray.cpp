#include<bits/stdc++.h>
using namespace std;
/*
Leaders in the Array: Given an array, print all the elements which are leaders.
A Leader is an element that is greater than all of the elements on its right side in the array.

Here in order to check whether the current element is leader or not, we need to know the largest element 
to its right, if the current element is greater than that largest element then we can say our current element 
is a leader.

-> for this approach we maintain a variable maxElement and traverse the array from the last.
->Now if you understood the above intuition,take a look at the code below to understand fully.
*/


void leaders(vector<int> v,int n)
{
int maxElement=INT_MIN;
for(int i=n-1;i>=0;i--)
{
    if(v[i]>maxElement)
    {
        maxElement=v[i];
        cout<<v[i]<<" ";
    }
    
}

}

int main()
{
    vector<int> v={10,22,12,3,0,6};
    leaders(v,v.size());
    return 0;
}