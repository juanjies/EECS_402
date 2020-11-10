#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "constants.h"
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "RowColumnClass.h"
#include "showMenu.h"
#include "annotateRect.h"
#include "selectColor.h"
#include "selectFill.h"
#include "TransparencyClass.h"
#include "insertPattern.h"
#include "insertImage.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: EECS402 Project 3 - Use dynamic allocation to implement image
//          editing with a UNIX Makefile to link multiple .h and .cpp files. 

int main ()  {
  string fileName;
  ifstream inFile;
  ofstream outFile;
  string magicNum; 
  ColorClass tempPixel;
  RowColumnClass tempLocation;
  
  int imageWid = 0, imageLen = 0, maxColorValue = 0; 
  int tempRed = 0, tempGreen = 0, tempBlue = 0;
  int topMenuOpt = 0;
  bool isValidInput = false;
  
  // cin fileName error checking
  cout << "Enter string for PPM image file name to load: " << endl;
  cin >> fileName;
  
	// file error checking
  inFile.open(fileName.c_str());

  if (inFile.fail())  {
    cout << "Cannot open the file" << endl;
    return 0;
  }
  else  {

    inFile >> magicNum;
    if (inFile.eof())  {
      cout << "EOF before reading the magic number" << endl;
      return 0;
    }
    else if (strcmp(magicNum.c_str(), MAGIC_NUM_PPM) != 0)  {
      cout << "Error found when trying to read magic number." 
           << " - expected P3 but found " << magicNum << endl;
      return 0; 
    }

    inFile >> imageWid;
    if (inFile.eof())  {
      cout << "EOF before reading the image width" << endl;
      return 0;
    }
    else if (inFile.fail())  {
      inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Error found when trying to read the image width "
           << " - expected a positive integer" << endl;
      return 0;
    }
    else if (imageWid < 0)  {
      cout << "Error found when trying to read the image width " 
           << " - expected a positive integer but found " 
           << imageWid << endl;
      return 0;
    }

    inFile >> imageLen;
    if (inFile.eof())  {
      cout << "EOF before reading the image length" << endl;
      return 0;
    }
    else if (inFile.fail())  {
      inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Error found when trying to read the image length "
           << " - expected a positive integer" << endl;
      return 0;
    }
    else if (imageLen < 0)  {
      cout << "Error found when trying to read the image length " 
           << " - expected a positive integer but found " 
           << imageLen << endl;
      return 0;
    }

    inFile >> maxColorValue;
    if (inFile.eof())  {
      cout << "EOF before reading the maximum color value" << endl;
      return 0;
    }
    else if (inFile.fail())  {
      inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Error found when trying to read the maximum color value"
           << " - expected a positive integer" << endl;
      return 0;
    }
    else if (maxColorValue != COLOR_RANGE_MAX)  {
      cout << "Error found when trying to read the maximum color value" 
           << " - expected 256 but found " << maxColorValue << endl;
      return 0;
    }
  }

  ColorImageClass image(imageLen, imageWid);

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0; cInd < imageWid; cInd++)  {
      // use a temp RowColumnClass object - tempLocation
      // and a temp ColorClass object - temp Pixel
      // such that we can use the setColorAtLocation method 
      // to read in all pixels and dynamic allocate them 
      inFile >> tempRed;
      inFile >> tempGreen;
      inFile >> tempBlue;
      if (inFile.eof())  {
        cout << "EOF before reading any pixel" << endl;
        return 0;
      }
      else if (inFile.fail())  {
        inFile.clear();
        inFile.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Error found when trying to read the pixels"
             << " - expected three RGB integers "
             << "between 0 and 255, inclusively"
             << endl;
        return 0;
      }
      else if (tempRed > COLOR_RANGE_MAX || tempRed < COLOR_RANGE_MIN
               || tempGreen > COLOR_RANGE_MAX 
               || tempGreen < COLOR_RANGE_MIN
               || tempBlue > COLOR_RANGE_MAX
               || tempBlue < COLOR_RANGE_MIN)  {
        cout << "Error found when trying to read the pixels"
             << " - expected three RGB integers "
             << "between 0 and 255, inclusively"
             << endl;
        return 0;
      }
      tempLocation.setRowCol(rInd, cInd);
      tempPixel.setTo(tempRed, tempGreen, tempBlue);
      image.setColorAtLocation(tempLocation, tempPixel);
    }
  }
  
  while (topMenuOpt != 5)  {
    topMenuOpt = showMenu();

    if (topMenuOpt == 1)  {
      annotateRect(image);
    }
    else if (topMenuOpt == 2)  {
      insertPattern(image);
    }
    else if (topMenuOpt == 3)  {
      insertImage(image);
    }
    // write out current image
    else if (topMenuOpt == 4)  {
      cout << "Enter string for PPM file name to output: " << endl;
      cin >> fileName;
      outFile.open(fileName.c_str());

      outFile << magicNum << endl;
      outFile << imageWid << " " << imageLen << endl;
      outFile << maxColorValue << endl;

      image.printImage(outFile);
      outFile.close();
    }
    else if (topMenuOpt == 5)  {
      cout << "Thank you for using this program" << endl;
    }
  }
  inFile.close();
  return 0;
}
