#include <vector>
#include <iostream>
using namespace std;


vector<int> GeneratePrimes(int n) {
  vector<int> primes;
  if (n<=1) return primes;
  primes.push_back(2);
  int j = 0;
  for (int i = 3; i <= n; ++i) {
    j = 0;
    while ( (j < primes.size()) && (i % primes[j] != 0 )) {
      ++j;
    }
    if (j == primes.size()) primes.push_back(i);
  }
  return primes;
}


int main(int argc, char *argv[])
{

  int n;
  while(true) {
    cin >> n;
    vector<int> res;    
    res = GeneratePrimes(n);
    for(int i=0;i<res.size();i++)
      cout << res[i] << " ";
    cout<<endl;

  }
  return 0;
}
