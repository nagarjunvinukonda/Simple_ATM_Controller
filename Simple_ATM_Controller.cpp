#include<iostream>

using namespace std;

void account(int option);


bool proceed(string action) {
	if(action =="y" || action == "Y"){
		return true;
	} else if(action == "n" || action == "N"){
		string exit;
		cout << "\n Thank you for Banking with us.";
		cin >> exit;
		return false;
	}

}



class bank{

    private:

    	int type;		// account type
		int balance;	// account balance
		string action;

		int BankAccount[3]{
			2354,		// PIN number
			10000,		// checking account balance
			500000,		// savings account balance
		};


    public:

        bank(){ }

		string AccountType[3]{"", "Checkings", "Savings"};

        bool verify(int pin){
            if (BankAccount[0] == pin)
                return true;
            else 
                return false;
        }


    	bank(int type) {
			// type 1 = Checkings
			// type 2 = Savings
			this->type = type;
			
			this->balance = BankAccount[this->type];
		}
		
		int Withdraw() {
			int withdrawAmount;

			cout << "\nPlease enter the amount to withdraw:\n " << endl;
			cin>>withdrawAmount;
			
			// Withdraw operation: check Insufficient funds:
			if(withdrawAmount <= this->balance){
				int AccountBalance = this->balance -= withdrawAmount;
				cout << "\nYour amount is dispensing... ";
				cout << "$"<< withdrawAmount << endl;
				
				// update the account balance
				BankAccount[this->type] = AccountBalance;
				Balance();

			} else {
				cout << "\nInsufficent funds" << endl;
				Balance();
			}

			return 0;
		}

		int Deposit() {
			int depositAmount;
			cout << "\nPlease enter an amount to deposit:\n" << endl;
			cin >> depositAmount;

			int AccountBalance = this->balance += depositAmount;

			// update the account balance
			BankAccount[this->type] = AccountBalance;

			cout << "\n$" << depositAmount << " was deposited into your account.\n";
			Balance();
			 
			return 0;
		}


		int Balance() { // return balance for the AccountType
			string checkBalance;
			
			cout << "\nWould you like to check your "<< AccountType[this->type] << " account balance? (y/n)\n" << endl;
			cin >> checkBalance;
			if(checkBalance=="y" || checkBalance=="Y"){
				cout << "Your account balance is: $" << this->balance << endl;
			} 
			
			cout << "\nWould you like to continue (y/n)?\n";
			cin >> action;

			if (proceed(action)) {

				account(this->type); // return to account menu
			}

			return 0;
		}


};


class atm{

    private: 

        int option;
        string action;

    public:

        atm(){

                    cout << "\n#Main Menu:" <<endl;
	                cout << "\tPlese enter the option number: " << endl;
	                cout << "\t1. Checkings \n\t2. Savings \n\t3. Exit" << endl;
                
                    cin>> option;
                    account_selection(option);

        }

        void account_selection(int option){

            switch(option){

		        case 1: 
  
                    account(option); // checkings
			        break;

		        case 2: 

                    account(option); // savings
			        break;

		        default:

			        cout << "Would you like to continue (y/n)?\n";
			        cin >> action;
			        proceed(action);
			
			        if (proceed(action)) {
				    // menu();
			        } 
			        break;
	        }
        }

        
};

void account(int option) {

		/*Note:
			account option = 1 (checkings)
			account option = 2 (savings)
		*/	
			bank b;
			string action;
			cout << "\n\n" <<"##"<<b.AccountType[option] << ":"<<"\n\tPlese enter the option number:"<<"\n\t1. Check balance"
				<<"\n\t2. Withdraw from " << b.AccountType[option] 
				<<"\n\t3. Deposit to " << b.AccountType[option] 
				<<"\n\t4. Return to Main Menu." << endl;

		// Pass in Bank account type
		    bank Account(option); 

		    int selectMenu;
		    cin >> selectMenu;
		
		    switch(selectMenu){
			    case 1:
				    cout << Account.Balance();
				    break;
			    case 2: 
				    cout << Account.Withdraw();
				    break;
			    case 3: 
				    cout << Account.Deposit();
				    break;
			    case 4:
				    atm(); // return to main menu
				    break;
			    default:
				    cout << "Would you like to continue (y/n)?\n";
				    cin >> action;
				    proceed(action);
			
				    if (proceed(action)) {
					    atm(); // return to main menu
				    } 
				    break;
		    }
}


int main(){

    cout<<"Welcome to ATM!"<<endl;

	cout<<"Insert card: (y/n)"<<endl;

	string action;

	cin>>action;

	if (proceed(action)) {
					    
		cout<<"Please enter your pin number to access your account:";

    	bank b;   //bank class object

    	int pin;
    	do{
        	    cin>>pin;     

            	if(b.verify(pin)){
                	atm a;
            	}
            	else{
                	cout<<"Your PIN is invalid, please try again:"<<"\n"<<endl;
                	cout<<"Please enter your account PIN number:";
            	}
    	}while(!b.verify(pin));
	}
    
    return 0;
}


