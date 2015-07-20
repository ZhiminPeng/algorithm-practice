#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> A) {
  int offset = 1, curr = 0;
  vector<int> B(A.begin(), A.end());
  for (int i = B.size() - 1; i >=0; --i) {
    curr = B[i] + offset;
    if (curr < 10) {
      ++B[i];
      return B;
    } else {
      B[i] = 0;
      offset = 1;
    }
  }
  if (offset == 1) {
    B.insert(B.begin(), 1);
  }
  return B;
}

int main(int argc, char *argv[]) {

  vector<int> A(2);
  A[0] = 9;
  A[1] = 9;
  vector<int> B = plusOne(A);
  for (int i = 0; i < B.size(); ++i) {
    cout << B[i] << " ";
  }
  cout << endl;
  return 0;
}
