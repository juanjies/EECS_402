#include <iostream>
using namespace std;
// Programmer: Juan-Jie Sun
// Date: October 2020
// Purpose: EECS402 Project 2: create a framework of useful classes        
//                             dealing with images and colors.

const int COLOR_RANGE_MAX = 1000;
const int COLOR_RANGE_MIN = 0;
const int DEF_ROW_COL_VALUE = -99999; // Q: should it be a const? >> global const
  // where should I declear global const?
const int IMAGE_ROW = 10;
const int IMAGE_COL = 18;

bool needClip(int inColor); // global func
// warning UNDEFINED REFERENCE 
int  clipColor(int inColor);

class ColorClass
{
  private:
    int inRed;
    int inGreen;
    int inBlue;

  public:
    ColorClass();
    // ~ColorClass(); // do we need to have destructors?
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    bool setTo(int inRed, int inGreen, int inBlue);
    bool setTo(ColorClass &inColor); 
    bool addColor(ColorClass &rhs);
    bool subtractColor(ColorClass &rhs);
    bool adjustBrightness(double adjFactor);
    void printComponentValues();
};

// default constructor to set RGB to the max range
ColorClass::ColorClass() 
// Q: the order of class prototpye, main func, scope resolution
{
  inRed = COLOR_RANGE_MAX;
  inGreen = COLOR_RANGE_MAX;
  inBlue = COLOR_RANGE_MAX;
}

// set color to black
void ColorClass::setToBlack()
{
  inRed = COLOR_RANGE_MIN;
  inGreen = COLOR_RANGE_MIN;
  inBlue = COLOR_RANGE_MIN;
}

// set color to red
void ColorClass::setToRed()
{
  inRed = COLOR_RANGE_MAX;
  inGreen = COLOR_RANGE_MIN;
  inBlue = COLOR_RANGE_MIN;
}

// set color to green
void ColorClass::setToGreen()
{
  inRed = COLOR_RANGE_MIN;
  inGreen = COLOR_RANGE_MAX;
  inBlue = COLOR_RANGE_MIN;
}

// set color to blue
void ColorClass::setToBlue()
{
  inRed = COLOR_RANGE_MIN;
  inGreen = COLOR_RANGE_MIN;
  inBlue = COLOR_RANGE_MAX;
}

// set color to white
void ColorClass::setToWhite()
{
  inRed = COLOR_RANGE_MAX;
  inGreen = COLOR_RANGE_MAX;
  inBlue = COLOR_RANGE_MAX;
}

// check if clipping is necessary for the input color index
// reture true for necessary
bool needClip(int inColor)
{
  if (inColor > COLOR_RANGE_MAX)
  {
    return true;
  }
  else if (inColor < COLOR_RANGE_MIN)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// clip the input color 
int clipColor(int inColor)
{
  if (inColor < COLOR_RANGE_MIN)
  {
    inColor = COLOR_RANGE_MIN;
  }
  else if (inColor > COLOR_RANGE_MAX)
  {
    inColor = COLOR_RANGE_MAX;
  }
  else
  {
    ;
  }
  return inColor;
}

// set RGB as the input values
// if any of input values need to be clipped
// return true
bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{ 
// Q: wouldn't input inRed have conflict with the attribute inRed?
  inRed = clipColor(inRed);
  inGreen = clipColor(inGreen);
  inBlue = clipColor(inBlue);
  
  return ((needClip(inRed) 
          || needClip(inGreen)
          || needClip(inBlue) ));
}

// set the color as the same as that in the input object
// if any of input color values needs to be clipped
// return true
bool ColorClass::setTo(ColorClass &inColor)
{
  inRed = clipColor(inColor.inRed);
  inGreen = clipColor(inColor.inGreen);
  inBlue = clipColor(inColor.inBlue);

  return ((needClip(inColor.inRed) 
          || needClip(inColor.inGreen)
          || needClip(inColor.inBlue)));
}

// add the color values of the input object 
// if any of result color values needs to be clipped
// return true
bool ColorClass::addColor(ColorClass &rhs)
{
  bool doClip = false;
  doClip = needClip(inRed + rhs.inRed)
           || needClip(inGreen + rhs.inGreen)
           || needClip(inBlue + rhs.inBlue);

  inRed = clipColor(inRed + rhs.inRed);
  inGreen = clipColor(inGreen + rhs.inGreen);
  inBlue = clipColor(inBlue + rhs.inBlue);
  return doClip;
}

// subtract the color values of the input object 
// if any of result color values needs to be clipped
// return true
bool ColorClass::subtractColor(ColorClass &rhs)
{
  bool doClip = false;
  doClip = needClip(inRed - rhs.inRed)
           || needClip(inGreen - rhs.inGreen)
           || needClip(inBlue - rhs.inBlue);

  inRed = clipColor(inRed - rhs.inRed);
  inGreen = clipColor(inGreen - rhs.inGreen);
  inBlue = clipColor(inBlue - rhs.inBlue);
  return doClip;
}

// multiply the RGB index by the input factor
// return true if there's any clipping
bool ColorClass::adjustBrightness(double adjFactor)
{
  bool doClip = false;
  doClip = needClip(inRed * adjFactor)
           || needClip(inGreen * adjFactor)
           || needClip(inBlue * adjFactor);

  inRed = clipColor(static_cast< int >(inRed * adjFactor) );
  inGreen = clipColor(static_cast< int >(inGreen * adjFactor) );
  inBlue = clipColor(static_cast< int >(inBlue * adjFactor) );
  return doClip;
}

// print out value as "R:<> G:<> B:<>"
void ColorClass::printComponentValues()
{
  cout << "R: " << inRed   << " "
       << "G: " << inGreen << " "
       << "B: " << inBlue  << endl; 
}

class RowColumnClass
{
  private:
    int rowIndex;  
    int colIndex;  

  public:
    RowColumnClass();
    RowColumnClass(int inRow, int inCol);
    void setRowCol(int inRow, int inCol);
    void setRow(int inRow);
    void setCol(int inCol);
    int getRow();
    int getCol();
    void addRowColTo(RowColumnClass &inRowCol);
    void printRowCol();
};

class ColorImageClass
{
  private:
    ColorClass image[IMAGE_ROW][IMAGE_COL];

  public:
    ColorImageClass();
    void initializeTo(ColorClass &inColor);
    bool addImageTo(ColorImageClass &rhsImg);
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd []);
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    void printImage();
  // ~ColorImageClass();
};

