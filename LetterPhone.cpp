/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
*/

void helper(string s,unordered_map<int,string>&mp, vector<string>&res,int idx,string temp){
    if(idx==s.size()){
        res.push_back(temp);
        return;
    }
    string letter = mp[s[idx]-'0'];
    for(int i=0;i<letter.size();i++){
        helper(s,mp,res,idx+1,temp+letter[i]);
    }
}


vector<string> Solution::letterCombinations(string s) {
    unordered_map<int,string>mp;
    mp.insert({0,"0"});
    mp.insert({1,"1"});
    mp.insert({2,"abc"});
    mp.insert({3,"def"});
    mp.insert({4,"ghi"});
    mp.insert({5,"jkl"});
    mp.insert({6,"mno"});
    mp.insert({7,"pqrs"});
    mp.insert({8,"tuv"});
    mp.insert({9,"wxyz"});
    
    vector<string>res;
    helper(s,mp,res,0,"");
    return res;
}
