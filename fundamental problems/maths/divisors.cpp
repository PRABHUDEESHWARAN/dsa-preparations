#include<bits/stdc++.h>
using namespace std;
// given a number n print all the divisors of n.
// here we are using the harmonic lemma concept to reduce the time complexity, which states that,
// given an integer its divisors will always exist in pair, soo going till sqrt(n) is enough to find all the divisors.
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
        }
        int k=n/i; // this gives the other pair for the current divisor "i".
        if(k!=i && n%k==0) // checking that both the divisor are not same and whether the newly found divisor from i is also a divisor of n.
        {
            v.push_back(k);
        }
    }
    sort(v.begin(),v.end());
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}