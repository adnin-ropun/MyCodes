#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s) {
    string t=s;
    reverse(t.begin(),t.end());
    if(s==t) return 1;
    else return 0;
}

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=(int)s.size()-1;
        string s1=s;
        string s2=s;
        while(i<j){

            if(s[i]!=s[j]){
                s1.erase(i,1);
                s2.erase(j,1);
                
                if(isPalindrome(s1)) return true;
                else if(isPalindrome(s2)) return true;
                else return false;

            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    Solution S;
    if(S.validPalindrome(s)) cout<<"Yes";
    else cout<<"No";
}
