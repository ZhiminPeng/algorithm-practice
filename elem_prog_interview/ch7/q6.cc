#include <string>
#include <iostream>
using namespace std;

string LookAndSay(int n) {
  string res = "";
  if(n <= 0)
    return res;
  else if(n == 1) {
    res.push_back('1');
    return res;
  } else {
    string prev = LookAndSay(n - 1);
    int start = 0;
    int count = 0;
    for (int i = 0; i < prev.size(); ++i) {
      if (prev[i] == prev[start]) {
        ++count;
      } else {
        res.push_back(count + '0');
        res.push_back(prev[start]);
        start = i;
        count = 1;
      }
    }
    res.push_back(count + '0');
    res.push_back(prev[start]);
    return res;
  }
}
    

int main() {

  int n;
  cin >> n;
  string result = LookAndSay(n);
  cout << result <<endl;

}
