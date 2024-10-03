#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0]; 
        for (int i = 1; i < nums.size(); i++) { 
            mini = min(mini, nums[i]); 
        }
        return mini; 
    }
};

int main() {
    Solution solution;
    int arr[] = {3, 4, 1, 7, 2}; 
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int)); 
    
    int result = solution.findMin(nums);
    cout << "The minimum element is: " << result << endl; 
    
    return 0; 
}
