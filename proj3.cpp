#include <iostream>
#include <fstream>
#include <cstdlib>
#include "constants.h"
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "RowColumnClass.h"

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

  int imageWid = 0, imageLen = 0, maxColorValue = 0; // temp
  int tempRed = 0, tempGreen = 0, tempBlue = 0;
  bool isValidInput = false;
  
  cout << "Enter string for PPM image file name to load: " << endl;
  cin >> fileName;
  inFile.open(fileName.c_str()); 
  
  if (inFile.fail())  {
		cout << "Unable to open input file!" << endl;
    exit(1);
	}
	// file error checking
  while (!isValidInput)  {
    if (inFile.eof())  {
			cout << "EOF before reading the image" << endl;
      exit(2);
		}
		else if (inFile.fail())  {
			inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
		}
    else  {
      isValidInput = true;
    }
  }

  inFile >> magicNum;
  cout << "Magic Number is: " << magicNum << endl;

  inFile >> imageWid;
  inFile >> imageLen;
  inFile >> maxColorValue;
  cout << "Image Width = " << imageWid << endl;
  cout << "Image Length = " << imageLen << endl;
  cout << "Max color value = " << maxColorValue << endl;

  cout << "Enter string for PPM file name to output: " << endl;
  cin >> fileName;
  outFile.open(fileName.c_str()); 

  ColorImageClass image(imageLen, imageWid);
  
  outFile << magicNum << endl;
  outFile << imageWid << " " << imageLen << endl;
  outFile << maxColorValue << endl;

  for (int rInd = 0; rInd < imageLen; rInd++)  {
    for (int cInd = 0; cInd < imageWid; cInd++)  {
      tempLocation.setRowCol(rInd, cInd);
      inFile >> tempRed;
      inFile >> tempGreen;
      inFile >> tempBlue;
      tempPixel.setTo(tempRed, tempGreen, tempBlue);
      image.setColorAtLocation(tempLocation, tempPixel);
      outFile << tempRed << " " << tempGreen << " " << tempBlue << " ";
    }
  }
  image.printImage();
  inFile.close();
  outFile.close();
}

/*
// temp ideas

// create a Dynamic 2D array
// Allocation    
ColorClass **pixelMatrix;  
pixelMatrix = new ColorClass*[imageLen];
for (int rInd = 0; rInd < imageLen; rInd++)  {
  pixelMatrix[rInd] = new ColorClass[imageWid];
}

for (int rInd = 0; rInd < imageLen; rInd++)  {
  for (int cInd = 0; cInd < imageWid; cInd++)  {
    // assign three R G B values as a pixel
    // pixelMatrix[rInd][cInd] = ColorClass(inRed, inGreen, inBlue); 
  }
}
// Deletion
for (int rInd = 0; rInd < imageLen; rInd++)  {
  delete [] pixelMatrix[rInd];
}
delete [] pixelMatrix;
*/