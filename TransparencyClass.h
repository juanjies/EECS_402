#ifndef _TransparencyClass_H_
#define _TransparencyClass_H_
#include "RowColumnClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: Provide a transparency class to help add pattern and image
//          0 means transparent, 1 means not transparent

class TransparencyClass  {
  private:
    int **transMatrix;
    int matrixLen, matrixWid;

  public:
    // set up a matrix based on input dimension
    // value ctor sets all element to 0
    TransparencyClass(int inRow, int inCol);
    // dtor: free the dynamic allocation
    ~TransparencyClass();
    // return true if it is 1 at the input location
    // reutrn false if it is 0 at the input location
    bool getTransAtLocation(int inRow, int inCol);
    // assign 1 at the given matrix location
    void setTransAtLocation(RowColumnClass &inRowCol);
    // assign 0 at the given matrix location
    void setNotTransAtLocation(RowColumnClass &inRowCol);
};
#endif
