#include <iostream>
#include "showMenu.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: show the top menu for users to choose a image edit option

int showMenu()  {
  int topMenuOpt = 0;  

  cout << "1. Annotate image with rectangle" << '\n'
       << "2. Annotate image with pattern from file" << '\n'
       << "3. Insert another image" << '\n'
       << "4. Write out current image" << '\n'
       << "5. Exit the program" << '\n'
       << "Enter int for main menu choice: " << endl;
  cin  >> topMenuOpt;
    
  return topMenuOpt;
}