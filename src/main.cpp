#include "Menu.h"

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    // !! CHANGE LATER
    argv[1] = "original";
  }
  std::cout << "Loading database..." << std::endl;
  Menu(argv[1]);
  return 0;
}