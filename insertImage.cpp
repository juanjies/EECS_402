#include <iostream>
#include <cstdlib>
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "selectColor.h"
#include <string>
#include "TransparencyClass.h"
#include "RowColumnClass.h"
#include "constants.h"
using namespace std;

// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: insert an image to the input image
void insertImage(ColorImageClass &image)  {
  bool  isValidInput = false;
  int imageWid = 0, imageLen = 0;
  int maxColorValue = 0;
  int inRow = 0, inCol = 0;
  int tempRed = 0, tempGreen = 0, tempBlue = 0;
  ifstream inFile;
  string fileName, magicNum;
  ColorClass transColor, tempPixel;
  RowColumnClass upperLeftLocation, tempLocation;

  cout << "Enter string for file name of PPM image to insert: " << endl;
  cin >> fileName;
  inFile.open(fileName.c_str());

  // error check for file opening process
  if (inFile.fail())  {
		cout << "Unable to open image file!" << endl;
    exit(1);
	}
	// pattern file contents error checking
  while (!isValidInput)  {
    if (inFile.eof())  {
			cout << "EOF before reading the image" << endl;
      exit(2);
		}
		else if (inFile.fail())  {
			inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid image" << endl;
		}
    else  {
      inFile >> magicNum;
      inFile >> imageWid;
      inFile >> imageLen;
      inFile >> maxColorValue;

      if (strcmp(magicNum.c_str(), MAGIC_NUM_PPM) != 0)  {
        cout << "The Magic Number of the .ppm file is invalid." << endl;
      }
      else if (maxColorValue != COLOR_RANGE_MAX)  {
        cout << "The maximum color value of the .ppm file is invalid." 
             << endl;
      }
      else if (imageWid < 0 || imageLen < 0)  {
        cout << "The dimension of the input .ppm file is invalid." << endl;
      }
      else {
        isValidInput = true;
      }
    }
  }

  ColorImageClass addedImage(imageLen, imageWid);
  TransparencyClass transMatrix(imageLen, imageWid);

  isValidInput = false;
  while (!isValidInput)  {
    cout << "Enter upper left corner to insert image row and column: " 
       << endl;
    cin >> inRow >> inCol;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid row or column input" << endl;
    }
    else  {
      isValidInput = true;
    }
  }

  upperLeftLocation.setRowCol(inRow, inCol);

  transColor = selectColor("tranparency"); 

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0; cInd < imageWid; cInd++)  {
      // store the inFile pixels to addedImage
      tempLocation.setRowCol(rInd, cInd);
      inFile >> tempRed;
      inFile >> tempGreen;
      inFile >> tempBlue;
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

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0;  cInd < imageWid; cInd++)  {
      // edit the image if the bool at the location
      // is not transparent
      if (!transMatrix.getTransAtLocation(rInd, cInd))  {
        tempLocation.setRowCol(rInd, cInd);
        addedImage.getColorAtLocation(tempLocation, tempPixel);
        tempLocation.setRowCol(upperLeftLocation.getRow() + rInd,
          upperLeftLocation.getCol() + cInd);
        image.setColorAtLocation(tempLocation, tempPixel);
      }
      // if it is transparent, then do nothing
      else if (transMatrix.getTransAtLocation(rInd, cInd)) {
        ;
      }
    }
  }
}