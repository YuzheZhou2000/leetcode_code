# include <bits/stdc++.h> 
using namespace std;
class Solution
{
public:
    // 使用一个map来记录序列

    unordered_map<int, int> myMap;
    vector<char> vec;


  //Insert one char from stringstream
    void Insert(char ch) {
        myMap[ch]++;
        vec.push_back(ch);
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
    	for (auto &ch:vec) {
			if (myMap[ch] == 1) return ch;
		}
		return '#';
    }

};

int main(){
    unordered_map<char, int> myMap;
    myMap['a'] ++;
    cout <<myMap['a']<<endl;
    return 0;
}