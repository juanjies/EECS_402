#include <iostream>
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "selectColor.h"
#include <string>
#include "TransparencyClass.h"
#include "RowColumnClass.h"
using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: insert an image to the input image
void insertImage(ColorImageClass &image)  {
  bool  isValidInput = false;
  int imageWid = 0, imageLen = 0;
  int maxColorValue = 0;
  int inRow = 0, inCol = 0;
  istream inFile;
  string fileName, magicNum;
  ColorClass transColor;
  ColorImageClass addedImage;
  RowColumnClass upperLeftLocation, tempLocation;

  cout << "Enter string for file name of PPM image to insert: " << endl;
  cin >> fileName;
  inFile.open(filename.c_str());

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
      isValidInput = true;
    }
  }

  inFile >> magicNum;
  inFile >> imageWid;
  inFile >> imageLen;
  inFile >> maxColorValue;
  // .ppm contents checking

  TransparencyClass transMatrix(imageLen, imageWid);

  transColor = selectColor(); // cout problem here
  // cout text always show rectangle color

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0; cInd < imageWid; cInd++)  {
      inFile >> addedImage[rInd][cInd];
      if (transColor.compareColor(addedImage[rInd][cInd]))  {
        transMatrix[rInd][cInd] == 0;
      }
      else if (!transColor.compareColor(addedImage[rInd][cInd]))  {
        transMatrix[rInd][cInd] == 1;
      }
    }
  }

  cout << "Enter upper left corner to insert image row and column: " 
       << endl;
  cin >> inRow >> inCol;
  upperLeftLocation.setRowCol(inRow, inCol);

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0;  cInd < imageWid; cInd++)  {
      if (transMatrix[rInd][cInd] == 1)  {
        tempLocation.setRowCol(upperLeftLocation.getRow() + rInd,
          upperLeftLocation.getCol() + cInd);
        image.setColorAtLocation(tempLocation, addedImage[rInd][cInd]);
      }
      else if (transMatrix[rInd][cInd] == 0) {
        ;
      }
    }
  }
}