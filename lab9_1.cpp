#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

double interest(double Balance,double rpy){
	return Balance*rpy/100;
}

int main(){	
	double loan,payout,newloan,total,rate;
	int endyear=1;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rate;
	cout << "Enter amount you can pay per year: ";
	cin >> payout;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	
	while (1){
	    total = loan + interest(loan,rate);
	
	if(payout>=total)
	{
	    payout=total;
	}
	
	newloan=total-payout;
	
	cout << fixed << setprecision(2); 
	cout << setw(13) << left << endyear; 
	cout << setw(13) << left << loan;
	cout << setw(13) << left << interest(loan,rate);
	cout << setw(13) << left << total;
	cout << setw(13) << left << payout;
	cout << setw(13) << left << newloan;
	cout << "\n";	
	
	if(newloan==0){
	    break;
	}
	loan=newloan;
	endyear++;
	}
	return 0;
}
