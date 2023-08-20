#include<bits/stdc++.h>
using namespace std;
/*
recursive bubble sort: here also we put max/min in last through adjacent swaps but instead of for loop
we are using recursion.(while loop).
-> the outer for loop in bubble sort which is used to iterate till the unsorted part each time is replaced by
the recursion call  which calls itself again and again with decrementing range here.
->the inner for loop in bubble sort which actually puts max/min in the last i.e the sorted part of the array is 
replaced by the while loop.
-> we introduce the base condition (if n==0 return) to break the loop.
*/
void recur_bubble_sort(vector<int> &v,int n) // here n is index not position.
{
    //base condition : when n==0 there are no elements to compare so we break the recur.
    if(n==0)
    {
        return;
    }
    int i=0;
    while(i<n)
    {
        if(v[i]>v[i+1])
        {
            swap(v[i],v[i+1]);
        }
        i++;
    }
    // call recursion for the unsorted part of the array by decrementing and sending value of n.
    return recur_bubble_sort(v,n-1);
}

int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,9,8,6};
    recur_bubble_sort(v,v.size()-1); // sending the index rather than position.
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}