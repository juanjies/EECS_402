#ifndef _RowColumnClass_H_
#define _RowColumnClass_H_

class RowColumnClass
{
  private:
    int rowIndex;  
    int colIndex;  

  public:
    // set rowIndex and colIndex to the default negative value
    RowColumnClass();
    // value ctor:setting the row and column values to the values passed in
    RowColumnClass(int inRow, int inCol);
    void setRowCol(int inRow, int inCol);
    void setRow(int inRow);
    void setCol(int inCol);
    int getRow();
    int getCol();
    //  adds the row and column index values in the input parameter 
    //  to the row and column index 
    void addRowColTo(RowColumnClass &inRowCol);
    // prints the attributes' values of rowIndex and colIndex
    void printRowCol();
};

#endif