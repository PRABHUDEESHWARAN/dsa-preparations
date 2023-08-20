#include<bits/stdc++.h>
using namespace std;

// check if a number is prime by iterating till sqrt of n times to get optimal time complexity.
int main()
{
    int n;
    cin>>n;
    // cout<<n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cout<<"not prime";
            return 1;
        }
    }
    cout<<"is prime";
    return 0;
}