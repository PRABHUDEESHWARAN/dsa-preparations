#include<bits/stdc++.h>
using namespace std;

/*
majority element appearing more than n/2 times.
The intuition here is that the majority element that occurs more than n/2 times will
always be the surivivor among all the other elements.
-> consider the shooting scneraio, if an element appears it will try to be the majority element by shooting the
previous majority element, if an element comes in and the current majority element's  power is zero, then 
the current element will become the majority element.
->At the end after the shootings, the majority element will remain as the surivivor.
*/

int majority(vector<int> v)
{
    int power=1; //initialise the first element as the candidate element with power 1.
    int candidate=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==candidate)
        {
            power++;
        }
        else
        {
            if(power==0)// when a new element arrives if the power of curr candidate is zero then the new 
            {           // element can take the candidate position.
                candidate=v[i];
                power=1; // when a new candidate arrives we are assigning them a power of 1.
            }
            power--;
        }
    }
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==candidate)
        {
            cnt++;
        }
    }
    if(cnt>=(v.size()/2))
    return candidate;
}

int main()
{
    // vector<int> v={7,8,6,7,6,7,2,7,0,7,7,5,7,7};
    vector<int> v={1,2,1,2};
    cout<<majority(v);
    return 0;
}