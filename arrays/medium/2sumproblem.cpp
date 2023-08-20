#include<bits/stdc++.h>
using namespace std;
/*
2sum problem: given an array and a target value, we need to tell if there exist two numbers such
that their sum is equal to the target.

TWO VARIANTS: return yes/no or return indices.
for this the optimal solution will be to,
    -> sort the array.
    -> keep two pointers at the left anf right i & j resp.
    ->we run a while loop for i<j and if v[i]+v[j]<target we increment i, as the array
    is sorted and we need a greater value than the current sum, we increment i from left.
    -> and if sum v[i]+v[j]>target then we decrement j as the array is sorted and we need a 
    smaller value than the current sum to meet the target, we decrement the j.
    ->this is a greedy algorithm and this two pointer approach is possilble only when
    the array is sorted.
*/
void issum(vector<int> v,int target)
{
    //two pointer approach.
    int i=0,j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]<target)
        {
            i++;
        }
        else if(v[i]+v[j]>target)
        {
            j--;
        }
        else{// here v[i]+v[j]=target so we can print "yes".
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}

int main()
{
    vector<int> v={1,2,4,5,6,7,4,6,9};
    int target=23;
    issum(v,target);
    return 0;
}