#include<bits/stdc++.h>
using namespace std;
/*
    Max consecutive ones in the array.

    -> the idea is to keep two variables currcount and maxcount, for each val in arr increment currcount if val==1
    and if currcount >maxcount update maxcount, at any moment the streak is broken that is val!=1 reset currcount to 0.
*/
int maxones(vector<int> v)
{
    int count=0,mcount=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==1)
        {
            count++;
            if(count>mcount)
            {
                mcount=count;
            }
        }
        else
        {
            count=0;
        }
    }
    return mcount;
}
int main()
{
    vector<int> v={1,1,1,2,1,1,1,1,1,2,3,1,1,1};
    cout<<maxones(v);
    return 0;
}