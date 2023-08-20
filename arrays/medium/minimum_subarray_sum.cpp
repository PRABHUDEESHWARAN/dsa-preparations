#include<bits/stdc++.h>
using namespace std;
/* To find the minimum sub array sum,
    ->first declare the sum and min variable.
    ->intialise min to int_max.
    ->Intuition:the idea is to make the sum to 0 whenever the sum is greater than zero, so that we can get the least possible sum.The reason we make sum to zero when sum>0 is becoz whenever we add a value(+or-) to a positive number its going to
    give a value which is greater than the value that is added. Since we need the minimum only the (value) alone can be kept
    instead of adding it to a positive sum.
    ->compare to a global variable "min" and update the min sum each time.
    ->print min.
  */  
int main()
{
    int n;
    cin>>n;
    int sum=0,min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        sum+=val;
        if(sum<min)
        {
            min=sum;
        }
        if(sum>0)
        {
            sum=0;
        }
    }
    cout<<min;
    return 0;
}