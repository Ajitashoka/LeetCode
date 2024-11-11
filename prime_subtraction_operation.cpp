https://leetcode.com/problems/prime-subtraction-operation/solutions/6032232/binary-search/
Intuition
/*Optimal prime can be computed using binary search.We should construct array such that the difference between the elements should be as small as possible.

Approach
1.Store prime upto 1000 in a vector.
2.Implement a binary search function that computes the optimal prime.
3.Start from the end of the array and if the next element is smaller than the current,the next element should be just 1 smaller than the next to make it strictly increasing.
4.Find the optimal prime to get to the number as mentioned above using BS.

Complexity
Time complexity:
O(NlogN)

Space complexity:
O(N)
*/
class Solution {
public:
    int bin(vector<int>&prime,int num)
    {
        int l=-1;
        int r=prime.size();

        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(prime[mid]<num)
            l=mid;
            else
            r=mid;
        }

        if(r==prime.size())
        return -1;

        return prime[r];
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;

        for(int i=2; i<=1000; i++)
        {
            bool b=1;
            for(int j=2; j*j<=i; j++)
            {
                if(i%j==0)
                {
                    b=0;
                    break;
                }
            }
            if(b)
            prime.push_back(i);
        }
        
        int n=nums.size();
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]>=nums[i+1])
            {
                int t=nums[i]-(nums[i+1]-1);
                int num=bin(prime,t);
                if(num==-1)
                return 0;
                nums[i]=nums[i]-num;
                if(nums[i]<=0)
                return 0;
            }
        }
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]<=nums[i])
            return 0;
        }
        return 1;
    }
};

