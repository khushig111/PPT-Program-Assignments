//MOCK TEST -1 CODING QUESTIONS

/*
Q-1 --> LEETCODE move zeroes (premium subscrption)
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
Q2 LEETCODE 387 FIRST UNIQUE CHARCTER IN A STRING

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
a. 1 <= s.length <= 10^5
b. s consists of only lowercase English letters.

Note: Create a GitHub file for the solution and add the file link the the answer section below.
*/

class Solution {
public:
    int firstUniqChar(string s) {
           
        //ONLY SMALL LETTERS 

        //WE COUNT THE CHARACTERS AND THEN RETURN THE INDEX OF THAT UNIQUE ALPHABET
        //HASHMAP OF CHARACTERS 

        // KEEP A CHECK O COUNT OF EACH CHARACTER
        // frequency array - WE MAY USE ARRAY OF 26 AS 26 LETTERS SO WE CAN KEEP COUNT OF EACH LETTER
        //convert thr string into character array.
        // we will take ascii values into consideration. a=97, b=98..... z=122
        //l-'a' = gives ascii value of it in frequency array eg 108-97=11 so 'l' is at 11th position in frequency array.

        int count[26] ={0}; // count of each char from a to z is zero --> all have value as zero
        for (char c:s) //iterate all char odf the string --> refer w3schools array loop article for it
        {
            count [c-'a']++;
        } 
        for (int i=0; i< s.length(); ++i)
        {
            if (count [s[i]-'a']==1)
            {
                return i;
            }
            // else{
            //     return -1;
            // }
        }
        return -1;
        
    }
};
