# include <iostream>    
# include <vector>
using namespace std;

vector<int> longest_prefix_suffix(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    
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
    return lps;
}

int main() {
    string pattern;
    cout << "Enter the pattern: ";
    cin >> pattern;

    vector<int> lps = longest_prefix_suffix(pattern);

    cout << "Longest Prefix Suffix (LPS) array: ";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }
    cout << endl;

    return 0;
}