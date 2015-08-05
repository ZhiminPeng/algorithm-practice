#include <string>
#include <cctype>
#include <iostream>
using namespace std;

string Decoding(string s) {
  int count = 0;
  string result = "";
  for (int i = 0; i < s.size(); ++i) {
    if (isdigit(s[i])) {
      count = count * 10 + s[i] - '0';
    } else {
      result.append(s[i], count);
      count = 0;
    }
  }
  return result;
}

string Encoding(string s) {
  string result = "";
  int count = 1;
  for (int i = 1; i <= s.size(); ++i) {
    if (s[i] == s.size() || s[i] != s[i-1]) {
      result.push_back(count + '0');
      result.push_back(s[i-1]);
      count = 1;
    } else {
      ++count;
    }
  }
  return result;
}
