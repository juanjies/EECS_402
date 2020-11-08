#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"
#include "selectColor.h"
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "selectFill.h"

// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: to annotate an image with a rectangle
void annotateRect(ColorImageClass &image)  {
  int rectOption = 0;
  int inRow = 0, inCol = 0, numRow = 0, numCol = 0;
  bool isValidInput = false;
  ColorClass rectColor;
  RowColumnClass upperLeftLocation, lowerRightLocation, tempLocation;

  cout << "1. Specify upper left and lower right corners of rectangle"
       << '\n'
       << "2. Specify upper left corner and dimensions of rectangle"
       << '\n'
       << "3. Specify extent from center of rectangle" << '\n';
         
  
  while (!isValidInput)  {
    cout << "Enter int for retangle specification method" << endl;
    cin >> rectOption;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid specification method input" << endl;
    }
    else if (rectOption > 3 || rectOption < 1)  {
      cout << "Invalid specification method input" << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  // method 1 - upper left and lower right
  if (rectOption == 1)  {
    isValidInput = false;
    // error checking for row and column input
    while (!isValidInput)  {
      // get rectangle region
      cout << "Enter upper left corner row and column: " << endl;
      cin >> inRow >> inCol;
      upperLeftLocation.setRowCol(inRow, inCol);
      cout << "Enter lower right corner row and column: " << endl;
      cin >> inRow >> inCol;
      lowerRightLocation.setRowCol(inRow, inCol);
 
      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid input!";
      }
      else  {
        isValidInput = true;
      }
    }
  }  
  // method 2 - upper left and dimension
  else if (rectOption == 2)  {
    isValidInput = false;

    while (!isValidInput)  {
      cout << "Enter upper left corner row and column: " << endl;
      cin >> inRow >> inCol;
      upperLeftLocation.setRowCol(inRow, inCol);
      cout << "Enter int for number of rows: " << endl;
      cin >> numRow;
      cout << "Enter int for number of columns " << endl;
      cin >> numCol;
      lowerRightLocation.setRowCol(inRow + numRow, inCol + numCol);

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid input!";
      }
      else  {
        isValidInput = true;
      }
    }
  }
  // method 3 - center and dimension
  else if (rectOption == 3)  {
    isValidInput = false;

    while (!isValidInput)  {
      cout << "Enter rectangle center row and column: " << endl;
      cin >> inRow >> inCol;
      cout << "Enter int for half number of rows: " << endl;
      cin >> numRow;
      cout << "Enter int for half number of columns " << endl;
      cin >> numCol;
      upperLeftLocation.setRowCol(inRow - numRow, inCol - numCol);
      lowerRightLocation.setRowCol(inRow + numRow, inCol + numCol);

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid input!";
      }
      else  {
        isValidInput = true;
      }
    }
  } 

  // get rectangle color
  rectColor = selectColor();

  // annotate the input object 
  if (selectFill())  {
    for (int rInd = 0; 
          rInd < lowerRightLocation.getRow() - upperLeftLocation.getRow();
          rInd++)  {
      for (int cInd = 0;
          cInd < lowerRightLocation.getCol() - upperLeftLocation.getCol();
          cInd++)  {
        tempLocation.setRowCol(rInd, cInd);
        image.setColorAtLocation(tempLocation, rectColor);
      }
    }
  }
  else if (!selectFill())  {
    // loop throught the top and the bottom row
    for (int rInd = 0;
          rInd < lowerRightLocation.getRow() - upperLeftLocation.getRow();
          rInd++)  {
      // top row of the empty rectangle
      int cInd;
      cInd = upperLeftLocation.getCol();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
      // bottom row of the empty rectangle
      cInd = lowerRightLocation.getCol();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
    }
    // loop throught the left and the right column
    for (int cInd = 0;
          cInd < lowerRightLocation.getCol() - upperLeftLocation.getCol();
          cInd++)  {
      // left column of the empty rectangle
      int rInd;
      rInd = upperLeftLocation.getRow();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
      // right column of the empty rectangle
      rInd = lowerRightLocation.getRow();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
    }
  }
}