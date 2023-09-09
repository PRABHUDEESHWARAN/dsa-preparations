#include<bits/stdc++.h>
using namespace std;
/*
Job scheduling Problem:
    -> we are given N jobs where each job is associated with a deadline and a profit associated with it.
    -> we need to find the number of jobs that can be done such that it results in maximum profit.
    -> each job takes 1 unit of time.
        eg: for job j1 with deadline 4 and profit 60, the job j1 can with done within the time interval 4 at any unit of time
        like it can done at 1 or 2 or 3 or 4.
    -> but here the intuition is to choose the maximum profit job first and do it in the last moment of time so that all other
    jobs within the range of the deadline of this process can be done within it.
    -> for eg. if job j1 has deadline 6 and profit 100 then, j1 will be done only at 6th unit of time and by doing so we can 
    allocate other spaces from 1 to 5 for other jobs.

steps:
    ->sort the input data in the order of their maximum profit in descending order.
    ->find the maximum deadline overall for all the provided jobs and init an array with initial value -1.
    ->ierate through the sorted data and place the jobs in the maximum possible deadline by assigning the value
    in the allocation array to the job id.

*/
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution
{
public:
    bool static comp(Job j1,Job j2)
    {
        return j1.profit>j2.profit;
    }
    pair<int,int> JobScheduling(Job arr[],int n)
    {
        pair<int,int> ans;
        sort(arr,arr+n,comp);
        int d=arr[0].dead;
        for(int j=1;j<n;j++)
        {
            Job ch=arr[j];
            d=max(d,ch.dead);
        }
        vector<int> assigned(d+1,-1);
        
        int jobs=0;
        int profit=0;
        for(int j=0;j<n;j++)
        {
            Job ch=arr[j];
            int deadline=ch.dead;
            for(int i=deadline;i>=1;i--)
            {
                if(assigned[i]==-1)
                {
                    assigned[i]=ch.id;
                    jobs++;
                    profit+=ch.profit;
                    break;
                }
            }
        }

        ans={jobs,profit};
        return ans;
    }

};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;
   
   return 0;
} 