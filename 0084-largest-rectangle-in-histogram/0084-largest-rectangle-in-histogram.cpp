class Solution {
public:
    vector<int> leftSmallerElementIndex(const vector<int>&arr){
        int n = arr.size();
        vector<int> result(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                result[i] = -1;
            }else{
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

    vector<int> rightSmallerElementIndex(const vector<int> &arr){
        int n = arr.size();
        vector<int>result(n);
        stack<int>s;
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                result[i] = n;
            }else{
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller = leftSmallerElementIndex(heights);
        vector<int> rightSmaller = rightSmallerElementIndex(heights);
        int area = 0;
        for(int i =0;i<n;i++){
            int lefts = leftSmaller[i];
            int right = rightSmaller[i];
            int breath = right - lefts -1;
            int height = heights[i];
            area = max(area , (height*breath));
       }
       return area;
    }
};