#include "Menu.h"

/**
 * @brief Main function to run the program and load the database of airports and flights
 * Complexity: O(1)
 * @param argc The number of arguments. If no argument is passed, the default folder is "fake".
 * @param argv The arguments (folder name).
 * @return int 0 if the program runs successfully.
 */
int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    argv[1] = "original";
  }
  std::cout << "Loading database..." << std::endl;
  Menu(argv[1]);
  return 0;
}