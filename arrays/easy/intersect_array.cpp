#include<bits/stdc++.h>
using namespace std;

/*
Given two arrays, intersect them in the sorted order.
-> The intition here is to move both the pointers if they match but if they dont move only the i pointer.
-> There will be no loops for adding the remaining elements left over because they dont have a pair.
*/

vector<int> IntersectArray(vector<int> v1,vector<int> v2)
{
    vector<int> v3;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]==v2[j]) // if pair found we dont take the same pair again so move both i and j.
        {
            v3.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j])// if v1[i]<v2[j], then since array is sorted we cant find v1[i] in v2 array further,
        {                      // therefore we move i till we find a match or an ele greater than v2[j].
            i++;
        }
        else{   // if v1[i]>v2[j] then  again since array is sorted we cant find v2[j] in v1 array further so we 
                // move j till we find a match or we find an element greater than v1[i];
            j++;
        }
    }
    return v3;
}
int main()
{

    vector<int> v1={1,2,3,4,5,5,9,76,101};
    vector<int> v2={1,2,3,7,9,9,10,76,81,101};
    vector<int> v3;
    v3=IntersectArray(v1,v2);
    for(int ch:v3)
    {
        cout<<ch<<" ";
    }
    return 0;
}