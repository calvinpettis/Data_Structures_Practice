#include <random>
#include <iostream>
int main(void)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0,1000000);

  for (int i = 0; i < 1000000; i++)
  {
       std::cout << dist(gen) << std::endl;
  }
  return 0;
}
