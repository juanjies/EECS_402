#ifndef _ColorImageClass_H_
#define _ColorImageClass_H_

#include "ColorClass.h"
#include "RowColumnClass.h"

class ColorImageClass  {
  private:
    ColorClass **image;
    int arrayLen, arrayWid;

  public:
    // set up a 2D array
    // value ctor sets all pixels to black
    ColorImageClass(int imageLen, int imageWid);
    // dtor: free the dynamic allocation 
    ~ColorImageClass();
    // initializes all image pixels to the input
    void initializeTo(ColorClass &inColor);
    // pixel-wise addition of color index
    // return true if there's any clipping
    bool addImageTo(ColorImageClass &rhsImg);
    // set the image values to be the sum of the all images input
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
    // set the pixel at the input location to the input color
    // return true if the location is valid 
    // return false if the location is not valid  
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    // set"outColor" to the pixel at the input location 
    // return true if the location is valid 
    // return false if the location is not valid
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    // print the contents of the image
    void printImage(ofstream &outFile);
};

#endif