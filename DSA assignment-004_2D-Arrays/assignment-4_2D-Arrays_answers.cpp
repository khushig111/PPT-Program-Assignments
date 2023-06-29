// ASSIGNMENT-4 

//ASSIGNMENT - 4

/*
Q1 LEETCODE PREMIUM QUES 1213 INTERSECTION OF THREE SORTED ARRAYS

💡 Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

Example 1:
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]

Explanation: Only 1 and 5 appeared in the three arrays.
*/
class solution
{
    def arraysIntersection (self, arr1: List[int], arr2: List[int], arr3: List[int])
    {
        //WE WILL TAKE 3 POINTERS.
        // IF ANY ONE POINTER POINTS OUT OF ARRAY SO WE STOP --> WHILE LOOP
        //output is not empty.

        int intersect[];
        
        int p1=0, p2=0, p3=0;
        while(p1<len(arr1) && p2<len(arr2) &&  p3<len(arr3)){
            if (arr[p1] == arr[p2] == arr[p3]){
                intersect.append(arr1[p1])
                p1++;
                p2++;
                p3++;
            }
            else{
                int largest = max (arr[p1],  arr[p2], arr[p3])
                if (arr1[p1] < largest){
                    p1++;
                }
                if (arr2[p2] < largest){
                    p2++;
                }
                if (arr3[p3] < largest){
                    p3++;
                }
            }
        }
        return intersect; 
    }

};




/*
Q2 LEETCODE  2215. Find the Difference of Two Arrays

Given two 0-indexed integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

- answer[0] *is a list of all distinct integers in* nums1 *which are not present in* nums2*.*
- answer[1] *is a list of all distinct integers in* nums2 *which are not present in* nums1.

Note that the integers in the lists may be returned in any order.

Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4,6]

Output: [[1,3],[4,6]]

Explanation:

For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6]
*/
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




/*
Q3 LEETCODE 867. Transpose Matrix
Given a 2D integer array matrix, return *the **transpose** of* matrix.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

**Example 1:**

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

Output: [[1,4,7],[2,5,8],[3,6,9]]

![iamge_v3.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a54805f4-c9b5-491c-a900-8e8a94062c79/iamge_v3.png)

*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // MATRIX MAY OR MAY NOT BE SQUARE MATRIX
        // ROWS BECOMES COLUMNS AND VICE VERSA
        // IF QUES MATRIX = n x m SO ANSWER MATRIX = m x n
        //(0,1 ka element becomes (1,0))


        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans (n, vector<int> (m));

        for(int i=0; i<n ; i++){
            for (int j =0 ; j<m ; j++){
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;

        
    }
};






/*
Q4 - LEETCODE  561. Array Partition
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is **maximized**. Return *the maximized sum*.

Example 1
Input: nums = [1,4,3,2]
Output: 4

**Explanation:** All possible pairings (ignoring the ordering of elements) are:

1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4

So the maximum possible sum is 4.
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<nums.size()-1; i+=2){
            ans+=min (nums[i], nums[i+1]);
        }
        return ans;
    }
};








/*
Q5 LEETCODE 441. Arranging Coins

💡 You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.
Given the integer n, return *the number of **complete rows** of the staircase you will build*.

Example 1
[v2.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4bd91cfa-d2b1-47b3-8197-a72e8dcfff4b/v2.jpg)

Input: n = 5
Output: 2

Explanation: Because the 3rd row is incomplete, we return 2.
*/
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









/*
Q6 LEETCODE 977. Squares of a Sorted Array
💡 Given an integer array nums sorted in non-decreasing order, return *an array of the squares of each number sorted in non-decreasing order*.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100]
*/
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









/*
Q7 LEETCODE  598.Range Addition II

💡 You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.
Count and return *the number of maximum integers in the matrix after performing all the operations*

Example 1:
![q4.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4d0890d0-7bc7-4f59-be8e-352d9f3c1c52/q4.jpg)

Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4

Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r=m, c=n;
        for(int i=0; i<ops.size(); i++){
            r = min (r , ops[i][0] );
            c = min (c , ops[i][1] );
        }
        return r*c;        
    }
};








/*
Q8 LEETCODE 1470. Shuffle the Array
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

*Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

Example 1:
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]

Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7]
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans; //(2*n,-1);

        int i=0; 
        int j=n;
        while(i<n and j<2*n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};
