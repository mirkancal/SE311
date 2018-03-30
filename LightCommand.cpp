/* @author: mirkancal */

#include <iostream>
#include <vector>
using namespace std;

class Light {
public:
    void on(){
        cout<<"Light's on!"<<endl;
    }
    void off(){
        cout<<"Light's off!"<<endl;
    }

    Light(){};
};

class Command {
public:
    virtual void Execute() = 0;
protected:
    Command(){};
};

class LightOnCommand : public Command {
    Light *light;
public:

    LightOnCommand(Light *l) {
        this->light = l;
    };

    void Execute() {
        this->light->on();
    }
};

class LightOffCommand : public Command {
        Light* light;
    public:

        LightOffCommand(Light* l){
            this->light = l;
        };

        void Execute(){
            this->light->off();
        }
 };

    class Invoker {
        Command* on;
        Command* off;
    public:
        Invoker(Command* on, Command* off){
            this->on=on;
            this->off=off;
        };

        void clickOn(){
            this->on->Execute();
        }
        void clickOff(){
            this->off->Execute();
        }
    };

    int main() {
        Light *philips = new Light();
        Command *command1 = nullptr;
        Command *command2 = nullptr;
        command1 = new LightOnCommand(philips);
        command2 = new LightOffCommand(philips);
        Invoker *invoker = new Invoker(command1, command2);
        invoker->clickOn();
        invoker->clickOff();

    }