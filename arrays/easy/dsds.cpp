#include <bits/stdc++.h>

using namespace std;

bool isvowel(char ch)
{
    ch=tolower(ch);
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return true;
    }
    return false;
}
int main(int argc, char** argv)
{
string s;
getline(cin,s);
int k=s.length();
int mpp[10001];
for(int i=0;i<k;i++)
{
    if(isvowel(s[i]))
    {
        for(int j=0;j<k;j++)
        {
            if(mpp[j]>0)
            {
                cout<<"["<<s[j]<<"]";
            }
            else if(i==j && mpp[j]==0)
            {
                cout<<"["<<s[j]<<"]";
                mpp[j]++;
            }
            else
            {
                cout<<s[j];
            }
        }
        cout<<endl;
    }
}

}