class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int ctr = 0;
        for (char c : t){
            mpp[c]++;
            ctr++;
        }
        int n = s.length();
        int low = -1, high = n;
        int l = 0, r = 0;
        
        while (r<n){
            auto it = mpp.find(s[r]);
            if (it != mpp.end()){
                if (mpp[s[r]]>0) ctr--;
                mpp[s[r]]--;
            }
            while (ctr==0){
                if ((r-l)<=(high-low)){
                    low = l;
                    high = r;
                }
                if (mpp.find(s[l])!=mpp.end()){
                    mpp[s[l]]++;
                    if (mpp[s[l]]>0) ctr++;
                }
                l++;
            }
            r++;
        }
        if (low == -1) return "";
        return s.substr(low,high-low+1);
    }
};