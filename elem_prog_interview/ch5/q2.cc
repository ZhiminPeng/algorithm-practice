#include <iostream>
using namespace std;

int swapBits(long x, int i, int j)
{
  if( ((x >> i) & 1) != ((x>>j) & 1) )
  {
    x = x^ ( (1L << i) | (1L << j) );
  }
  return x;
}


int main(int argc, char *argv[])
{
  cout<<swapBits(50, 1, 2)<<endl;
  return 0;
}
