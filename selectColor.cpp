#include "ColorClass.h"
#include <iostream>
#include "constants.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: output a colorclass object based on users' color choice

ColorClass selectColor(string colorTarget)  {
  int colorOption = 0;
  ColorClass pixelColor;
  bool isValidInput = false;
  const int COLOR_OPT_MIN = 1, COLOR_OPT_MAX = 5;  
  const int RED_OPT = 1, GREEN_OPT = 2,
        BLUE_OPT = 3, BLACK_OPT = 4, WHITE_OPT = 5;

  cout << "1. Red" << endl
       << "2. Green" << endl
       << "3. Blue" << endl
       << "4. Black" << endl
       << "5. White" << endl;
  
  while (!isValidInput)  {
    cout << "Enter int for "<< colorTarget << " color" << endl;
    cin >> colorOption;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid color input" 
           << " - expected an integer between 1 and 5, inclusively" << '\n' 
           << "try again"
           << endl;
    }
    else if (colorOption > COLOR_OPT_MAX 
             || colorOption < COLOR_OPT_MIN)  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid color input" 
           << " - expected an integer between 1 and 5, inclusively" << '\n' 
           << "try again"
           << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  
  if (colorOption == RED_OPT)  {
    pixelColor.setToRed();
  }
  else if (colorOption == GREEN_OPT)  {
    pixelColor.setToGreen();
  }
  else if (colorOption == BLUE_OPT)  {
    pixelColor.setToBlue();
  }
  else if (colorOption == BLACK_OPT)  {
    pixelColor.setToBlack();
  }
  else if (colorOption == WHITE_OPT)  {
    pixelColor.setToWhite();
  }
  return pixelColor;
}