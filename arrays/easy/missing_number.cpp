#include<bits/stdc++.h>
using namespace std;
/*
Missing number in an array: 
    given an array find the missing number in the sequencial order.
    -> find the sum from 1 to n and also the sum of the given numbers.
    -> their difference is the missing number.
    -> another optimal solutionw would be to perform the xor operation between the pairs.
*/
int main()
{
    int n,sum1=0,sum2=0;
    cin>>n;
    vector<int> v;
    // we can also use the sum of first n natural numbers formula : (n*(n+1))/2.
    for(int i=0;i<n-1;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
        sum2+=val;
        sum1+=i+1;
    }
    sum1+=n;
    cout<<sum1-sum2;

    return 0;
}