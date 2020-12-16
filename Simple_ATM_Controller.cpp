#include<iostream>

using namespace std;


void account(int option);


bool proceed(string action) {
	if(action =="y"){
		return true;
	} else if(action == "n"){
		string Exit;
		cout << "\n Thank you for Banking with us.";
		cin >> Exit;
		return false;
	}

}




class Bank{

    private:

    	int type;		// account type
		int balance;	// account balance
		string action;

		static int BankAccount[3];


    public:

        Bank(){ }

		string AccountType[3]{"", "Checkings", "Savings"};

        bool verify(int pin){
            if (BankAccount[0] == pin)
                return true;
            else 
                return false;
        }


    	Bank(int type) {
			// type 1 = Checkings
			// type 2 = Savings
			this->type = type;
			
			this->balance = BankAccount[this->type];
		}

		int Withdraw(int withdrawAmount) {
			
			// Withdraw operation: check Insufficient funds:
			if(withdrawAmount <= this->balance){
				int AccountBalance = this->balance -= withdrawAmount;
				cout << "\nYour amount is dispensing... ";
				cout << "$"<< withdrawAmount << endl;
				
				// update the account balance
				BankAccount[this->type] = AccountBalance;
				Balance();

			} else {
				cout << "\nInsufficent account funds" << endl;
				Balance();
			}

			return 0;
		}

		int Deposit(int depositAmount) {

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
			if(checkBalance=="y"){
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

int Bank::BankAccount[3]{
	2354,		// PIN number
	200,		// checking account balance
	500,		// savings account balance
};


class ATM{

    private: 

        int option;
        string action;

    public:

		static int ATM_money;

		ATM(){}

		void Main_Menu(){

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

				    	Main_Menu();
			        } 
			        break;
	        }
        }

        
};

int ATM::ATM_money = 1000;

void account(int option) {

		/*Note:
			account option = 1 (checkings)
			account option = 2 (savings)
		*/	
			Bank b;
			ATM a;
			string action;
			cout << "\n\n" <<"##"<<b.AccountType[option] << ":"<<"\n\tPlese enter the option number:"<<"\n\t1. Check balance"
				<<"\n\t2. Withdraw from " << b.AccountType[option] 
				<<"\n\t3. Deposit to " << b.AccountType[option] 
				<<"\n\t4. Return to Main Menu." << endl;

		// Pass in Bank account type
		    Bank Account(option); 

		    int selectMenu;
			int withdraw;
			int deposit;
		    cin >> selectMenu;
		
		    switch(selectMenu){
			    case 1:
				    cout << Account.Balance();
				    break;
			    case 2: 
					cout<<"\nPlease enter the amount to withdraw:\n";
					cin>>withdraw;
					if (withdraw<= a.ATM_money){
						a.ATM_money-=withdraw; 

				    	cout << Account.Withdraw(withdraw);
					}
					else{
						cout<<"ATM has only:"<<"$"<<a.ATM_money<<"\nInsufficient ATM funds!\n"<<"Please start again!\n";

					}
				    break;

			    case 3:
					cout<<"\nPlease enter an amount to deposit:\n";
					cin>>deposit; 
					a.ATM_money+= deposit;
				    cout << Account.Deposit(deposit);
				    break;
			    case 4:
					a.Main_Menu(); // return to main menu
				    break;
			    default:
				    cout << "Would you like to continue (y/n)?\n";
				    cin >> action;
				    proceed(action);
			
				    if (proceed(action)) {

						a.Main_Menu(); // return to main menu
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

    	Bank b;   //bank class object

    	int pin;
    	do{
        	    cin>>pin;     

            	if(b.verify(pin)){
                	ATM a;
					a.Main_Menu();
            	}
            	else{
                	cout<<"Your PIN is invalid, please try again:"<<"\n"<<endl;
                	cout<<"Please enter your account PIN number:";
            	}
    	}while(!b.verify(pin));
	}
    
    return 0;
}


