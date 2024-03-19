#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    int freq_max = 0; // maximum frequency
    int n = nums.size();
    int totalInc = 0;
    
    for (int i = 0, j = 0; j < n; ++j) {
        totalInc += nums[j]; // Add the current element to the total increment.
        
        // While the product of the current subarray length and the current element
        // is greater than the difference between the sum of the subarray and 'k',
        // remove elements from the left side of the subarray.
        while ((int)(j - i + 1) * nums[j] - totalInc > k) {
            totalInc -= nums[i]; // Subtract the leftmost element from the total increment.
            ++i; // Move the left pointer to the next element.
        }
        // Update the maximum frequency if the current subarray length is greater.
        freq_max = max(freq_max, j - i + 1);
    }
    
    return freq_max;
}

int main() {

    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;
    int r1 = maxFrequency(nums1, k1);
    cout << "Frequency for 1st set: " << r1 << endl; // Output: 3
    
    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;
    int r2 = maxFrequency(nums2, k2);
    cout << "Frequency for 2nd set: " << r2 << endl; // Output: 2
    
    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    int r3 = maxFrequency(nums3, k3);
    cout << "Frequency for 3rd set: " << r3 << endl; // Output: 1
    
    return 0;
}

/*
Suppose we have the following input:

Input: nums = [1, 4, 8, 13], k = 5

- Sort the array, the array becomes [1, 4, 8, 13].
- We iterate through each element in the sorted array and consider it as a potential candidate for the maximum frequency.

- For the first element, 1, we calculate the total increments required to make all elements up to that element equal to it. 
    Since the difference between 1 and the first element is 0, no increments are needed. 
    So, the total increments required for the first element is 0.

- For the second element, 4, we calculate the total increments required to make all elements up to that element equal to it. 
    The difference between 4 and the first element is 3. 
    So, we need 3 increments to make the first two elements equal to 4. 
    The total increments required for the second element is 3.

- For the third element, 8, we calculate the total increments required. 
    The difference between 8 and the sum of the first three elements (1 + 4 + 8 = 13) is 5. 
    So, we need 5 increments to make the first three elements equal to 8. 
    The total increments required for the third element is 5.

- For the fourth element, 13, we calculate the total increments required.
    The difference between 13 and the sum of all elements (1 + 4 + 8 + 13 = 26) is 13. 
    So, we need 13 increments to make all elements equal to 13. 
    However, we have a constraint of at most 5 operations (k = 5), so we cannot make all elements equal to 13, so stop.

- Update and count frequency

*/
