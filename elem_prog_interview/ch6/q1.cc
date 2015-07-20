#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dutchFlagPartition(vector<int>& v, int i) {
  int pivot = v[i];
  int small = 0, equal = 0, large = v.size() - 1;
  while (equal <= large) {
    if (v[equal] < pivot) {
      swap(v[equal++], v[small++]);
    } else if (v[equal] == pivot) {
      ++equal;
    } else {
      swap(v[equal], v[large--]);
    }
  }
}


int main(int argc, char *argv[]) {
  vector<int> v(10);
  for (int i = 0; i < 10; ++i) {
    v[i] = rand() % 10;
  }
  for (int i = 0; i < 10; ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
  dutchFlagPartition(v, 1);
  for (int i = 0; i < 10; ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
  
  return 0;
}
