#include <iostream>
#include <fstream>
using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: EECS402 Project 3 - Use dynamic allocation to implement image
//          editing with a UNIX Makefile to link multiple .h and .cpp files. 

const int igoredCharLen = 300;

int main ()  {
  string fileName;
  ifstream inFile;
  string magicNum; // temp
  int imageWid = 0, imageLen = 0; // temp
  bool isValidInput = false;

  cout << "Enter string for PPM image file name to load: " << endl;
  cin >> fileName;
  
  inFile.open("fileName.c_str()"); 
  
  if (inFile.fail())  {
		cout << "Unable to open input file!" << endl;
    exit;
	}
	
  while (!isValidInput)  {
        
    // inFile >> magicNum;
    // cout << "Magic Number is: " << magicNum << endl;
    inFile >> imageWid;
    inFile >> imageLen;

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
		
    cout << "Image Width = " << imageWid << endl;
    cout << "Image Length = " << imageLen << endl;
	}

  inFile.close();
  
  return 0;
}