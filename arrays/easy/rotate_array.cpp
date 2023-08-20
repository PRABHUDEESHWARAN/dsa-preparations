#include<bits/stdc++.h>
using namespace std;
// rotate given array by places.


void left_rotate(vector<int> &v,int d)
{
    // by doing several reverses we can rotate the array to the left
    //left rotation is as follows.

    //-> first reverse until d places.
    reverse(v.begin(),v.begin()+d);
    //-> then reverse from d+1 to end places.
    reverse(v.begin()+d,v.end());
    // now reverse the total array.
    reverse(v.begin(),v.end());
}
void right_rotate(vector<int> &v,int d)
{
    // by doing several reverses we can rotate the array to the  right.
    //right rotation is as follows.

    //-> first reverse until d places from last.
    d=v.size()-d;
    reverse(v.begin()+d,v.end());
    //-> then reverse from start to d places from last.
    reverse(v.begin(),v.begin()+d);
    // now reverse the total array.
    reverse(v.begin(),v.end());
}
int main()
{
    vector<int> v={1,2,3,4,5,6,7,8};
    int places=3;
    left_rotate(v,places);
    right_rotate(v,places);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}