class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                five++;
            }
            if(bills[i] == 10){
                if(five==0){
                    return false;
                }
                five--;
                ten++;
            }
            if(bills[i] == 20){
                if(ten>0 && five>0){
                    five--;
                    ten--;
                }else if(ten==0 && five>2){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};