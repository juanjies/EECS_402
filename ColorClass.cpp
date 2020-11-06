#include <iostream>
#include <fstream>
#include "ColorClass.h"
#include "constants.h"
using namespace std;

// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: Provide the inplementations for ctor and method in ColorClass

ColorClass::ColorClass() 
{
  valRed = COLOR_RANGE_MAX;
  valGreen = COLOR_RANGE_MAX;
  valBlue = COLOR_RANGE_MAX;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  valRed = clipColor(inRed);
  valGreen = clipColor(inGreen);
  valBlue = clipColor(inBlue);
}

void ColorClass::setToBlack()
{
  valRed = COLOR_RANGE_MIN;
  valGreen = COLOR_RANGE_MIN;
  valBlue = COLOR_RANGE_MIN;
}

void ColorClass::setToRed()
{
  valRed = COLOR_RANGE_MAX;
  valGreen = COLOR_RANGE_MIN;
  valBlue = COLOR_RANGE_MIN;
}

void ColorClass::setToGreen()
{
  valRed = COLOR_RANGE_MIN;
  valGreen = COLOR_RANGE_MAX;
  valBlue = COLOR_RANGE_MIN;
}

void ColorClass::setToBlue()
{
  valRed = COLOR_RANGE_MIN;
  valGreen = COLOR_RANGE_MIN;
  valBlue = COLOR_RANGE_MAX;
}

void ColorClass::setToWhite()
{
  valRed = COLOR_RANGE_MAX;
  valGreen = COLOR_RANGE_MAX;
  valBlue = COLOR_RANGE_MAX;
}

bool ColorClass::needClip(int inColor)
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

int ColorClass::clipColor(int inColor)
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

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{ 
  valRed = clipColor(inRed);
  valGreen = clipColor(inGreen);
  valBlue = clipColor(inBlue);
  
  return (needClip(inRed) 
          || needClip(inGreen)
          || needClip(inBlue));
}

bool ColorClass::setTo(ColorClass &inColor)
{
  valRed = clipColor(inColor.valRed);
  valGreen = clipColor(inColor.valGreen);
  valBlue = clipColor(inColor.valBlue);

  return (needClip(inColor.valRed) 
          || needClip(inColor.valGreen)
          || needClip(inColor.valBlue));
}

bool ColorClass::addColor(ColorClass &rhs)
{
  bool doClip = false;
  doClip = needClip(valRed + rhs.valRed)
           || needClip(valGreen + rhs.valGreen)
           || needClip(valBlue + rhs.valBlue);

  valRed = clipColor(valRed + rhs.valRed);
  valGreen = clipColor(valGreen + rhs.valGreen);
  valBlue = clipColor(valBlue + rhs.valBlue);
  return doClip;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
  bool doClip = false;
  doClip = needClip(valRed - rhs.valRed)
           || needClip(valGreen - rhs.valGreen)
           || needClip(valBlue - rhs.valBlue);

  valRed = clipColor(valRed - rhs.valRed);
  valGreen = clipColor(valGreen - rhs.valGreen);
  valBlue = clipColor(valBlue - rhs.valBlue);
  return doClip;
}

bool ColorClass::adjustBrightness(double adjFactor)
{
  bool doClip = false;
  doClip = needClip(valRed * adjFactor)
           || needClip(valGreen * adjFactor)
           || needClip(valBlue * adjFactor);

  valRed = clipColor(static_cast< int >(valRed * adjFactor) );
  valGreen = clipColor(static_cast< int >(valGreen * adjFactor) );
  valBlue = clipColor(static_cast< int >(valBlue * adjFactor) );
  return doClip;
}

void ColorClass::printComponentValues(ofstream outFile)
{
  cout << "R: " << valRed   << " "
       << "G: " << valGreen << " "
       << "B: " << valBlue;
  outFile << valRed << " " << valGreen << " " << valBlue << " ";
}