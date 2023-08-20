#include<bits/stdc++.h>
using namespace std;

/*
Find the number that appears once and other numbers twice.
-> we are given an array where all elements occur twice except one element and we are supposed to return that element.
-> if we observe all the elements in the array have a pair except one element, therefore we can use the xor operation between
all the elements in the array and the result will be the number that appears once.

*/
int main()
{
    int n;
    cin>>n;
    int res;
    cin>>res;
    for(int i=1;i<n;i++)
    {
        int val;
        cin>>val;
        res=res^val;
    }
    cout<<res;
    return 0;
}