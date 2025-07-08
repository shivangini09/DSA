class StockSpanner {
    stack<pair<int,int>> st;
    int ind = -1; // initialized index;
public:
    StockSpanner() {
        ind = -1;
        while (!st.empty()) st.pop();

        
    }
    
    int next(int price) {
        // basically price ka index minus the index of prev greater element 
        ind = ind+1;
        while(!st.empty() && st.top().first<=price){
            st.pop(); // pop out the smaller elements
        }
        int ans;
        if(st.empty()){
            ans = -1;      // if stack is empty 
        }
        else{
            ans = st.top().second;
        }
        st.push({price,ind});
        return(ind-ans);
        
    }
    
};
