#ifndef _ColorClass_H_
#define _ColorClass_H_
#include <fstream>
#include <iostream>

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: Provide a ColorClass to process RGB values in a single pixel 

class ColorClass  {
  private:
    int valRed;
    int valGreen;
    int valBlue;

  public:
    // default constructor to set RGB to the max range
    // which is while color
    ColorClass();
    // value ctor to set RGB to the input values
    ColorClass(int inRed, int inGreen, int inBlue);
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    // check if clipping is necessary for the input color index
    // reture true for necessary
    bool needClip(int inColor);
    // clip the input color 
    // and return the clipped value
    int  clipColor(int inColor);
    // set RGB as the input values
    // if any of input values need to be clipped
    // return true
    bool setTo(int inRed, int inGreen, int inBlue);
    // set the color as the same as that in the input object
    // if any of input color values needs to be clipped
    // return true
    bool setTo(ColorClass &inColor); 
    // add the color values of the input object 
    // if any of result color values needs to be clipped
    // return true
    bool addColor(ColorClass &rhs);
    // subtract the color values of the input object 
    // if any of result color values needs to be clipped
    // return true  
    bool subtractColor(ColorClass &rhs);
    // multiply the RGB index by the input factor
    // cast the product value as an integer 
    // return true if there's any clipping
    bool adjustBrightness(double adjFactor);
    // print out value as "R:<> G:<> B:<>" to console
    void printComponentValues();
    // print out value as "<R> <G> <B> " to the output file stream
    void printComponentValues(ofstream &outFile);
};

#endif