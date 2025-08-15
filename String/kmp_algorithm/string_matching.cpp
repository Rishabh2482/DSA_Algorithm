# include <iostream>
# include <vector>
using namespace std;

void findlps(vector<int>&lps,const string& pattern) {
        int m= pattern.length();
        int pre= 0,suf=1,len=0;
        while(suf<m){
            // if match
            if(pattern[pre]==pattern[suf]){
                lps[suf]=pre+1;
                suf++;
                pre++;
            }
    
            // if not match
            else{
                if(pre==0){
                    suf++;
                }
                else{
                    pre = lps[--pre];
                }
            }
        }
}

vector<int> search(string &pat, string &txt) {
        // code here
        int n = pat.length();
        int m= txt.length();
        vector<int> ans;
        vector<int>lps(pat.length(),0);
        
        findlps(lps,pat);
        
        int first =0, second =0;
        
        while(first<txt.length()){
            // if match
            if(txt[first]== pat[second]){
                first++;
                second++;
                if(second==n){
                    ans.push_back(first-second);
                    second=lps[second-1];
                }
            }
            // not match
            else{
                if(second==0) first++;
                else
                second= lps[second-1];
            }
        }
        
        return ans;
    }

int main() {
    string pattern;
    string mainString;
    cout<< "Enter the Main String: ";
    cin>> mainString;

    cout << "Enter the pattern string to be find in Main String: ";
    cin >> pattern;

    vector<int> firstOccuranceofpattern = search(pattern,mainString);

    cout << "All starting index occurance of pattern string in mainstring : ";
    for (int i = 0; i < firstOccuranceofpattern.size(); i++) {
        cout << firstOccuranceofpattern[i] << " ";
    }
    cout << endl;

    return 0;
}