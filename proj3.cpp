#include <iostream>
#include <fstream>
#include <cstdlib>
#include "constants.h"
#include "ColorClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: EECS402 Project 3 - Use dynamic allocation to implement image
//          editing with a UNIX Makefile to link multiple .h and .cpp files. 

const int igoredCharLen = 300;

int main ()  {
  string fileName;
  ifstream inFile;
  ofstream outFile;
  string magicNum; // temp
  int imageWid = 0, imageLen = 0, maxColorValue = 0; // temp
  int inRed = 0, inGreen = 0, inBlue = 0;
  bool isValidInput = false;
  
  cout << "Enter string for PPM image file name to load: " << endl;
  cin >> fileName;
  inFile.open(fileName.c_str()); 
  
  if (inFile.fail())  {
		cout << "Unable to open input file!" << endl;
    exit(1);
	}
	
  while (!isValidInput)  {

    if (inFile.eof())  {
			cout << "EOF before reading the image" << endl;
      exit(2);
		}
		else if (inFile.fail())  {
			inFile.clear();
      inFile.ignore(igoredCharLen, '\n');
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
      inFile >> inRed >> inGreen >> inBlue;
      pixelMatrix[rInd][cInd] = ColorClass(inRed, inGreen, inBlue); 
    }
  }
  // Deletion
  for (int rInd = 0; rInd < imageLen; rInd++)  {
    delete [] pixelMatrix[rInd];
  }
  delete [] pixelMatrix;
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