class Solution {
public:
    // Function to return the integer after single operation op between a and b
    int eval(int b,int a, char op){
        switch(op){
            case '+':
            return a+b;
            
            case '-':
            return a-b;
            
            case '*':
            return a*b;

            case '/':
            return (int)(a/b);


        }

        return 0;
    }
    // Iterate through vector and store in stack
    // if a operator is not found push into stack after integer conversion
    // else pop last two element and do (sec op first) and push the result
    // return the last element left in stack
    int evalRPN(vector<string>& tokens) {
        //cout>>(int)'0';
        stack<int> st;
        int ele;

        for(string i: tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/"){
                ele = stoi(i);
                st.push(ele);
            }
            else{
            
            int a = st.top(); st.pop(); 
            int b = st.top(); st.pop();
            st.push(eval(a,b,i[0]));
            
            }
            
        }
        return st.top();
    }
};