// ASSIGNMENT -3 

/*
Q1 LEETCODE 16 --> 3 SUM CLOSEST
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff =INT_MAX;
        int closest_sum =0;
        int n= nums.size();
        sort(nums.begin(), nums.end());

        for (int p1=0; p1<n-2 ; ++p1){
            int p2= p1+1 , p3 = n-1;
            while(p2<p3){
                int sum=nums[p1] + nums[p2]+ nums[p3];
                if(sum>target) {
                    p3--;
                }
                else if(sum<target){
                    p2++;
                }
                else{
                    return sum;
                }

                int diff = abs (sum-target);

                if(diff<min_diff){
                    min_diff =diff;
                    closest_sum= sum;
                }
            }
        }
        return closest_sum;
        
    }
};




/*
Q2 LEETCODE Q18 --> 4SUM
Question 2
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n= nums.size();
        for(int i=0; i<n -3; i++)
        {
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int tSum = target -(nums[i] + nums[j]);
                int l=j+1, h=n-1;
                while (1<h){
                    if( nums[l] +nums[h] == tSum){
                        vector<int> oneAns = {nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(oneAns);
                        while(l<h && nums[l] == nums[l+1] ){
                            l++;
                        }
                        while(l<h && nums[h] == nums[h+1]){
                            h--;
                        } 
                        l++;
                        h--;  
                    }
                    else if(nums[l] + nums[h]<tSum){
                        l++;
                    }
                    else{
                        h--;
                    }
                }              
            }
        }
        return ans;
        
    }
};




/*
Q3 31 --> NEXT PERMUTATION

💡 A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater
permutation of its integer. More formally, if all the permutations of the array are
sorted in one container according to their lexicographical order, then the next
permutation of that array is the permutation that follows it in the sorted container.

If such an arrangement is not possible, the array must be rearranged as the
lowest possible order (i.e., sorted in ascending order).

● For example, the next permutation of arr = [1,2,3] is [1,3,2].
● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.

**Example 1:**
Input: nums = [1,2,3]
Output: [1,3,2]

*/
class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()==1){
            return ;
        }

        int idx1;
        for(int i =nums.size()-2 ; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx1=i;
                break;
            }
        }
        if(idx1 <0){
            reverse(nums.begin(),nums.end());
        }
        else
        {
            int idx2=0;
            for(int i =nums.size()-1; i>=0; i--)
            {
                if(nums[i]>nums[idx1])
                {
                    idx2=i;
                    break;
                }
            }
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin() + idx1 +1, nums.end());
        }
    }
};




/*
Q4 LEETCODE 35 SEARCH INSERT POSITION

Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //sorted array and O(logN) complexity so it means we will use binary search.
        int n=nums.size();
        int start = 0;
        int end= n-1;

        while(start<=end)
        {
            int mid=(start+end)/2;
            if (nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }

        }
        return start;
    }
};




/*
Q5 LEETCODE 66 PLUS ONE
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.

Increment the large integer by one and return the resulting array of digits.
<aside>
💡 **Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // idx = pointer at last index of array.
        int idx= digits.size()-1;
        while (idx >= 0){ //revese loop as if ones place is 9 or lesser than than.
            if(digits[idx] == 9){
                digits[idx]=0;
                // digits[idx] == 0;
            }
            else{ // less than 9 
                digits[idx]+=1;
                return digits;
            }
            idx --; // going reverse.
        }

        //if all digits are 9
        //new array will be created if number is onlycontains 9.
        // eg: 9 -> 10. [1,0] OR 999 -> 1000 [1,0,0,0] no. of digits are increasing.

        digits.insert(digits.begin(),1);
        return digits;
    }
};


/*
Q6 LEETCODE 136 SINGLE NUMBER
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //WE WILL USE SETS AND MAPS

        unordered_map<int,int> m;
        for(auto a:nums) m[a]++;
        for (auto a: m)
        {
            if (a.second!=2)
            {
                return a.first;
            }
        }
        return -1;
        
    }
};





/*
Q7 LEETCODE PREMIUM QUES --> 163 MISSING RANGES
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.

Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]

Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
*/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        auto f = [](int a, int b) {
            return a == b ? to_string(a) : to_string(a) + "->" + to_string(b);
        };
        int n = nums.size();
        vector<string> ans;
        if (n == 0) {
            ans.emplace_back(f(lower, upper));
            return ans;
        }
        if (nums[0] > lower) {
            ans.emplace_back(f(lower, nums[0] - 1));
        }
        for (int i = 1; i < n; ++i) {
            int a = nums[i - 1], b = nums[i];
            if (b - a > 1) {
                ans.emplace_back(f(a + 1, b - 1));
            }
        }
        if (nums[n - 1] < upper) {
            ans.emplace_back(f(nums[n - 1] + 1, upper));
        }
        return ans;
    }
};





/*
Q8 LEETCOCDE PREMIUM QUESTION 253 MEETING ROOMS-II

Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
*/
