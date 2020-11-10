#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: December 2020
// Purpose: Implementations for RowColumnClass

RowColumnClass::RowColumnClass()  {
  rowIndex = DEF_ROW_COL_VALUE;
  colIndex = DEF_ROW_COL_VALUE;
}

RowColumnClass::RowColumnClass(int inRow, int inCol)  {
  rowIndex = inRow;
  colIndex = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol)  {
  rowIndex = inRow;
  colIndex = inCol;
}

void RowColumnClass::setRow(int inRow)  {
  rowIndex = inRow;
}

void RowColumnClass::setCol(int inCol)  {
  colIndex = inCol;
}

int RowColumnClass::getRow()  {
  return rowIndex;
}

int RowColumnClass::getCol()  {
  return colIndex;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)  {
  setRow(getRow() + inRowCol.getRow());
  setCol(getCol() + inRowCol.getCol());
}

void RowColumnClass::printRowCol()  {
  cout << "[" << rowIndex << ',' << colIndex << "]";
}