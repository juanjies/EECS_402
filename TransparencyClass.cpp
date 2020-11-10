#include "TransparencyClass.h"
#include "RowColumnClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: Provide a Transparency class to help add pattern and image
//          0 means transparent, 1 means not transparent

TransparencyClass::TransparencyClass(int inRow, int inCol)  {
  matrixLen = inRow;
  matrixWid = inCol;

  transMatrix = new int *[matrixLen];
  for (int rInd = 0; rInd < matrixLen; rInd++)  {
    transMatrix[rInd] = new int[matrixWid];
  }  

  for (int i = 0; i < matrixLen; i++)  {
    for (int j = 0; j < matrixWid; j++)  {
      transMatrix[i][j] = 0;
    }
  }
}

TransparencyClass::~TransparencyClass()  {
  for (int rInd = 0; rInd < matrixLen; rInd++)  {
    delete [] transMatrix[rInd];
  }
  delete [] transMatrix;
}

bool TransparencyClass::getTransAtLocation(int inRow, int inCol)  {
  bool isTrans = false;
  if (transMatrix[inRow][inCol] == 1)  {
    isTrans = false;
  }
  else if (transMatrix[inRow][inCol] == 0)  {
    isTrans = true;
  }
  return isTrans;
}

void TransparencyClass::setTransAtLocation(RowColumnClass &inRowCol)  {
  transMatrix[inRowCol.getRow()][inRowCol.getCol()] = 0;
}

void TransparencyClass::setNotTransAtLocation(RowColumnClass &inRowCol)  {
  transMatrix[inRowCol.getRow()][inRowCol.getCol()] = 1;
}