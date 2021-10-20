    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    vector<int> KMP(string pattern,string text){
        int n = text.length();
        int m = pattern.length();
        vector<int>lps= prefix_function(pattern);
        vector<int> ind;
        int i=0,j=0;
        while(i<n){
            if(pattern[j]==text[i]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
            if (j == m) { 
                ind.push_back(i-j);
                j = lps[j - 1]; 
            } 
        }
        return ind;
    }