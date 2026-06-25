class Solution {
public:
void newstrS(string s,vector<string>&word){
    
    string str="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            word.push_back(str);
            str="";
        }
        else if(s[i]!=' '){
            str=str+s[i];
        }
    }
    word.push_back(str);
}
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        vector<string>word;
        newstrS(s,word);
        if(pattern.size()!=word.size()){
            return false;
        } 
        for(int i=0;i<pattern.size();i++){
            char firch=pattern[i];
           string secword=word[i];
           if(!mp1.count(firch)&&!mp2.count(secword)){
            mp1[firch]=secword;
            mp2[secword]=firch;

           }
           else{
            if(mp1[firch]!=secword|| mp2[secword]!=firch){
                return false;
            }
           }
        }
        return true;
    }
};