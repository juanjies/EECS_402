
#include <iostream>
using namespace std;
// Programmer: Juan-Jie Sun
// Date: September 2020
// Purpose: EECS402 Project 1: accrue interest for an investment account

/* 
  Func accrueInterest shows the initial balance, total interest accrued,
  and the final balance.     
*/
bool accrueInterest(
     double &balanceAmt,
     const int numMonths,
     const bool doPrintEachMonth
     );
/* 
  Func accrueOneMonthsInterest shows the initial balance, interest rate,
  interest accrued and the new balance of one month. 
*/
bool accrueOneMonthsInterest(
     double &balanceAmt,
     const bool doPrintInfo
     );

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  double balanceAmt = 0;
  int numMonths = 0;
  bool doPrintEachMonth;
  char monthlyResultOpt;

  cout << "Enter the initial balance of the account: ";
  cin >> balanceAmt;
  cout << "Enter the number of months to accrue interest: ";
  cin >> numMonths;
  cout << "Show month-by-month results - 'y' for yes, any other for no: ";
  cin >> monthlyResultOpt;

  if (monthlyResultOpt == 'y')
  {
    doPrintEachMonth = true;
  }
  else 
  {
    doPrintEachMonth = false;
  }
  accrueInterest(balanceAmt, numMonths, doPrintEachMonth);
  return 0;
}
#endif

bool accrueInterest(
     double &balanceAmt,
     const int numMonths,
     const bool doPrintEachMonth
     )
{ 
  double initBalanceAmt = 0;
  if (numMonths < 0)
  {
    cout << "ERROR in acruInterest: numMonths must be > 0, "
         << "but the value " << numMonths << " was provided!" << endl;
    cout << "Sorry, an error was detected. Unable to provide results!"
         << endl;
    return false;
  }
  else if (balanceAmt < 0)
  {
    cout << "Error in accrueOneMonthsInterest: " 
      << "balanceAmt must be >= 0, "
      << "but the value " << balanceAmt
      << " was provided!" << endl;

    return false;
  }
  
  initBalanceAmt = balanceAmt;

  for (int i = 0; i < numMonths; i++)
  {
    accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
  }
  cout << "Interest accrued for " << numMonths << " months!" << endl;
  cout << "\n";
  cout << "Initial balance: " << initBalanceAmt << endl;
  cout << "Total interest accrued: " << (balanceAmt - initBalanceAmt) << endl;
  cout << "Final balance: " << balanceAmt << endl;
    
  return true;
}

bool accrueOneMonthsInterest(
     double &balanceAmt,
     const bool doPrintInfo 
     )
{
  double highBar = 15000.00, lowBar = 1000.00;
  double minInterestRate = 0.0015, stdInterestRate = 0.00225,
           maxInterestRate = 0.004;
  double monthlyInterestRate;
  double prevBalanceAmt, monthlyAccruedInt;

  if (balanceAmt >= highBar) 
  {
    monthlyInterestRate = maxInterestRate;
  }
  else if (balanceAmt >= lowBar)
  {
    monthlyInterestRate = stdInterestRate;
  }
  else if (balanceAmt >= 0 && balanceAmt < lowBar)
  {
    monthlyInterestRate = minInterestRate;
  }
  
  prevBalanceAmt = balanceAmt;
  monthlyAccruedInt = balanceAmt * monthlyInterestRate;
  balanceAmt += balanceAmt * monthlyInterestRate;

  if (doPrintInfo)
  {
    cout << "Accruing interest for 1 month:" << endl;
    cout << "  Initial balance: " << prevBalanceAmt << endl;
    cout << "  Initial rate: " << monthlyInterestRate << endl;
    cout << "  Interest accrued:  " << monthlyAccruedInt << endl;
    cout << "  New balance:  " << balanceAmt << endl;
  }
  return true;
}