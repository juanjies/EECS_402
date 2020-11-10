#include "ColorImageClass.h"
#include <fstream>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "selectColor.h"
#include <cstdlib>
#include "TransparencyClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: insert a pattern to the input image

void insertPattern(ColorImageClass &image)  {
  string fileName;
  ifstream inFile;
  RowColumnClass upperLeftLocation, tempLocation;
  ColorClass patternColor;
  bool isValidInput = false;
  int inRow = 0, inCol = 0, tempInt = 0;
  int patternLen = 0, patternWid = 0;

  // error checking for fileName and Width and Length contents
  while (!isValidInput)  {
    cout << "Enter string for file name containing pattern: " << endl;    cin >> fileName;
    inFile.open(fileName.c_str());

    if (inFile.eof())  {
			cout << "EOF before reading the pattern" << endl;
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
		}

    inFile >> patternWid;
    inFile >> patternLen;
    // error check for file opening process
    if (inFile.fail())  {
      cout << "Invalid pattern width or length " << '\n'
           << "boht should be positive integers " << '\n'
           << "Try again" << endl;
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
    }
    else  {
      isValidInput = true;
    }
  }
  
	// pattern file contents error checking
  isValidInput = false;
  while (!isValidInput)  {
    cout << "Enter upper left corner of pattern row and column: ";
    cin >> inRow >> inCol;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid row or column input"  << '\n'
           << "Both should be positive integers" << '\n'
           << "try again" << endl;
    }
    else if (inRow < 0 || inCol < 0)  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid row or column input"  << '\n'
           << "Both should be positive integers" << '\n'
           << "try again" << endl;
    }
    else  {
      isValidInput = true;
    }
  }

  upperLeftLocation.setRowCol(inRow, inCol);
  patternColor = selectColor("pattern");

  TransparencyClass pattern(patternLen, patternWid);

  // read in pattern
  for (int rInd = 0; rInd < patternLen; rInd++)  {
    for (int cInd = 0; cInd < patternWid; cInd++)  {
      inFile >> tempInt;
      tempLocation.setRowCol(rInd, cInd);
      if (tempInt == 0)  {
        pattern.setTransAtLocation(tempLocation);
      }
      else if (tempInt == 1)  {
        pattern.setNotTransAtLocation(tempLocation);
      }
    }
  }

  /*
  // add pattern to the image
  for (int rInd = 0; rInd < patternLen; rInd++)  {
    for (int cInd = 0;  cInd < patternWid; cInd++)  {
      if (pattern.getTransAtLocation(rInd, cInd) == 1)  {
        tempLocation.setRowCol(upperLeftLocation.getRow() + rInd,
          upperLeftLocation.getCol() + cInd);
        image.setColorAtLocation(tempLocation, patternColor);
      }
    }
  }
  */

}