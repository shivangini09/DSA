class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                five++;        // you now have a five rupee coin
            }
            else if(bills[i]==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                // we have gotten a chwenchy rupee note!!
                if(five && ten){
                    five--;
                    ten--;    // khulle dedo paise lelo
                }
                else if(five>=3){
                    five=five-3;      // chillar
                }
                else{
                    return false;       //chillar nhi h mere paas lol
                } 
            }
        }
        return true;
        
    }
};