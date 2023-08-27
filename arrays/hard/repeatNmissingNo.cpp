#include<bits/stdc++.h>
using namespace std;
/*
Find the Repeating and Missing Number:
-> We are given a read only array of size N from [1,N] both inclusive, where
all elements appear exactly once except one element which twice and another 
element that is missing.

Our task is to find the missing element.

-> Here the brute force solution would be to have a frequency array from 1 to N 
with initial values initiated to zero  and given an answer as such by 
traversing the frequency array.
    -> element with freq 2 - repeating element.
    -> element with freq 0 - missing element.
But the above brute force approach uses Linear space O(1),we shall overcome this in the 
optimal approach.

-> we find the sum of first N natural numbers (N*N+1)/2.
-> we find the sum of squares of first N natural numbers [n*(n+1)*(2n+1)]/6.
->Then we solve those two equations to arrive at an answer.
*/
void find(vector<int> v,int n)
{

    //sum of 1st N natural no.
    long long sn=(n*(n+1))/2;
    //sum of square of first N natural no.
    long long s2n=(n*(n+1)*((2*n)+1))/6;

    //sum and sum of square of elem of array.
    long long s=0,s2=0;
    for(int i=0;i<n;i++)
    {
        s+=(long long)v[i];
        s2+=(long long)v[i]*(long long)v[i];
    }
    //eq1 x-y=s-sn.
    long long val1=s-sn;
    //eq2 x^2 -y^2=s2-s2n.
    long long val2=s2-s2n;

    //solve.
    val2=val2/val1; //--> x+y.
    //find x.
    long long x=(val1+val2)/2;
    //find y.
    long long y=x-val1;
    cout<<x<<" "<<y;
    return;

}

int main()
{
    vector<int> v={3,1,2,5,3};
    find(v,v.size());
    return 0;
}