#include<bits/stdc++.h>
using namespace std;
// KADANE'S ALGORITHM.
/* To find the maximum sub array sum,
    ->first declare the sum and max variable.
    ->intialise max to int_min.
    ->Intuition:the idea is to make the sum to 0 whenever the sum is less than zero, so that we can get the maximum possible sum.
    The reason we make sum to zero when sum<0 is becoz whenever we add a value(+or-) to a negative number its going to
    give a value which is lesser than the value that is added. Since we need the maximum, only the (value) alone can be kept
    instead of adding it to a negative sum.
    ->compare to a global variable "max" and update the max sum each time.
    ->print max.
  */ 
int main()
{
    int n;
    cin>>n;
    int sum=0,max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        sum+=val;
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<max;
    return 0;
}