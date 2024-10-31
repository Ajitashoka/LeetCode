https://leetcode.com/problems/minimum-total-distance-traveled/description/
class Solution {
public:
    long long DFS(vector<int>& a,vector<vector<int>>&b,int i,int j,vector<vector<vector<long long>>>&dp)
    {
        if(i==a.size())
        return 0;
        if(j==b.size())
        return 1e18;

       if(dp[i][j][b[j][1]]!=-1)
       return dp[i][j][b[j][1]];

        long long num1=DFS(a,b,i,j+1,dp);
        long long num2=1e18;
        if(b[j][1]>0)
        {
            b[j][1]--;
            num2=abs(a[i]-b[j][0])+DFS(a,b,i+1,j,dp);
            b[j][1]++;
        }
        else
        num2=DFS(a,b,i,j+1,dp);

        return dp[i][j][b[j][1]]=min(num1,num2);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<vector<vector<long long>>> dp(robot.size(),vector<vector<long long>>(factory.size(),vector<long long>(101,-1)));
        long long num=DFS(robot,factory,0,0,dp);
        return num;
    }
};
