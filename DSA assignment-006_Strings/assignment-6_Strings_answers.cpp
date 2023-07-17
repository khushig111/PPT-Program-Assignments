// ASSIGNMENT 6

// Q1 LEETCODE 942. DI String Match
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result(s.size() + 1) ;
        int leftPointer =0;
        int rightPointer = s.size();
        int index=0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='I')
            {
                result[index++]=leftPointer++;
            }
            else
            {
                result[index++]=rightPointer--;
            }
        }

        if(s[s.size()-1]=='I')
        {
            result[index]=leftPointer;
        }
        else
        {
            result[index]=rightPointer;
        }

        return result;
    }
};






// Q2 LEETCODE 74. Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()){
            return false;
        }
        
        int n=matrix.size(); //rows
        int m=matrix[0].size(); //cols
        
        int lo=0;
        int h= (n*m)-1;
        
        while(lo<=h){
            
            
            int mid= (lo +(h-lo)/2);
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            
            else if(matrix[mid/m][mid%m] < target){
                lo=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
    }
};







// Q3 LEETCODE 941. Valid Mountain Array
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return false;
        
        int increasing=1;
        for(int i = 1; i< n; i++) {
            
            //if increasing change to 0 i.e if decreasing array is there or not
            if(arr[i] < arr[i-1]){
                if(i == 1){ //always decreasing
                    return false; 
                }
                increasing = 0; 
            }
            
            if(increasing){
                if(arr[i] <= arr[i-1]){
                    return false;
                }
            } else {
                if(arr[i] >= arr[i-1]){
                    return false;
                }
            }
            
        }
        
        if(increasing == 1) return false; //always increasing
        return true;
    }
};





// Q4 LEETCODE 525. Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //time : o(n)
        //space : o(n)

        unordered_map<int,int> mp; 
        
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
        }
        
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum == 0){
                res = max(res, i+1);
            }
            
            if(mp.find(sum)!=mp.end()){ //sum is in map
                res=max(res,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return res;
    }
};







// Q5 LEETCODE  PREMIUM --> 1874 - Minimize Product Sum of Two Arrays
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minProductSum(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B), greater<>());
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) ans += A[i] * B[i];
        return ans;
    }
};






// Q6 LEETCODE 2007. Find Original Array From Doubled Array
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        queue<int> q;
        vector <int> ans;

        sort(changed.begin(), changed.end());

        for(int i : changed)
        {
            if (q.front ()!=i)
            {
                ans.push_back(i);
                q.push(2*i);
            }
            else
            {
                q.pop();
            }
        }
        if(!q.empty())
        {
            return {};
        }

        return ans;
        
    }
};






// Q7 LEETCODE 59. Spiral Matrix II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int up=0, down =n-1, left =0, right=n-1, ct=1;

        while (ct<=n*n){
            for(int j=left; j<=right && ct <=n *n; j++){
                matrix[up][j]= ct ++;
            }

            for(int i= up+1; i<= down -1 && ct <= n*n; i++){
                matrix[i][right]= ct ++;
            }

            for(int j=right; j>=left && ct <=n *n; j--){
                matrix[down][j]= ct ++;
            }

            for(int i=down - 1; i>= up+1 && ct <= n*n; i--){
                matrix[i][left]= ct ++;
            }

            left++ ;
            right-- ;
            up++ ;
            down-- ;
        }
        
        return matrix;
    }
};







// Q8 LEETCODE PREMIUM --> 311 - Sparse Matrix Multiplication
// Time: O(MNK)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int M = A.size(), K = A[0].size(), N = B[0].size();
        vector<vector<int>> ans(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < K; ++k) {
                    ans[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return ans;
    }
};
