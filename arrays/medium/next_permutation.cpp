#include<bits/stdc++.h>
using namespace std;
/*
Next permutation:

Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).


solution:
    -> find the longest prefix match (a[i]<a[i+1]) lets say v[i] at index i.
    -> find the element just greater than the v[i]. if v[i] is 1 and remaining elements to its right are 5,4,3,0,0
    we need to consider 3 here lets say v[j].
    ->swap(v[i],v[j]).
    ->now sort the remaining elements from the index i+1 to n-1 in ascending order so that we get the immediate next permutation.
*/
void nextPermutation(vector<int> &v,int n)
{
    //find longest prefix index 'Pindex'.
    int pIndex=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i]<v[i+1])
        {
            pIndex=i;
            break;
        }
    }

    //finding element just greater than v[i] from i+1 to n-1.
    int min=INT_MAX;
    for(int i=pIndex+1;i<n;i++)
    {
        if(v[i]>v[pIndex] && v[i]<min)
        {
            min=v[i];
        }
    }
    //swap pIndex and the min val.
    swap(v[pIndex],v[min]);
    //sort te remaiing elements.
    sort(v.begin()+pIndex+1,v.end());
}

int main()
{

    vector<int> v={1,3,2};
    nextPermutation(v,v.size());
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}