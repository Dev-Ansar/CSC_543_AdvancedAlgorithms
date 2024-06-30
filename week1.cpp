#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Finding the complement that adds up to target

            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }

        // If complement not found, add the number and its index to the map
        numMap[nums[i]] = i;
    }
    
    return {}; // if no solution found

}


int main() {
    vector<int> nums = {7, 9, 15, 30, 50};
    int target = 45;
    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] <<"]"<< endl;
    } else {
        cout << "No solution found" << endl;
    }
    
    return 0;
}
