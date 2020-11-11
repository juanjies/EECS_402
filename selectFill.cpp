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
  const int FILL_OPT_MIN = 1, FILL_OPT_MAX = 2;
  const int NOT_FILL_OPT = 1, FILL_OPT = 2;

  cout << "1. No" << endl;
  cout << "2. Yes" << endl;

  while (!isValidInput)  {
    cout << "Enter int for rectangle fill option" << endl;
    cin >> fillOption;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid fill option input" 
           << " - expected an integer of 1 or 2 " << '\n' 
           << "try again"
           << endl;
    }
    else if (fillOption > FILL_OPT_MAX
             || fillOption < FILL_OPT_MIN)  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid fill option input" 
           << " - expected an integer of 1 or 2 " << '\n' 
           << "try again"
           << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  if (fillOption == NOT_FILL_OPT)  {
    isFill = false;
  }
  else if (fillOption == FILL_OPT)  {
    isFill = true;
  }
  return isFill;
}