#include <bits/stdc++.h>
using namespace std;
string ff(string s){
    string str;
    for (int i = 0;i < s.size();i++){
        if (s[i] == '#'){
            str.pop_back();
        }else{
            str += s[i];
        }
    }
    return str;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    if (ff(str1)==ff(str2)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
//run id:2746