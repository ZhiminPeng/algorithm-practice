// Delete a key from an array
#include <iostream>
#include <vector>
using namespace std;

size_t removeElement(vector<int>& A, int k) {
  // write-idx keep track of the next available slot for
  // fill in value
  size_t write_idx = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    if (A[i] != k) {
      A[write_idx++] = A[i];
    }
  }
  return write_idx;
}
