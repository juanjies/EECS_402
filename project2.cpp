
#include <iostream>
using namespace std;
// Programmer: Juan-Jie Sun
// Date: October 2020
// Purpose: EECS402 Project 2: create a framework of useful classes        
//                             dealing with images and colors.

class RowColumnClass
{
  private:
    int rowIndex;  // Q: should it be a const?
    int colIndex;  // Q: should it be a const?

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
/*
  Main func is not required in this project but
  used to test the created classes. 
*/
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

/*
  This default ctor initialize both the row and 
  column values to -99999.
*/
RowColumnClass::RowColumnClass()
{
  int defValue = -99999; // Q: should it be a const?
  rowIndex = defValue;
  colIndex = defValue;
}
/*
  This ctor sets the row and column values to the 
  corresponding values passed in.
*/
RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  rowIndex = inRow;
  colIndex = inCol;
}
/* 
  set the both attributes of RowIndex and ColIndex 
  to the values passed in
*/
RowColumnClass::setRowCol(int inRow, int inCol)
{
  rowIndex = inRow;
  colIndex = inCol;
}
/* 
  set the attribute of RowIndex to the values passed in
*/
RowColumnClass::setRow(int inRow)
{
  rowIndex = inRow;
}
/* 
  set the attribute of ColIndex to the values passed in
*/
RowColumnClass::setCol(int inCol)
{
  colIndex = inCol;
}
// get the attribute value of RowIndex
RowColumnClass::getRow()
{
  return rowIndex;
}
// get the attribute value of ColIndex
RowColumnClass::getCol()
{
  return colIndex;
}
/* 
  adds the row and column index values in the input parameter 
  to the row and column index of the object the func is called on
*/
RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
  setRow(getRow + inRowCol.getRow);
  setCol(getCol + inRowCol.getCol);
}
// prints the attributes' values of rowIndex and colIndex
RowColumnClass::printRowCol()
{
  cout << "[" << rowIndex << ',' << colIndex << "]" << endl;
}
