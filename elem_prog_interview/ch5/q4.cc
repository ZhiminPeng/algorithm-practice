#include <iostream>
#include <stdexcept>
using namespace std;

unsigned long closestIntSameBits(unsigned long x)
{
  for (int i = 0; i < 63; ++i)
  {
    if(( (x>>i) & 1) ^ ( (x>> (i+1) &1) ) )
    {
      x ^= (1UL << i) | (1UL << (i+1));
      return x;
    }
  }
  throw invalid_argument("All bits are 0 or 1");

}

int main(int argc, char *argv[])
{
  cout << closestIntSameBits(1)<<endl;
  cout << closestIntSameBits(0)<<endl;  
  return 0;
}
