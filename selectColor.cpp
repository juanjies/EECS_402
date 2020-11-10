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

  cout << "1. Red" << endl
       << "2. Green" << endl
       << "3. Blue" << endl
       << "4. Black" << endl
       << "5. White" << endl;
  
  while (!isValidInput)  {
    cout << "Enter int for "<< colorTarget << "color" << endl;
    cin >> colorOption;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid color input" << endl;
    }
    else if (colorOption > 5 || colorOption < 1)  {
      cout << "Invalid color input" << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  
  if (colorOption == 1)  {
    pixelColor.setToRed();
  }
  else if (colorOption == 2)  {
    pixelColor.setToGreen();
  }
  else if (colorOption == 3)  {
    pixelColor.setToBlue();
  }
  else if (colorOption == 4)  {
    pixelColor.setToBlack();
  }
  else if (colorOption == 5)  {
    pixelColor.setToWhite();
  }
  return pixelColor;
}