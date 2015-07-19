#include <iostream>
using namespace std;

unsigned add(unsigned a, unsigned b){
  unsigned sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
  unsigned ak = 0, bk = 0, carryout = 0;
  while (temp_a || temp_b) {
    ak = a & k, bk = b & k;
    carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
    sum |= (ak ^ bk ^ carryin);
    carryin = carryout << 1, k <<= 1, temp_a >>= 1, temp_b >>= 1;
  }
  return sum | carryin;
}

unsigned multiply(unsigned x, unsigned y){
  unsigned result = 0;
  while (x) {
    if (x & 1) {
      result = add(result, y);
    }
    x >>= 1, y <<= 1;
  }
  return result;
}


int main(int argc, char *argv[])
{
  cout << multiply(2, 4) << endl;
  return 0;
}
