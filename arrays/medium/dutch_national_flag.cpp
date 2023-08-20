#include<bits/stdc++.h>
using namespace std;
/*
sort array of 0's,1's and 2's using dutch national flag algorithm.
-> The algorithm states that,
        -> we put every low element in the left and every high element in the right 
        then the middle element will automatically sort themselves in the between low and high values.

        ->Now, we keep three pointers low,mid, and high.
        ->keep low and mid at first element.
        ->high at last element.
        ->As there are only three values 0,1,2 we will have three scenarios.
            -> if arr[mid]=0 : swap(low,mid) low++ , mid++;
            -> if arr[mid]=1 : dont do anything continue. mid++;
            -> if arr[mid]=2 : swap(high,mid) high--;
*/
void DNF(vector<int> &v)
{
    int low=0,mid=0,high=v.size()-1;
    while(mid<high)
    {
        if(v[mid]==0)
        {
            swap(v[low],v[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1)
        {
            mid++;
        }
        else if(v[mid]==2)
        {
            swap(v[mid],v[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> v={2,1,1,2,2,0,1,0,1,2,0,1,0,1,2,1,0};
    DNF(v);
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}