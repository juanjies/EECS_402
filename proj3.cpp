#include <iostream>
#include <fstream>
using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: EECS402 Project 3 - Use dynamic allocation to implement image
//          editing with a UNIX Makefile to link multiple .h and .cpp files. 

int main ()  {
  string fileName;
  ifstream inFile;
  string magicNum; // temp
  int imageWid, imageLen; // temp

  cout << "Enter string for PPM image file name to load: " << endl;
  cin >> fileName;
  
  inFile.open("fileName.c_str()"); 
  
  inFile >> magicNum;
  cout << "Magic Number is: " << magicNum << endl;
  inFile >> imageWid;
  inFile >> imageLen;
  cout << "Image width = " << imageWid << endl;
  cout << "Image Length = " << imageLen << endl;

  inFile.close();
  
  return 0;
}