#include <iostream>
using namespace std;



int Parity(unsigned long n)
{
  int result = 0;
  while(n)
  {
    result ^= (n & 1);
    n = n >> 1;
  }
  return result;
}


int main(int argc, char *argv[])
{
  for (int i = 0; i < 10; ++i)
  {
    cout << Parity(i)<<endl;
  }
  return 0;
}