// default ctor sets all pixels to black
ColorImageClass::ColorImageClass()
{
  for (int i = 0; i < IMAGE_COL; i++)
  {
    for (int j = 0; j < IMAGE_ROW; j++)
    {
      image[i][j].setToBlack();
    }
  }
}

// initializes all image pixels to the input
void ColorImageClass::initializeTo(ColorClass &inColor)
{
  for (int i = 0; i < IMAGE_COL; i++)
  {
    for (int j = 0; j < IMAGE_ROW; j++)
    {
      image[i][j].setTo(inColor);
    }
  }
}

// pixel-wise addition of color index
// return true if there's any clipping
bool ColorImageClass::addImageTo(ColorImageClass &rhsImg);
{
  bool doClip = false;

  for (int i = 0; i < IMAGE_COL; i++)
  // does it matter to loop thro col or row first?
  {
    for (int j = 0; j < IMAGE_ROW; j++)
    {
      doClip = doClip || needClip(image[i][j].addColor(rhsImg[i][j]));
      clipColor(image[i][j].addColor(rhsImg[i][j]));
    }
  }
  return doClip;
}

// set the image values to be the sum of the corresponding 
// pixels in each image in the imagesToAdd input
bool ColorImageClass::addImages(int numImgsToAdd, ColorImageClass imagesToAdd [])
{
  bool doClip = false;

  for (int i = 0; i < IMAGE_COL; i++) 
  {
    for (int j = 0; j < IMAGE_ROW; j++)
    {
      for (int k = 0; i < (numImgsToAdd-1); k++)
      {
        doClip = doClip || 
                 needClip(imagesToAdd[k+1].addColor(imagesToAdd[k]));
        clipColor(imagesToAdd[k+1].addColor(imagesToAdd[k]));
      }
      image[i][j].setTo(imagesToAdd[numImgsToAdd].[i][j]);
    }
  }
  return doClip;
}

// set the pixel at the input location to the input color
// return true if the location is valid 
// return false if the location is not valid
bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor)
{
  if (inRowCol.getRow() < IMAGE_ROW && inRowCol.getCol() < IMAGE_COL)
  {
    image.setTo(inColor);
    return true;
  }
  else
  {
    return false;
  }
}

// set"outColor" to the pixel at the input location 
// return true if the location is valid 
// return false if the location is not valid
bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor)
{
  if (inRowCol.getRow() < IMAGE_ROW && inRowCol.getCol() < IMAGE_COL)
  {
    outColor.setTo(image[inRowCol.getRow()][inRowCol.getCol()])
    return true;
  }
  else
  {
    return false;
  }
}

// print the contents of the image
void ColorImageClass::printImage()
{
  for (int i = 0; i < IMAGE_COL; i++)
  {
    for (int j = 0; j < IMAGE_ROW; j++)
    {
      cout << "R: " << image[i][j].inRed << " "
           << "G: " << image[i][j].inGreen << " "
           << "B: " << image[i][j].inBlue << "--";
    }
    cout << endl;
  }
}

//  Main func is not required in this project but
//  used to test the created classes. 
int main()
{
  int rowIndexTemp = 11;
  int colIndexTemp = 36;
  RowColumnClass testRowColClass(0, 0);

  testRowColClass.printRowCol();
  testRowColClass.setRowCol(rowIndexTemp, colIndexTemp);
  testRowColClass.printRowCol();

  return 0;
}

// a default ctor 
// initialize both the row and column values to -99999.
RowColumnClass::RowColumnClass()
{
  rowIndex = DEF_ROW_COL_VALUE;
  colIndex = DEF_ROW_COL_VALUE;
}

//  a value ctor
//  setting the row and column values to the values passed in.
RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  rowIndex = inRow;
  colIndex = inCol;
}

//  set the both attributes of RowIndex and ColIndex 
//  to the values passed in

void RowColumnClass::setRowCol(int inRow, int inCol)
{
  rowIndex = inRow;
  colIndex = inCol;
}

//  set the attribute of RowIndex to the values passed in
void RowColumnClass::setRow(int inRow)
{
  rowIndex = inRow;
}

//  set the attribute of ColIndex to the values passed in
void RowColumnClass::setCol(int inCol)
{
  colIndex = inCol;
}

// get the attribute value of RowIndex
int RowColumnClass::getRow()
{
  return rowIndex;
}

// get the attribute value of ColIndex
int RowColumnClass::getCol()
{
  return colIndex;
}

//  adds the row and column index values in the input parameter 
//  to the row and column index of the object the func is called on
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
  setRow(getRow() + inRowCol.getRow());
  setCol(getCol() + inRowCol.getCol());
}

// prints the attributes' values of rowIndex and colIndex
void RowColumnClass::printRowCol()
{
  cout << "[" << rowIndex << ',' << colIndex << "]" << endl;
}

