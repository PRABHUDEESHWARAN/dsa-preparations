#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    string s=to_string(n);
    int digits=s.length();
    int sum=0;
    temp=n;
    // cout<<power<<endl;
    while(temp!=0)
    {
        int base=temp%10;
        // cout<<base<<" ";
        int val=ceil(pow(base,digits));
        // cout<<val<<endl;
        sum+=val;
        temp/=10;
    }
    // cout<<sum<<" "<<n<<endl;
    if(sum==n)
    {
        cout<<"YES";
    }else cout<<"NO";
    return 0;
}