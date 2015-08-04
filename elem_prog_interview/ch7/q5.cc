#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

const array<string, 10> mymap = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void PhoneNumberToStringsHelper(string& phone_number, int digit, string& curr_string, vector<string>& result) {

  if (digit == phone_number.size()) {
    result.push_back(curr_string);
  } else {
    for (int i = 0; i < mymap[phone_number[digit] - '0'].size(); ++i) {
      curr_string[digit] = mymap[phone_number[digit] - '0'][i];
      PhoneNumberToStringsHelper(phone_number, digit + 1, curr_string, result);
    }
  }

}

vector<string>  PhoneNumberToStrings(string phone_number) {

  vector<string> result;
  string curr_string(phone_number.size(), 0);
  PhoneNumberToStringsHelper(phone_number, 0, curr_string, result);
  return result;
}

int main() {

  string phone_number;
  cin >> phone_number;
  vector<string> result;
  result = PhoneNumberToStrings(phone_number);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
  return 0;
}
