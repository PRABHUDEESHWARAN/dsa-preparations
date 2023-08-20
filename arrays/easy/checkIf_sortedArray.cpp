#include<bits/stdc++.h>
using namespace std;
/*
check if a given array is sorted.
*/

std::string issorted(vector<int> v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>v[i+1])
        {
            return "array not sorted";
        }
    }
    return "array is sorted";
}
int main()
{
    vector<int> v={1,1,1,1,2,2,2,2,2,3,3};
    cout<<issorted(v);
    return 0;
}