// multiply two big integers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string multiply(string x, string y) {
  // check the sign of the two strings
  bool is_positive = true;
  if (x[0] == '-') {
    is_positive = !is_positive;
    x = x.substr(1);
  }
  if (y[0] == '-') {
    is_positive = !is_positive;
    y = y.substr(1);
  }
  // reverse the string for convenience
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());  

  // save the results
  vector<int> result(x.size() + y.size(), 0);

  // calculate the multiplication
  for (int i = 0; i < x.size(); ++i) {
    for (int j = 0; j < y.size(); ++j) {
      result[i + j] += (x[i] - '0') * (y[j] - '0');
      result[i + j + 1] += result[i + j] / 10;
      result[i + j] %= 10;
    }
  }

  // convert result in vector to string
  string res = "";
  if (!is_positive) {
    res.push_back('-');
  }

  int i = result.size() - 1;
  while(i != 0 && result[i] == 0) {
    --i;
  }
  for ( ; i >= 0; --i) {
    res.push_back('0' + result[i]);
  }
  return res;
}

// main function for testing
int main(int argc, char *argv[]) {
  string x, y;
  while(true) {
    cin >> x;
    cin >> y;
    cout<< multiply(x, y) << endl;
  }
  return 0;
}
