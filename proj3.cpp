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
  isValidInput = false;
  inFile.open(fileName.c_str());

  if (inFile.eof())  {
    cout << "EOF before reading the image" << endl;
    inFile.clear();
    inFile.ignore(IGNORED_CHAR_LEN, '\n');
    exit(0);
  }
  else if (inFile.fail())  {
    cout << "Cannot open the file";
    inFile.clear();
    inFile.ignore(IGNORED_CHAR_LEN, '\n');
    exit(0);
  }
  else  {
    inFile >> magicNum;
    inFile >> imageWid;
    inFile >> imageLen;
    inFile >> maxColorValue;
    
    if (strcmp(magicNum.c_str(), MAGIC_NUM_PPM) != 0)  {
      cout << "Error found when trying to read magic number." 
           << " - expected P3 but found " << magicNum << endl;
      exit(0);
    }
    else if (maxColorValue != COLOR_RANGE_MAX)  {
      cout << "Error found when trying to read the maximum color value" 
           << " - expected 256 but found " << maxColorValue << endl;
      exit(0);
    }
    else if (imageWid < 0)  {
      cout << "Error found when trying to read the image width " 
           << " - expected a positive integer but found " 
           << imageWid << endl;
      exit(0);
    }
    else if (imageLen < 0)  {
      cout << "Error found when trying to read the image length " 
           << " - expected a positive integer but found " 
           << imageLen << endl;
      exit(0);
    }
    else {
      isValidInput = true;
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
}
