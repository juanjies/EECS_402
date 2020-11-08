#include <iostream>
#include "selectFill.h"
#include "constants.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: output a boolean to determine if the rectangle annotation 
//          should be filled or not
bool selectFill()  {
  int fillOption = 0;
  bool isFill = false;
  bool isValidInput = false;

  cout << "1. No" << endl;
  cout << "2. Yes" << endl;

  while (!isValidInput)  {
    cout << "Enter int for rectangle fill option" << endl;
    cin >> fillOption;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid fill option input" << endl;
    }
    else if (fillOption > 2 || fillOption < 1)  {
      cout << "Invalid fill option input" << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  
  if (fillOption == 1)  {
    isFill = false;
  }
  else if (fillOption == 2)  {
    isFill = true;
  }
  return isFill;
}