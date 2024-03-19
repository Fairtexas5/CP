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
    int result1 = maxFrequency(nums1, k1);
    cout << "Output for nums = [1,2,4] and k = 5: " << result1 << endl; // Output: 3
    
    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;
    int result2 = maxFrequency(nums2, k2);
    cout << "Output for nums = [1,4,8,13] and k = 5: " << result2 << endl; // Output: 2
    
    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    int result3 = maxFrequency(nums3, k3);
    cout << "Output for nums = [3,9,6] and k = 2: " << result3 << endl; // Output: 1
    
    return 0;
}
