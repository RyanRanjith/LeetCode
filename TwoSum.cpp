#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            // Create and return a vector using push_back instead of initializer list
            vector<int> result;
            result.push_back(numMap[complement]);  // Add the index of the complement
            result.push_back(i);                  // Add the current index
            return result;                        // Return the result vector
        }
        numMap[nums[i]] = i;
    }
    // Return an empty vector if no solution is found
    vector<int> emptyResult;
    return emptyResult;
}

int main() {
    // Initialize the array and convert it to a vector
    int arr[] = {2, 7, 11, 15};  // Traditional array initialization
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));  // Convert array to vector

    int target = 9;
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }
    return 0;
}