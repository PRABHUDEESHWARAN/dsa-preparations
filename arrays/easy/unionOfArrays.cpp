#include<bits/stdc++.h>
using namespace std;
/*
union of two arrays:
given two arrays you are supposed to return the union of the two arrays in the acending order.
*/

vector<int> unionArray(vector<int> v1,vector<int> v2)
{
    vector<int> v3;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<=v2[j])
        {
            if(v3.size()==0 || v3.back()!=v1[i])
            {
                v3.push_back(v1[i]);
            }
            i++;
        }
        else{
            if(v3.size()==0 || v3.back()!=v2[j])
            {
                v3.push_back(v2[j]);
            }
            j++;
        }
    }
    while(i<v1.size())
    {
        if(v3.size()==0 || v3.back()!=v1[i])
            {
                v3.push_back(v1[i]);
            }
            i++;
    }
    while(j<v2.size())
    {
        if(v3.size()==0 || v3.back()!=v2[j])
            {
                v3.push_back(v2[j]);
            }
            j++;
    }
    return v3;
}
int main()
{

    vector<int> v1={1,2,3,4,5,5,6};
    vector<int> v2={1,2,3,7,9,9,10};
    vector<int> v3;
    v3=unionArray(v1,v2);
    for(int ch:v3)
    {
        cout<<ch<<" ";
    }
    return 0;
}