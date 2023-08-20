#include<bits/stdc++.h>
using namespace std;
// print the fibo of a given number using recursion.
// f(6)=5  => 0 1 1 2 3 5 
// fibo f(1)=1 f(0)=0.
//using formula for fibo of any number f(n)=f(n-1)+f(n-2);

int fibo_number(int n)
{

    //base condition
    if(n<=1)
    {
        return n;
    }

    //formula
    return fibo_number(n-1)+fibo_number(n-2);
}
void fibo_series(int n)
{
    vector<int> v;
    if(n==1)
    {
        v.push_back(0);
    }
    else{
        v.push_back(0);
        v.push_back(1);
    }
    int i=2;
    while(i<n)
    {
        v.push_back(v[i-1]+v[i-2]);
        i++;
    }
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
}
int main()
{

    int n;
    cin>>n;
    cout<<fibo_number(n)<<endl;
    fibo_series(n);
    return 0;
}
