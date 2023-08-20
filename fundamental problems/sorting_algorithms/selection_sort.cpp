#include<bits/stdc++.h>
using namespace std;
/*
Selection sort: "select minimum and swap"
    -> here we iterate the given array and for each iteration we run another loop to choose the min/max element and we replace
    it with the current index of the outer loop.

*/
void selection_sort(vector<int> &v,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=INT_MAX;
        int index=0;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[i] && v[j]<min)
            {
                min=v[j];
                index=j;
            }
        }
        int temp=v[i];
        v[i]=v[index];
        v[index]=temp;
    }


    return;
}
int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,9,8,6};
    selection_sort(v,v.size());
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}