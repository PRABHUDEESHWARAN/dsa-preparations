#include<bits/stdc++.h>
using namespace std;
/*
Stocks buy and Sell: given an array of stock prices that are bought and sold throughout the day,
we are supposed to given the maximum profit that can be made by buying a stock at a current index and selling 
them at the upcoming future index.

The idea here is to use the two pointer approach
    -> i and j pointer at starting index.
    ->initialise the min=v[0], and iterate j till end of the array.
    -> if calculate profit by v[j]-min, and update profit.
    ->if v[j] is found to be less than min update min.
*/

int profit(vector<int> v)
{
    int profit=0;
    int minBuy=v[0];
    for(int j=0;j<v.size();j++)
    {
        int currprofit=v[j]-minBuy;
        profit=max(profit,currprofit);
        minBuy=min(minBuy,v[j]);
    }
    return profit;

}
int main()
{
    vector<int> v={1,2,3,4,5,6,45,2};
    cout<<profit(v);
    return 0;
}