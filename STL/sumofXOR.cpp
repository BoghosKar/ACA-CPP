#include <iostream>
#include <vector>

class Solution
{
public:
    int subsetXORSum(std::vector<int>& nums)
    {
        return solve(nums, 0, 0);
    }

    int solve(std::vector<int>& nums, int i, int ans)
    {
        if (i == nums.size())
        {
            return ans;
        }
        return solve(nums, i + 1, ans ^ nums[i]) + solve(nums, i + 1, ans);
    }
};

int main()
{
    std::vector<int> nums = {2, 5, 6};
    
    for (const auto& num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    Solution solution;
    int result = solution.subsetXORSum(nums);
    std::cout << "XOR subset sum: " << result << std::endl;
    return 0;
}
