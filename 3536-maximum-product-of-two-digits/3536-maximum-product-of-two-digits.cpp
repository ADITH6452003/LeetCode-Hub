class Solution {
public:
    int maxProduct(int n) {
        // Edge case: if n is single digit or 0, we can't multiply two digits
        if (n >= -9 && n <= 9) return 0; 
        
        int temp = abs(n); // Handle negative inputs safely
        vector<int> nums;
        
        while(temp != 0) {
            int k = temp % 10;
            nums.push_back(k);
            temp /= 10;
        }
        
        int max2 = 0;
        int num_digits = nums.size(); // Store size as a signed integer
        
        // Now safely loop through the actual digits
        for(int i = 0; i < num_digits - 1; i++){
            for(int j = i + 1; j < num_digits; j++){
                int tempM = nums[i] * nums[j];
                max2 = max(max2, tempM);
            }
        }
        
        return max2;
    }
};
