//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
    stack<string> str ;
    string temp = "" ;
   
    for(int i = 0 ; i<=s.length() ; ++i)
    {
        //cout<<s[i];
        if(s[i] == '.' ||  s[i]=='\0' || s[i]=='\n')
        {
            str.push(temp);
            str.push(".");
            
            temp = "";
        }
        else
        {
            //cout<<s[i];
            temp+=s[i] ;
        }
    }
    str.pop();
    string str1 = "";
    while(!str.empty())
    {
        str1+=str.top();
        str.pop();
    }
    return str1;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends