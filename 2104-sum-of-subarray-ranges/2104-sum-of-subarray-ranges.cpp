class Solution {
public:
    vector<int> nextSmallerElementIndex(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> s;
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            if(s.empty()) {
                result[i] = n;
            } else {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

    vector<int> prevSmallerElementIndex(const vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if(s.empty()) {
                result[i] = -1;
            } else {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

    long long sumSubarrayMin(const vector<int>& arr) {
        int n = arr.size();
        vector<int> psei = prevSmallerElementIndex(arr);
        vector<int> nsei = nextSmallerElementIndex(arr);
        
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int leftSmaller = psei[i];
            int rightSmaller = nsei[i];
            
            long long leftRange = i - leftSmaller;
            long long rightRange = rightSmaller - i;
            long long noOfSubarray = leftRange * rightRange;
            
            sum = sum + (noOfSubarray * arr[i]);
        }
        
        return sum;
    }

    vector<int> nextGreaterElementIndex(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> s; 

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            
            if (s.empty()) {
                result[i] = n;
            } else {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

    vector<int> prevGreaterElementIndex(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> s;

        for (int i = 0; i < n; i++) { 
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            
            if (s.empty()) {
                result[i] = -1; 
            } else {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

    long long sumSubarrayMins(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pgei = prevGreaterElementIndex(arr);
        vector<int> ngei = nextGreaterElementIndex(arr);
        
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int leftGreater = pgei[i];
            int rightGreater= ngei[i];
            
            long long leftRange = i - leftGreater;
            long long rightRange = rightGreater - i;
            long long noOfSubarray = leftRange * rightRange;
            
            sum = sum + (noOfSubarray * arr[i]);
        }
        
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long smaller = sumSubarrayMin(nums);
        long long greater = sumSubarrayMins(nums);
        return greater - smaller;
    }
};