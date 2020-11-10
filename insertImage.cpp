#include <iostream>
#include <cstdlib>
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "selectColor.h"
#include <string>
#include <string.h>
#include "TransparencyClass.h"
#include "RowColumnClass.h"
#include "constants.h"
using namespace std;

// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: insert an image to the input image
void insertImage(ColorImageClass &image)  {
  bool  isValidInput = false, isSuccess = true;
  int imageWid = 0, imageLen = 0;
  int maxColorValue = 0;
  int inRow = 0, inCol = 0;
  int tempRed = 0, tempGreen = 0, tempBlue = 0;
  ifstream inFile;
  string fileName, magicNum;
  ColorClass transColor, tempPixel;
  RowColumnClass upperLeftLocation, tempLocation;

  while (!isValidInput && isSuccess)  {
    cout << "Enter string for file name of PPM image to insert: " << endl;
    cin >> fileName;
    inFile.open(fileName.c_str());

    if (inFile.fail())  {
      cout << "Unable to open image file " << '\n'
           << "Try again.";
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
      isSuccess = false;
    }
    else  {
      isValidInput = true;
    }
  }

  isValidInput = false;
	// pattern file contents error checking
  while (!isValidInput && isSuccess)  {
    inFile >> magicNum;
    
    if (inFile.eof())  {
      cout << "EOF before reading the magic number" << endl;
      isSuccess = false;
    }
    else if (strcmp(magicNum.c_str(), MAGIC_NUM_PPM) != 0)  {
      cout << "The Magic Number of the .ppm file is invalid." << endl;
      isSuccess = false;
    }
    
    inFile >> imageWid;
    inFile >> imageLen;

    if (inFile.eof())  {
      cout << "EOF before reading the image Width and Length" << endl;
      isSuccess = false;
    }
    else if (imageWid < 0 || imageLen < 0)  {
      cout << "Error found when read the dimension of the image"
           << " - expected both to be non-negative integers"
           << endl;
      isSuccess = false;
    }

    inFile >> maxColorValue;
    if (inFile.eof())  {
      cout << "EOF before reading the image maximum color value" << endl;
      isSuccess = false;
    }
    else if (inFile.fail())  {
      cout << "The maximum color value of the .ppm file is invalid." 
           << " - expected to be " << COLOR_RANGE_MAX 
           << endl;
      isSuccess = false;
    }
    else if (maxColorValue != COLOR_RANGE_MAX)  {
      cout << "The maximum color value of the .ppm file is invalid." 
           << " - expected to be " << COLOR_RANGE_MAX 
           << endl;
      isSuccess = false;
    }
    else {
      isValidInput = true;
    }
  }

  ColorImageClass addedImage(imageLen, imageWid);
  TransparencyClass transMatrix(imageLen, imageWid);
  
  isValidInput = false;
  while (!isValidInput && isSuccess)  {
    cout << "Enter upper left corner to insert image row and column: " 
       << endl;
    cin >> inRow >> inCol;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid row or column input"  << '\n'
           << "Both should be positive integers" << '\n'
           << "try again" << endl;
      isSuccess = false;
    }
    else if (inRow < 0 || inCol < 0)  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid row or column input"  << '\n'
           << "Both should be positive integers" << '\n'
           << "try again" << endl;
      isSuccess = false;
    }
    else  {
      isValidInput = true;
    }
  }

  if (isSuccess)  {
    upperLeftLocation.setRowCol(inRow, inCol);
    transColor = selectColor("tranparency"); 
  }
  

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0; cInd < imageWid; cInd++)  {
      if (isSuccess)  {
        // store the inFile pixels to addedImage
        tempLocation.setRowCol(rInd, cInd);
        inFile >> tempRed;
        inFile >> tempGreen;
        inFile >> tempBlue;

        if (inFile.fail())  {
          cout << "Error found when reading the added image's pixel"
               << " - expected to be RGB integer values "
               << "between 0 and 255, inclusively" << endl;
          isSuccess = false;
        }
        tempPixel.setTo(tempRed, tempGreen, tempBlue);
        addedImage.setColorAtLocation(tempLocation, tempPixel);
        // get the pixel of addedImage 
        // compare it with user specified transColor
        // form the transMatrix
        tempLocation.setRowCol(rInd, cInd);
        addedImage.getColorAtLocation(tempLocation, tempPixel);
        if (transColor.compareColor(tempPixel))  {
          transMatrix.setTransAtLocation(tempLocation);
        }
        else if (!transColor.compareColor(tempPixel))  {
          transMatrix.setNotTransAtLocation(tempLocation);
        }
      }
    }
  }

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0;  cInd < imageWid; cInd++)  {
      if (isSuccess)  {
        // edit the image if the bool at the location
        // is not transparent
        if (!transMatrix.getTransAtLocation(rInd, cInd))  {
          tempLocation.setRowCol(rInd, cInd);
          addedImage.getColorAtLocation(tempLocation, tempPixel);
          tempLocation.setRowCol(upperLeftLocation.getRow() + rInd,
            upperLeftLocation.getCol() + cInd);
          image.setColorAtLocation(tempLocation, tempPixel);
        }
      }
    }
  }

}