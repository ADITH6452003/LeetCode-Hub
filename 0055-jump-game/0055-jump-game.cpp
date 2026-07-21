#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        
        // Changed i > 0 to i >= 0 to include the starting position
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        
        return goal == 0;
    }
};