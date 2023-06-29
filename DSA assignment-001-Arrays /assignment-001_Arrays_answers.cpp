//ASSIGNMENT 1

/*
Q-1 --> LEETCODE 1 TWO SUM

💡 **Q1.** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example:**
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1][

*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // using the brute force approach

        int n = nums.size(); // n= size of array
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

/*
Q-2 -->  27 REMOVE ELEMENT

💡 Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

**Example :**
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

**Explanation:** Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)[

*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        // create iterator and point it to the nums vector
        vector<int>::iterator it;
        it = nums.begin();

        // traverse the nums array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                nums.erase(it); // using erase from STL library
                it--;           // decrement it as it goes ine place forward but actually an element just deleted.
                i--;
            }
            it++;
        }
        return nums.size();
    }
};

/*
Q-3 --> LEETCODE 35 SEARCH INSERTION POSITION

💡  Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

**Example 1:**
Input: nums = [1,3,5,6], target = 5

Output: 2

*/

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // sorted array and O(logN) complexity so it means we will use binary search.
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};

/*
Q-4 --> LEETCODE 66 PLUS ONE

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.

Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        // idx = pointer at last index of array.
        int idx = digits.size() - 1;
        while (idx >= 0)
        { // revese loop as if ones place is 9 or lesser than than.
            if (digits[idx] == 9)
            {
                digits[idx] = 0;
                // digits[idx] == 0;
            }
            else
            { // less than 9
                digits[idx] += 1;
                return digits;
            }
            idx--; // going reverse.
        }

        // if all digits are 9
        // new array will be created if number is onlycontains 9.
        //  eg: 9 -> 10. [1,0] OR 999 -> 1000 [1,0,0,0] no. of digits are increasing.

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*
Q5 --> LEETCODE

💡 You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

**Example 1:**
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

**Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // merged array should be in num1 itself, given in ques.
        //  sorted in non-decreasing order --> means in increasing order, ascending order.

        // start from end to put bigger values at end in the empty spaaces.

        // if any array is out of count we will stop as rest is already sorted

        int i = m - 1, j = n - 1, k = m + n - 1;
        // i=size of nums1      j= size of nums2        k=mid of both.

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        while (i >= 0) // if j finished and I is left
            nums1[k--] = nums1[i--];
        while (j >= 0) // if I finished and J is left
            nums1[k--] = nums2[j--];
    }
};

/*
Q-6 --> LEETCODE 217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**
Input: nums = [1,2,3,1]

Output: true
*/
// approach --> sorting the array; complexity o(n log n)
int n = nums.size();
sort(nums.begin(), nums.end());

for (int i = 0; i < n - 1; i++)
{
    if (nums[i] == nums[i + 1])
        return true;
}
return false;

/*
Q-7 --> LEETCODE move zeroes (premium subscrption)
💡 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

**Example 1:**
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

*/

// TWO POINTER TECHNIQUE

int n = nums.size();
if (n == 0 || n == 1)
    return;
int left = 0, right = 0;
int temp;

// re-arrangement
while (right < n)
{ // moving right pointer
    if (nums[right] == 0)
        ++right;
    else
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        ++left;
        ++right;
    }
}

/*
Q-8 --> LEETCODE  645 SET MISMATCH
💡 You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**
Input: nums = [1,2,2,4]
Output: [2,3]

*/
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1, missing = 1;
        vector<int> result;

        // find duplicate
        for (auto x : nums)
        {
            if (nums[abs(x) - 1] < 0)
            {
                dup = abs(x);
            }
            else
            {
                nums[abs(x) - 1] *= -1;
            }
        }

        result.push_back(dup);

        // find the  missing
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                // missing
                missing = i + 1;
            }
        }
        result.push_back(missing);
        return result;
    }
};
