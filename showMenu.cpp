
int showMenu();

void showMenu()  {
  int mainMenuOpt = 0, recMethod = 0, recColor = 0, recFillOpt = 0;

  while (mainMenuOpt !=5)  {
    cout << "1. Annotate image with rectangle" << '\n'
         << "2. Annotate image with pattern from file" << '\n'
         << "3. Insert another image" << '\n'
         << "4. Write out current image" << '\n'
         << "5. Exit the program" << '\n'
         << "Enter int for main menu choice: " << endl;
    cin >> mainMenuOpt;
    
    if (mainMenuOpt == 1)  {
      cout << "1. Specify upper left and lower right corners of rectangle"
              << '\n'
           << "2. Specify upper left corner and dimensions of rectangle"
              << '\n'
           << "3. Specify extent from center of rectangle" << '\n'
           << "Enter int for retangle specification method" << endl;
      cin << menuOneOpt;
      
      if (recMethod == 1)  {
        cout << "Enter upper left corner row and column: ";
        // cin 
        cout << "Enter lower right corner row and column: ";
        // cin
      }
      else if (recMethod == 2)  {
        cout << "Enter upper left corner row and column: ";
        // cin
        cout << "Enter int for number of rows: ";
        // cin
        cout << "Enter int for number of column: ";
        // cin
      }
      else if (recMethod == 3)  {
        cout << "Enter rectangle center row and column: ";
        // cin
        cout << "Enter int for half number of rows: ";
        // cin
        cout << "Enter int for half number of columns: ";
        // cin
      }
      else  {
        // error
      }

      // choose color
      cout << "1. Red" << '\n' 
           << "2. Green" << '\n'
           << "3. Blue" << '\n'
           << "4. Black" << '\n'
           << "5. While" << '\n'
           << "Enter int for ractangle color: "
      cin >> recColor;
      
      // choose fill option
      cout << "1. No" << '\n'
           << "2. Yes" << '\n'
           << "Enter int for rectangle fill option: " << endl;
      cin << recFillOpt;
    }
    
    else if (mainMenuOpt == 2) {
      cout << "Enter string for file name containing pattern: ";
      // cin
      cout << "Enter ipper left corner of pattern row and column: ";
      // cin
      
      // color option duplicated code ??
    }
    else if (mainMenuOpt == 3) {
      cout << "Enter string for file name of PPM image to insert: ";
      // cin
      cout << "Enter upper left corner to insert image row and column";
      // cin

      // transparency color
    }
    else if (mainMenuOpt == 4) {
      cout << "Enter string for PPM file name to output: ";
      // cin
    }
    else if (mainMenuOpt == 5) {
      cout << "Thank you for using this program";
    }
  }
}


