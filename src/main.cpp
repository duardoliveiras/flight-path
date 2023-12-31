#include "Menu.h"

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    argv[1] = "fake";
  }
  std::cout << "Loading database..." << std::endl;
  Menu(argv[1]);
  return 0;
}