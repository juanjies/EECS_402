ColorImageClass::ColorImageClass(int imageLen, int imageWid)  {
  for (int i = 0; i < imageLen; i++)  {
    for (int j = 0; j < imageWid; j++)  {
      image[i][j].setToBlack();
    }
  }
}

void ColorImageClass::initializeTo(ColorClass &inColor)  {
  for (int i = 0; i < IMAGE_ROW; i++)  {
    for (int j = 0; j < IMAGE_COL; j++)  {
      image[i][j].setTo(inColor);
    }
  }
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)  {
  bool doClip = false;

  for (int i = 0; i < IMAGE_ROW; i++)  {
    for (int j = 0; j < IMAGE_COL; j++)  {
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
  for (int i = 0; i < IMAGE_ROW; i++)  {
    for (int j = 0; j < IMAGE_COL; j++)  {
      image[i][j].setTo(imagesToAdd[numImgsToAdd-1].image[i][j]);
    }
  }
  return doClip;
}

bool ColorImageClass::setColorAtLocation(
       RowColumnClass &inRowCol, ColorClass &inColor
       )  {
  if (inRowCol.getRow() < IMAGE_ROW && inRowCol.getCol() < IMAGE_COL)  {
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
  if (inRowCol.getRow() < IMAGE_ROW && inRowCol.getCol() < IMAGE_COL)  {
    outColor.setTo(image[inRowCol.getRow()][inRowCol.getCol()]);
    return true;
  }
  else  {
    return false;
  }
}

void ColorImageClass::printImage()  {
  for (int i = 0; i < IMAGE_ROW; i++)  {
    for (int j = 0; j < IMAGE_COL; j++)  {
      if (j == (IMAGE_COL-1)) {
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