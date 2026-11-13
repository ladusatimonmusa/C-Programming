////Develop a c++ program that simulates a simple bank account. the program should store an account holder's name, 
////and account balance. the program should allow users to deposit money,withdraw money and check their balances and retrieve account information.
////ensure that withdraws can not exceed avialable balance
//
//
//
//#include <iostream>
//using namespace std;
//class Bank {
//	private:
//		string name;
//		double balance;
//		double deposit;
//		double withdraw;
//		
//		
//	public:
//	//setter function for name
//	void setNamesr(string newName){
//		name = newName;
//	}
//	
//	//getter function for name
//	string getName(){
//		return name;
//	}	
//	
//	//setter function for balance
//	void setBalance(double newBalance){
//		balance = newBalance;
//	}
//	
//	//getter function for balance
//	double getBalance(){
//		return balance;
//	}
//	
//	//setter function for deposit
//	void setDeposit(double newDeposit){
//		deposit = newDeposit;
//	}
//	
//	//getter function for deposit
//	double getDeposit(){
////		balance = deposit + balance;
//		return deposit;
//	}
//	
//	//setter function for withdraw
//	void setWithdraw(double newWithDraw){
//		withdraw = newWithDraw;
//	}
//	
//	//getter for account info
//	void retrieveInfo(){
//		cout << "Name: " << name << endl;
//		cout << "Balance: " << balance << endl;
//	}
//};
//
//
//
//
//
//int main(){
//	
//	
//	Bank person1;
//	string name, choice;
//	double balance;
//	cout << "Enter your name: " << endl;
//	cin >> name;
//	cout << "Enter your balance: " << endl;
//	cin >> balance;
//	
//	cout << " 1.check balance" << endl;
//	cout << "2.Withdraw" << endl;
//	cout << "2.Deposit" << endl;
//	cout << "4.Get Account information" << endl;
//	cout << "Choose your option: " << endl;
//	cin >> choice;
//	
//	double withdraw,actualBalance,remainBalance,deposit;
//	actualBalance = person1.getBalance();
//	
//	
//	
//	switch(choice){
//		case "1":
//			cout << "Your balance is : " << person1.getBalance() << endl;
//			break;
//		case "2":
//		cout << "How much do you want to withdraw: " << endl;
//		cin << withdraw;
//		if (actualBalance <= balance){
//			cout << "Insufficient balance" << endl;
//		}	
//		else {
//			cout << "You have withdrawed: " << withdraw << endl;
//			remainBalance = person1.getBalance() - withdraw;
//			person1.setBalance(remainBalance);
//		}
//		break;
//		
//		case "3" :
//			cout << "How much do you want to deposit: "<< endl;
//			cin >> deposit;
//			cout << "You have deposited: " << deposit << endl;
//			person1.setBalance(deposit);
//		break;
//		
//		case "4": 
//		  cout << person1.retrieveInfo() << endl;
//		  break;
//		  
//		  default: cout << "Invalid option";
//			
//	}
//	
//	
//	
//	
//	
//	
//	return 0;
//}






#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string name;
    double balance;

public:

    // Constructor
    Bank(string accountName, double initialBalance) {
        name = accountName;
        balance = initialBalance;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Deposit function
    void depositMoney(double amount) {

        if (amount > 0) {
            balance = balance + amount;

            cout << "Successfully deposited: "
                 << amount << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw function;
    void withdrawMoney(double amount) {

        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        }

        else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        }

        else {
            balance = balance - amount;

            cout << "Successfully withdrawn: "
                 << amount << endl;
        }
    }

    // Check balance
    void checkBalance() {
        cout << "Your account balance is: "
             << balance << endl;
    }

    // Retrieve account information
    void retrieveInfo() {
        cout << "\n----- ACCOUNT INFORMATION -----" << endl;
        cout << "Account holder: " << name << endl;
        cout << "Account balance: " << balance << endl;
        cout << "--------------------------------" << endl;
    }
};


