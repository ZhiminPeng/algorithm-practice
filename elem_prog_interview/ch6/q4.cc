// Check if a board game is winnable
#include <iostream>
#include <vector>
using namespace std;

bool canReach(vector<int>& A) {
  int max_reach = 0;
  for (int i = 0; i <= max_reach && max_reach < A.size(); ++i) {
    max_reach = (max_reach > A[i] + i) ? max_reach : A[i] + i;
  }
  return max_reach >= A.size() - 1;

}
