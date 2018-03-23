//============================================================================
//  Name        : FactoryMethod.cpp
//	SE311 Lab5 Mirkan Çalışkan
//============================================================================
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// An 'Abstract Product' class --> AccountProduct

class AccountProduct {
public:

    virtual void depositMoney(double depositAmount) =0;
    virtual void displayBalance() = 0;
    virtual void withdrawMoney(double withdrawAmount) = 0;
    virtual string getName(){};

    AccountProduct(string name) : _name(name) {};

protected:
    string _name;
};


// A 'ConcreteProduct' class --> AKBANK_SavingsAccountProduct

class AKBANK_SavingsAccountProduct : public  AccountProduct {
private:
    double accountBalance;
public:
    AKBANK_SavingsAccountProduct(string name) : AccountProduct(name), accountBalance(0.0 ) {
        cout << "AKBANK - Savings Account : Creating account." << endl;
    }
    void depositMoney(double depositAmount) {
        accountBalance += depositAmount;
        cout << "AKBANK - Savings Account : Deposit money " << depositAmount << endl;
    }
    void displayBalance() {
        cout << "AKBANK - Savings Account : Account Balance " << accountBalance << endl;
    }
    void withdrawMoney(double withdrawAmount) {
        accountBalance -= withdrawAmount;
        cout << "AKBANK - Savings Account: Withdraw money " << withdrawAmount << endl;
    }
};

class VAKIFBANK_SavingsAccountProduct : public  AccountProduct{
private:
    double accountBalance;
public:
    VAKIFBANK_SavingsAccountProduct(string name) : AccountProduct(name), accountBalance(0.0) {
        cout << "VAKIFBANK - Savings Account : Creating account." << endl;
    }
    void depositMoney(double depositAmount) {
        accountBalance += depositAmount;
        cout << "VAKIFBANK - Savings Account : Deposit money " << depositAmount << endl;
    }
    void displayBalance() {
        cout << "VAKIFBANK - Savings Account : Account Balance " << accountBalance << endl;
    }
    void withdrawMoney(double withdrawAmount) {
        accountBalance -= withdrawAmount;
        cout << "VAKIFBANK - Savings Account: Withdraw money " << withdrawAmount << endl;
    }
};

// A 'ConcreteProduct' class --> AKBANK_CheckingAccountProduct
class AKBANK_CheckingAccountProduct : public  AccountProduct{
private:
    double accountBalance ;
public:
    AKBANK_CheckingAccountProduct(string name) : AccountProduct(name), accountBalance(0.0) {
        cout << "AKBANK - Checking Account : Creating account." << endl;
    }
    void depositMoney(double depositAmount) {
        accountBalance += depositAmount;
        cout << "AKBANK - Checking Account : Deposit money " << depositAmount << endl;
    }
    void displayBalance() {
        cout << "AKBANK - Checking Account : Account Balance " << accountBalance << endl;
    }
    void withdrawMoney(double withdrawAmount) {
        accountBalance -= withdrawAmount;
        cout << "AKBANK - Checking Account: Withdraw money " << withdrawAmount << endl;
    }
};

class VAKIFBANK_CheckingAccountProduct : public  AccountProduct {
private:
    double accountBalance ;
public:
    VAKIFBANK_CheckingAccountProduct(string name) : AccountProduct(name), accountBalance(0.0) {
        cout << "VAKIFBANK - Checking Account : Creating account." << endl;
    }
    void depositMoney(double depositAmount) {
        accountBalance += depositAmount;
        cout << "VAKIFBANK - Checking Account : Deposit money " << depositAmount << endl;
    }
    void displayBalance() {
        cout << "VAKIFBANK - Checking Account : Account Balance " << accountBalance << endl;
    }
    void withdrawMoney(double withdrawAmount) {
        accountBalance -= withdrawAmount;
        cout << "VAKIFBANK - Checking Account: Withdraw money " << withdrawAmount << endl;
    }
};
// An 'Abstract Creator' class
//      --> BankAccountCreator
class BankAccountCreator {
public:
    // Factory Methods
    virtual AccountProduct* createSavingsBankAccount() = 0;
    virtual AccountProduct* createCheckingBankAccount() = 0;

    // We call the  factory methods thus defer the instantiation to
    // subclasses.

    void createAccount() {
        _savings = createSavingsBankAccount();
        _checking = createCheckingBankAccount();
    }
    // Helper get methods to access to the private data.
    AccountProduct* getSavings() {return _savings;}
    AccountProduct* getChecking() {return _checking;}

    virtual ~BankAccountCreator() {};
private:
    AccountProduct * _savings;
    AccountProduct * _checking;
};

// A 'ConcreteCreator' class ---> AKBANK_AccountConcreteCreator

class  AKBANK_AccountConcreteCreator : public  BankAccountCreator {
// Factory Method implementation
public:
    // We are overriding the facotry method
    AccountProduct* createSavingsBankAccount() {
        return new AKBANK_SavingsAccountProduct(std::__cxx11::string());
    }
    // We are overriding the facotry method
    AccountProduct* createCheckingBankAccount() {
        return new AKBANK_CheckingAccountProduct(std::__cxx11::string());
    }
};

class  VAKIFBANK_AccountConcreteCreator : public  BankAccountCreator {
// Factory Method implementation
public:
    // We are overriding the facotry method
    AccountProduct* createSavingsBankAccount() {
        return new VAKIFBANK_SavingsAccountProduct(std::__cxx11::string());
    }
    // We are overriding the facotry method
    AccountProduct* createCheckingBankAccount() {
        return new VAKIFBANK_CheckingAccountProduct(std::__cxx11::string());
    }
};

class Portfolio : public AccountProduct {
public:
    Portfolio(string name) : AccountProduct( name ) {} ;
    void depositMoney(double depositAmount){};

    void displayBalance(){
        for (int i = 0; i<myPortfolio.size();i++){
            myPortfolio[i]->displayBalance();}
    };

    void withdrawMoney(double withdrawAmount){};

    void Add(AccountProduct* d) {myPortfolio.push_back(d);};

    string getName() {return _name;};
private:
    vector<AccountProduct*> myPortfolio;
    string _name;
};

// Factory Method Design Pattern.
// Entry point into main application.

int main() {

    BankAccountCreator* bankSystemCreator;
    AccountProduct* savings;
    AccountProduct* checking;

    bankSystemCreator = new AKBANK_AccountConcreteCreator();
    bankSystemCreator->createAccount();

    bankSystemCreator = new VAKIFBANK_AccountConcreteCreator();
    bankSystemCreator->createAccount();

    savings = bankSystemCreator->getSavings();
    savings->depositMoney(1000.00);
    savings->displayBalance();
    savings->withdrawMoney(115.00);
    savings->displayBalance();

    checking = bankSystemCreator->getChecking();
    checking->depositMoney(1250.00);
    checking->displayBalance();
    checking->withdrawMoney(50.00);
    checking->displayBalance();
    
//Portfolio
    Portfolio* Mirkan = new Portfolio("VAKIFBANK");
    Mirkan->Add(savings);
    Mirkan->Add(checking);
    cout<<Mirkan->getName()<<endl;
    Mirkan->displayBalance();
}
