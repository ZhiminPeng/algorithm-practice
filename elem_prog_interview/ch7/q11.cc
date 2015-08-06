#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// convert int to binary string
string TransIntToBinary(int n) {
  string res = "";
  while (n) {
    res.push_back('0' + (n & 1));
    n >>= 1;
  }
  reverse(res.begin(), res.end());
  return res; 
}

string Encoding(vector<int>& A) {
  string res = "";
  for (const int& a : A) {
    string tmp = TransIntToBinary(a);
    tmp.insert(0, tmp.size() - 1, '0');
    res = res + tmp;
  }

  return res;
}

// convert binary string to int
int TransBinaryToInt(const string& s) {

  int val = 0;
  for (const char& c : s) {
    val = val * 2 + c - '0';
  }
  return val;
}

// decoding
vector<int> Decoding(const string& s) {

  vector<int> res;
  int i = 0;
  int count = 0;
  while (i < s.size() ) {
    // check the number of consequtive '0'
    int zero_idx = i;
    while (zero_idx < s.size() && s[zero_idx] == '0') {
      ++zero_idx;
    }
    int len = zero_idx - i + 1;
    res.push_back( TransBinaryToInt(s.substr(zero_idx, len)) );
    i = zero_idx + len;
    
  }

  return res;

}

int main() {
  vector<int> A = {1, 2, 3, 4};

  string res = Encoding(A);
  cout << res << endl;
  vector<int> B;
  B = Decoding(res);
  for (const int& i : B) {
    cout << i << " ";
  }
  cout << endl;
  
}
