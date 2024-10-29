https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/5975967/binary-search-prefix-sum/
class Solution {
public:
    vector<vector<int>> prefix;
    //Prefix Sum
    bool check(int row,int col,int n,int m,int mid)
    {

        //check the number of ones in the possible square.
        int num=0;
        if(row+mid<n && col+mid<m)
        {
            if(row==0 && col==0)
            num=prefix[row+mid][col+mid];
            else if(row==0)
            num=prefix[row+mid][col+mid]-prefix[row+mid][col-1];
            else if(col==0)
            num=prefix[row+mid][col+mid]-prefix[row-1][col+mid];
            else
            num=prefix[row+mid][col+mid]-prefix[row+mid][col-1]-(prefix[row-1][col+mid]-prefix[row-1][col-1]);
        }
        if(num==(mid+1)*(mid+1))
        return true;
        return false;
    }
    int expand(int row,int col,int n,int m,vector<vector<int>>&ans)
    {
        //binary Search
        int l=-1;
        int r=ans.size();
        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(check(row,col,n,m,mid))
            l=mid;
            else
            r=mid;
        }
        return l;
    }
    int countSquares(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        //Prefix Sum Preparation
        prefix=vector<vector<int>>(n,vector<int>(m,0));
        for(int j=0; j<m; j++)
        {
            if(j==0)
            prefix[0][j]=matrix[0][j];
            else
            prefix[0][j]=prefix[0][j-1]+matrix[0][j];
        }
        for(int i=1; i<n; i++)
        {
            int num=0;
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==1)
                num++;
                prefix[i][j]=num+prefix[i-1][j];
            }
        }

        int num=-1;
        int val=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // check for each cell and add the answer 
                val+=expand(i,j,n,m,matrix)+1;
                cout<<endl;
            }
        }
        return val;
    }
};
