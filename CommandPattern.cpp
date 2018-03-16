#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
//
// The classes and/or objects participating in this pattern are:
//
// 1. Command  (Command)
//		- declares an interface for executing an operation.
// 2. ConcreteCommand  (CalculatorCommand)
//		- defines a binding between a Receiver object and an action.
//		- implements Execute by invoking the corresponding operation(s) on Receiver
// 3. Client  (Calculator Application)
//		- creates a ConcreteCommand object and sets its receiver.
// 4. Invoker  (User)
//		- asks the command to carry out the request
// 5. Receiver  (Calculator)
//		- knows how to perform the operations associated with carrying out
//		  a request. Any class may serve as a Receiver.
//
//
// "Command"
//
class EventHandler {
public:
	virtual void Execute() = 0;
protected:
	EventHandler(){};
};
//r
// "Receiver"
//
class MouseDriver {
public:
	MouseDriver() {};
	void Action(int x, int y) {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

class KeyboardDriver {
public:
    KeyboardDriver() {};

    void Action(char x) {

        switch (x) {
            case 'a' :
                cout << "a" << endl;
                break;
            case 's' :
                cout << "s" << endl;
                break;
            case 'd' :
                cout << "d" << endl;
                break;
            case 'f' :
                cout << "f" << endl;
                break;
            case 'g' :
                cout << "g" << endl;
                break;
            case 'h' :
                cout << "h" << endl;
                break;
            case 'j' :
                cout << "j" << endl;
                break;
            case 'k' :
                cout << "k" << endl;
                break;
            case 'l' :
                cout << "l" << endl;
                break;
            case 'q' :
                cout << "q" << endl;
                break;
            case 'w' :
                cout << "w" << endl;
                break;
            case 'e' :
                cout << "e" << endl;
                break;
            case 'r' :
                cout << "r" << endl;
                break;
            case 't' :
                cout << "t" << endl;
                break;
            case 'y' :
                cout << "y" << endl;
                break;
            case 'u' :
                cout << "u" << endl;
                break;
            default:
                cout << "UNDEFINED INPUT" << endl;
                break;
        }
    }
};

//
// "ConcreteCommand"
//
class MouseEventHandler : public EventHandler {
public:
	// Constructor
    MouseEventHandler(MouseDriver *mouseDriver, int x, int y)
    : _mouseDriver(mouseDriver), _x(x), _y(y) {}
	void Execute()   {
        _mouseDriver->Action(_x, _y);
	}

private:
    MouseDriver* _mouseDriver;
	int _x;
	int _y;
};

class KeyboardEventHandler : public EventHandler {
public:
    // Constructor
    KeyboardEventHandler(KeyboardDriver *keyboardDriver, char x)
            : _keyboardDriver(keyboardDriver), _x(x){}
    void Execute()   {
        _keyboardDriver->Action(_x);
    }

private:
    KeyboardDriver* _keyboardDriver;
    char _x;
};

// "Invoker"
class User {
public:
	User() {};
    void Compute(EventHandler *eventHandler){
            eventHandler->Execute();
    }
private:
    MouseDriver *_mouseDriver;
    KeyboardDriver *_keyboardDriver;
    vector<EventHandler *> *_eventHandlers;
};

int main() {
    // Create user and let her compute
    EventHandler *eventHandler = nullptr;
    auto *user = new User();
    auto *mouseDriver = new MouseDriver();
    auto *keyboardDriver = new KeyboardDriver();

    eventHandler = new MouseEventHandler(mouseDriver, 20, 50);
    user->Compute(eventHandler);
    eventHandler = new MouseEventHandler(mouseDriver, 50, 200);
    user->Compute(eventHandler);
    eventHandler = new MouseEventHandler(mouseDriver, 20, 300);
    user->Compute(eventHandler);

    eventHandler = new KeyboardEventHandler(keyboardDriver, 'a');
    user->Compute(eventHandler);

    /*
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    */

}

