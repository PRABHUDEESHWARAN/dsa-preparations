#include<bits/stdc++.h>
using namespace std;
/*
insertion sort: placing element in the crt position using swapping to the left.
The intuition is to iterate through the array and for each value at the current index we are placing the value in its appropriate 
position to the left through swapping, so the current element kind of gets inserted in the crt position to the left.Where as in 
bubble sort the max or min value get bubbled to the last by swapping.

The main difference between insertion and bubble sort is that in insertion sort the current element gets placed in the correct 
position whereas in bubble sort we wont know which element will go to the sorted part of the array at last.

*/

void insertion_sort(vector<int> &v,int n)
{

    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0)
        {
            if(v[j]<v[j-1])
            {
                int temp=v[j];
                v[j]=v[j-1];
                v[j-1]=temp;
            }
            j--;
        }
    }
    return;
}


int main()
{
    vector<int> v={5,7,5,3,6,7,8,3,2,5,732,67,5,32,4,6,3,5,8,9,234,45,6,2,4235,667,78,7889,12,3,34,9,8,6};
    insertion_sort(v,v.size());
    for(int ch:v)
    {
        cout<<ch<<" ";
    }
    return 0;
}