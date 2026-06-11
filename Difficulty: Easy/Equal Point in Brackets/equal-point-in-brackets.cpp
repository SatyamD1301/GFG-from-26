class Solution {
  public:
    int findIndex(string &s) {
        int n = s.size();
        
        int closeAfter = 0;
        for(char ch : s) {
            if(ch == ')') closeAfter++;
        }
        
        int openBefore = 0;
        
        for(int i = 0; i < n; i++) {
            if(openBefore == closeAfter)
                return i;
                
            if(s[i] == '(')
                openBefore++;
            else
                closeAfter--;
        }
        
        if(openBefore == closeAfter)
            return n;
            
        return -1;
    }
};