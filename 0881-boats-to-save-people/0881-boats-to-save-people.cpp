class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int left  = 0;
        int right = nums.size()-1;
        int boats = 0;
        while(left<=right){
            if(nums[left]+nums[right] <= limit){
                left++;
            }
            right--;
            boats++;
        }
        // if(nums[0]+nums[1]>limit && ){
        //     return n;
        // }
        return boats;
    }
};


// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int boats = 0;
//         sort(people.begin(), people.end());
        
//         int left = 0;                  // Lightest person
//         int right = people.size() - 1; // Heaviest person
        
//         while (left <= right) {
//             // If the lightest and heaviest can share a boat
//             if (people[left] + people[right] <= limit) {
//                 left++;  // Lightest person gets on the boat
//             }
//             // Regardless of whether they share, the heaviest person ALWAYS gets on a boat
//             right--; 
            
//             // One boat sets sail
//             boats++; 
//         }
        
//         return boats;
//     }
// };