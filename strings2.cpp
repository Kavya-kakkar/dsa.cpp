#include<iostream> //valid palindrome leetcode Que no 125
#include<string>
using namespace std;
bool isAlphaNumeric(char ch) {
    if((ch >= '0' && ch <= '9' ) || (tolower(ch) >='a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int st = 0, end = s.length()-1;

    while(st < end) {
        if(! isAlphaNumeric(s[st])){
            st++; continue;
        }
        if(!isAlphaNumeric(s[end])){
            end--; continue;
        }
        if(tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++; end--;
    }
    return true;
}
int main(){
    string inputString;
    cout<<"enter a string: ";
    getline(cin,inputString);

    if(isPalindrome(inputString)) {
        cout<<"\"" << inputString << "\" is a palindrome." << endl;
    } else {
        cout<<"\"" << inputString << "\" is  not a palindrome." << endl;
    }
    
    return 0;
};