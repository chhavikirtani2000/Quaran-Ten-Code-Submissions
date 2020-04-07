#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int BonusPoints (vector<int>& rankings)
{
    vector<int> bonus;
    int n=rankings.size();
    for(int i=0;i<n;i++)
    {
        bonus.push_back(0);
    }
    bonus[0]=1;
    for(int i=0;i<n-1;i++)
    {
        if(rankings[i]<rankings[i+1])
        {
            bonus[i+1]=bonus[i]+1;
        }
        else if(rankings[i]==rankings[i+1])
        {
            bonus[i+1]=1;
        }
        else if(rankings[i]>rankings[i+1])
        {
            if(bonus[i]>1)
            {
                bonus[i+1]=1;
            }
            else if(bonus[i]==1)
            {
                int k=i;
                bonus[k]+=1;
                bonus[k+1]=1;
                while(k-1>=0 && rankings[k-1]>rankings[k])
                {
                    bonus[k]+=1;
                    if(bonus[k]!=bonus[k-1])
                    {
                        break;
                    }
                    else
                    {
                        bonus[k-1]+=1;
                    }
                    k--;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=bonus[i];
    }
    return sum;
}
int main()
{
    vector<int> rankings;
    rankings.push_back(1);
    rankings.push_back(2);
    rankings.push_back(2);
    cout<<BonusPoints(rankings);
}