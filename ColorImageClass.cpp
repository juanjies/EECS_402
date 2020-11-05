#include "ColorImageClass.h"

ColorImageClass::ColorImageClass(int imageLen, int imageWid)  {
  arrayLen = imageLen;
  arrayWid = imageWid;

  image = new ColorClass*[arrayLen];
  for (int rInd = 0; rInd < arrayLen; rInd++)  {
    image[rInd] = new ColorClass[arrayWid];
  }  

  for (int i = 0; i < arrayLen; i++)  {
    for (int j = 0; j < arrayWid; j++)  {
      image[i][j].setToBlack();
    }
  }
}

ColorImageClass::~ColorImageClass()  {
  for (int rInd = 0; rInd < arrayLen; rInd++)  {
  delete [] image[rInd];
  }
  delete [] image;
}

void ColorImageClass::initializeTo(ColorClass &inColor)  {
  for (int i = 0; i < arrayLen; i++)  {
    for (int j = 0; j < ; j++)  {
      image[i][j].setTo(inColor);
    }
  }
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)  {
  bool doClip = false;

  for (int i = 0; i < arrayLen; i++)  {
    for (int j = 0; j < arrayWid; j++)  {
      doClip = image[i][j].addColor(rhsImg.image[i][j]) || doClip;
    }
  }
  return doClip;
}

bool ColorImageClass::addImages(int numImgsToAdd, 
                                ColorImageClass imagesToAdd [])  {
  bool doClip = false;
  // add image[k] to image [k+1] and loop through all images
  // so that the last image would be the sum of all images
  for (int k = 0; k < (numImgsToAdd-1); k++)  {
    doClip = (imagesToAdd[k+1].addImageTo(imagesToAdd[k]) || doClip);
  }
  // set the current image to that last image
  for (int i = 0; i < arrayLen; i++)  {
    for (int j = 0; j < arrayWid; j++)  {
      image[i][j].setTo(imagesToAdd[numImgsToAdd-1].image[i][j]);
    }
  }
  return doClip;
}

bool ColorImageClass::setColorAtLocation(
       RowColumnClass &inRowCol, ColorClass &inColor
       )  {
  if (inRowCol.getRow() < arrayLen && inRowCol.getCol() < arrayWid)  {
    image[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
    return true;
  }
  else  {
    return false;
  }
}

bool ColorImageClass::getColorAtLocation(
       RowColumnClass &inRowCol, ColorClass &outColor
       )  {
  if (inRowCol.getRow() < arrayLen && inRowCol.getCol() < arrayWid)  {
    outColor.setTo(image[inRowCol.getRow()][inRowCol.getCol()]);
    return true;
  }
  else  {
    return false;
  }
}

void ColorImageClass::printImage()  {
  for (int i = 0; i < arrayLen; i++)  {
    for (int j = 0; j < arrayWid; j++)  {
      if (j == (arrayLen-1)) {
        image[i][j].printComponentValues();
      }
      else  {
        image[i][j].printComponentValues();
      cout << "--";
      }
    }
    cout << endl;
  }
}