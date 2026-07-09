class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if (n==1 && s[0]=='*') return true;
        else if (n==1) return false;
        if (s[0]==')' ) return false;
        stack<int> st1, st2;
        for (int i=0;i<n; i++){
            if (s[i]=='('){
                st1.push(i);
            }
            else if (s[i]==')'){
                if (!st1.empty()) st1.pop();
                else{
                    if (st2.empty()) return false;
                    st2.pop();
                }
            }
            else{
                st2.push(i);
            }
        }   
        while (!st2.empty()){
            if (st1.empty()) break;
            if (st1.top() > st2.top()) return false;
            st1.pop();
            st2.pop();

         }
        if (!st1.empty()) return false;
        return true;
    }
};
