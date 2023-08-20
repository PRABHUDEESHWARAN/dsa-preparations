#include<bits/stdc++.h>
/*
the program must accept the names of the names if the colors
in an LED having same clr at begining and in the end.Also consider 
each LED in the given LED serial ser as a grp.

Finally the program must print the number of groups of LEDs as output.

*/
using namespace std;

int main(int argc, char** argv)
{
vector<string> v;
string s;
while(cin>>s)
{
    v.push_back(s);
}
int k=v.size(),cnt=0;
unordered_map<string,int> mpp;
for(int i=0;i<k;i++)
{
    cnt++;
    if(mpp.find(v[i])!=mpp.end())
    {
        cnt+=mpp[v[i]];
    }
    mpp[v[i]]++;
}
cout<<cnt;
}