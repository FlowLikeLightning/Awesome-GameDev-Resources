// add your imports here
#include <iostream>
#include <cstdint>
int main(){
  // code here
  int32_t seed, inpnums;
  int32_t min,max;
  std::cin>>seed>>inpnums>>min>>max;
  std::cout<<std::endl;
  for (int i = 0; i < inpnums; ++i)
  {
    seed^=seed<<13;
    seed^=seed>>17;
    seed^=seed<<5;
  }
  std::cout<<min+seed%(max-min+1)<<std::endl;

  return 0;



}