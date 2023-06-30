//ASSIGNMENT - 5

// Q1 LEETCODE 2022. Convert 1D Array Into 2D Array
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> v (m,vector<int>(n));

        if(m*n != original.size())
        {
            return {};
        }
        for(int i=0; i<m ; i++){
            for 
            (int j=0; j<n; j++){
                v[i][j] = original[n*i+j];
            }
        }
        return v;        
    }
};






//Q2 LEETCODE 441. Arranging Coins
class Solution {
public:
    int arrangeCoins(int n) {
       //  1+2+3+.....+ k = k(k+1)/2

       long long k= sqrt(2*(long long)n);
       long long sum = k*(k+1)/2;

       if(sum>n){
           return k-1;
       }
       return k;
    }
};







//Q3 LEETCODE 977. Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
                            // // o(n log n) --> error
                            // // brute force 

                            // for(int i=0; i<=nums.size(); i++ )
                            // {
                            //     nums[i]=nums[i]*nums[i];
                            // }

                            // sort(nums.begin(), nums.end());

                            // return nums;
        // optimized solution
        int left = 0;
        int right = nums.size()-1;

        vector<int> output (nums.size(),0);

        for(int i=nums.size()-1; i>=0; i--) // inserting elements from backwards
        {
            if (abs (nums[left]) > (nums[right]) )
            {
                output [i]= nums[left]*nums[left];
                left++;
            }
            else{
                output [i]= nums[right] * nums[right];
                right--; //decrement right pointer
            }
        }
        return output;
    }
};







//Q4 LEETCODE 2215. Find the Difference of Two Arrays
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // DISTINCT ELEMENTS SHULD BE THERE. WE AMKE SETS TO AVOID REPEATED NUMBERS 
        
        unordered_set<int> set1;
        vector<vector<int>> ans;
        unordered_set<int> set2;
        
        for(int i =0; i<nums1.size() ; i++){
            set1.insert(nums1[i]);
        }

        for(int i=0; i<nums2.size(); i++){
            set1.erase(nums2[i]);
            set2.insert(nums2[i]);
        }

        vector <int> ans1;
        
        for(auto it: set1){
            ans1.push_back(it);
        }

        ans.push_back(ans1);
        ans1.clear();

        for(int i=0; i<nums1.size() ; i++){
            set2.erase(nums1[i]);
        }
        for(auto it: set2){
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        ans1.clear();

        return ans;
    }
};








//Q5 LEETCODE 1385. Find the Distance Value Between Two Arrays
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d){ 
        //vector<int>& arr1, vector<int>& arr2, int d) {
        //int[] arr1, int[] arr2, int d


        int cnt=0;
        for(int i=0; i<arr1.size(); i++)
        {
            int fst = arr1[i];
            bool flag = false;

            for(int j=0; j < arr2.size(); j++)
            {
                int scnd= arr2[j];

                if(abs(scnd-fst)<=d){
                    flag=true;
                    break;
                }
            }

            if( flag == false ){
                cnt++;
            }
        }
        return cnt;
        
    }
};








//Q6 LEETCODE 442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int n: nums){
            n=abs(n);

            if(nums[n-1]>0) {
                nums [n-1]*= -1;
            }
            else{;
                result.push_back(n);
            }
        }
        return result;
    }
};









//Q7 LEETCODE 153. Find Minimum in Rotated Sorted Array
class Solution {
/*    
    int search(vector<int> & nums, int l, int r){
        if(l==r) 
            return nums[l];
        int mid = l+(r-l)/2;

        if(nums[mid] > nums[r]){
            return search(nums, mid+1, r);
        }
        if(nums[mid] < nums[r]){
            return search(nums,l, mid);
        }
        return nums[r];
    }
*/

public:
    int findMin(vector<int>& nums) {
        //return search (nums,0,nums.size()-1);

        int l=0, r = nums.size()-1;
        while (l<r){
            int mid = l+(r-l)/2;

            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else if(nums[mid] < nums[r]){
                r = mid;
            }
            else{
                nums[l];
            }

        }
        return nums[l];
    }
};








//Q8 LEETCODE 2007. Find Original Array From Doubled Array
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
