/*
Q-1 LEETCODE 561 ARRAY PARTITION

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

Example 1:
Input: nums = [1,4,3,2]
Output: 4

Explanation:All possible pairings (ignoring the ordering of elements) are:

1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4

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
Q-2 LEETCODE 575 DISTRIBUTE CANDIES

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3

Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

*/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // atmost n/2 candies she can eat
        //we need to find the minimum value


        int n = candyType.size();
        // store unique value in set
        set <int> st;

        for(auto it: candyType ){
            st.insert(it);

        }
        int set_size = st.size();

        //we are returning the minimum value between setsize and n/2 candies so she eats the minimum number of candies.
        return min(n/2, set_size);

    }
};



/*
Q3 LEETCODE  594. LONGEST HARMONIOUS SUBSEQUENCE

We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        //unordered map will store our counting,
        unordered_map<int,int> mp;

        //putting our values of num into the unordered map
        for(int val:nums) mp[val]++;

        for(auto p:mp)
        {
            if(mp.find(p.first-1)!=mp.end())
            {
                ans=max (ans, p.second + mp[p.first-1]);
            }
        }
        return ans;
    }

};


/*
Q4 LEETCODE  605. CAN PLACE FLOWERS

You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int total = 0;
        for (int i=0; i< flowerbed.size() && total < n; i++){
            if(flowerbed[i]==0){
                int next = (i==flowerbed.size() -1 ) ? 0: flowerbed[i+1];
                int prev = (i==0) ? 0 : flowerbed[i-1];

                if(next ==0 && prev ==0){
                    flowerbed[i]=1;
                    total++;
                }
            }
        }
        return total==n;
    }
};






/*
Q5 LEETCODE 628. MAXIMUM PRODUCT OF THREE NUMBERS

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        //WE NEED MAXIMUM PRODUCT
        
        //APPROACH 1 - SORTING AND FINDING PRODUCT OF MAX NUMBERS (last 3 numbers).
        // this apprroach is getting faile as -100 -99 waelcase k liyr nhi h yhe
                //we ae sorting as we need to find max product and maximum product max numbers ka hi hoga.
                //sort (nums.begin(), nums.end());
                //int n = nums.size()-1;        
                //int ans = nums[n] * nums[n-1]* nums [n-2]; 
                

                //return ans;


        // APPROACH 2 - SORTING AND FINDING PRODUCT OD MAX NUMBERS(if -100 , -99etc are there so take first two numbers and then last digit ).
        //eg -100 -99 3 4 5 --> here we take -100,-99, 5 
        sort (nums.begin(), nums.end());
        int n = nums.size();

        int ans = max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);

        return ans;

    }
    
};




/*
Q6 LEETCODE 704 BINARY SEARCH

Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Explanation: 9 exists in nums and its index is 4
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // time complexity should be O(log n)
        int n = nums.size();
        int low =0, high=n-1;

        while (low <= high){
            //int mid = low + (high-low)/2;
            int mid =(low + high)/2 ; // mid index

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target )
            {
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;


                        // int n = nums.size()-1;
                        // for (int i =0; i<=n ; i++)
                        // {
                        //     if (nums[i] == target)
                        //     {
                        //         return i;
                        //     }
                        //     else 
                        //         return -1;
                        // }
                        // return 0;
    }
};






/*
Q-7 LEETCODE 896 MONOTONIC ARRAY
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true
*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool is_increasing = true;
            bool is_decreasing = true;
        for(int i =1; i <nums.size(); i++)
        {
            if (nums [i] < nums[i-1])
            {
                is_increasing = false;
            }
            if (nums [i] > nums[i-1])
            {
                is_decreasing = false;
            }
            

        }
        return is_increasing || is_decreasing ;
        
    }
};









/*
Q8 LEETCODE 908 SMALLEST RANGE I

You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
*/
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int smallest = nums[0];
        int largest = nums[0];

        for (int i = 0; i< nums.size(); i++){
            smallest = min(nums[i], smallest);
            largest = max(nums[i], largest);
        }
        smallest +=k;
        largest -= k;

        return max(0, largest - smallest);
    }
};