int main() {

    string name;
    double initialBalance;
    int choice;

    cout << "Enter account holder's name: ";
    getline(cin, name);

    cout << "Enter initial account balance: ";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative!" << endl;
        return 1;
    }

    // Creating an object
    Bank person1(name, initialBalance);

    do {

        cout << "\n===== SIMPLE BANKING SYSTEM =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Get Account Information" << endl;
        cout << "5. Exit" << endl;

        cout << "Choose your option: ";
        cin >> choice;

        double amount;

        switch (choice) {

            case 1:
                person1.checkBalance();
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                person1.withdrawMoney(amount);
                break;

            case 3:
                cout << "Enter deposit amount: ";
                cin >> amount;

                person1.depositMoney(amount);
                break;

            case 4:
                person1.retrieveInfo();
                break;

            case 5:
                cout << "Thank you for banking with us!" << endl;
                break;

            default:
                cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}



traffic

#include <iostream>
#include <string>

using namespace std;

class TrafficLight {
private:
    string intersectionName;
    string currentSignal; 
    int durationSeconds;
    bool isActive;

public:
    // Constructor using normal assignment inside curly braces
    TrafficLight(string intersection) {
        intersectionName = intersection;
        currentSignal = "RED";
        durationSeconds = 30;
        isActive = false;
    }

    void startSystem() {
        isActive = true;
        cout << "[System]: " << intersectionName << " traffic light is now ACTIVE.\n";
    }

    void shutdownSystem() {
        isActive = false;
        currentSignal = "RED"; 
        cout << "[System]: " << intersectionName << " traffic light is now INACTIVE.\n";
    }

    void changeSignal(string nextSignal, int duration) {
        if (!isActive) {
            cout << "Error: Cannot change signal. " << intersectionName << " system is offline.\n";
            return;
        }
        
        if (nextSignal == "RED" || nextSignal == "YELLOW" || nextSignal == "GREEN") {
            currentSignal = nextSignal;
            durationSeconds = duration;
            cout << "[" << intersectionName << "]: Signal changed to " << currentSignal 
                  << " for " << durationSeconds << " seconds.\n";
        } else {
            cout << "Error: Invalid signal color '" << nextSignal << "'. Use RED, YELLOW, or GREEN.\n";
        }
    }

    void displayIntersectionReport() const {
        cout << "\nIntersection Report: " << intersectionName << "\n";
        cout << "Operational Status: " << (isActive ? "RUNNING" : "OFFLINE") << "\n";
        cout << "Active Signal     : " << currentSignal << "\n";
        cout << "Remaining Interval: " << durationSeconds << "s\n";
        cout << "--------------------------------------\n";
    }
};

int main() {
    TrafficLight mainAnd1st("Main St & 1st Ave");
    TrafficLight oakAndBroadway("Oak St & Broadway");

    mainAnd1st.startSystem();
    oakAndBroadway.startSystem();

    mainAnd1st.changeSignal("GREEN", 45);
    oakAndBroadway.changeSignal("YELLOW", 5);

    mainAnd1st.displayIntersectionReport();
    oakAndBroadway.displayIntersectionReport();

    return 0;
}



//AC
#include <iostream>
#include <string>

using namespace std;

class SmartAC {
private:
    string location;
    bool isOn;
    int temperature;       
    string mode;      
    string fanSpeed;  

public:
    // Constructor using normal assignment inside curly braces
    SmartAC(string loc) {
        location = loc;
        isOn = false;
        temperature = 24;
        mode = "Cool";
        fanSpeed = "Auto";
    }

    void turnOn() { 
        isOn = true; 
        cout << "[" << location << " AC]: Powered ON.\n";
    }
    
    void turnOff() { 
        isOn = false; 
        cout << "[" << location << " AC]: Powered OFF.\n";
    }

    void setTemperature(int temp) {
        if (!isOn) {
            cout << "Error: Cannot change temperature. " << location << " AC is OFF.\n";
            return;
        }
        if (temp < 16 || temp > 30) {
            cout << "Error: Target temperature must be between 16°C and 30°C.\n";
            return;
        }
        temperature = temp;
        cout << "[" << location << " AC]: Temperature set to " << temperature << "°C.\n";
    }

    void setMode(string newMode) {
        if (!isOn) return;
        
        if (newMode == "Cool" || newMode == "Heat" || newMode == "Fan" || newMode == "Dry") {
            mode = newMode;
            cout << "[" << location << " AC]: Mode changed to " << mode << ".\n";
        } else {
            cout << "Error: Invalid mode '" << newMode << "'. Choose Cool, Heat, Fan, or Dry.\n";
        }
    }

    void setFanSpeed(string newSpeed) {
        if (!isOn) return;
        
        if (newSpeed == "Low" || newSpeed == "Medium" || newSpeed == "High" || newSpeed == "Auto") {
            fanSpeed = newSpeed;
            cout << "[" << location << " AC]: Fan speed changed to " << fanSpeed << ".\n";
        } else {
            cout << "Error: Invalid fan speed '" << newSpeed << "'. Choose Low, Medium, High, or Auto.\n";
        }
    }

    void displayStatus() const {
        cout << "\n--- AC Unit Status: " << location << " ---\n";
        cout << "Power Status: " << (isOn ? "ON" : "OFF") << "\n";
        if (isOn) {
            cout << "Current Temp: " << temperature << "°C\n";
            cout << "Mode:         " << mode << "\n";
            cout << "Fan Speed:    " << fanSpeed << "\n";
        }
        cout << "-----------------------------------\n";
    }
};

int main() {
    SmartAC livingRoomAC("Living Room");
    SmartAC bedroomAC("Master Bedroom");

    livingRoomAC.turnOn();
    livingRoomAC.setTemperature(22);
    livingRoomAC.setMode("Cool");
    livingRoomAC.setFanSpeed("High");

    bedroomAC.turnOn();
    bedroomAC.setTemperature(25);
    bedroomAC.setMode("Dry");

    livingRoomAC.displayStatus();
    bedroomAC.displayStatus();

    return 0;
}

