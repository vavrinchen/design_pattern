#include <iostream>

const int buttonNum = 7;

class ICommand {
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
};

class Receiver {
    public:
        void light_on() {
            std::cout << "light on" << std::endl;
        }
        void light_off() {
            std::cout << "light off" << std::endl;
        }
};

class NoReceiverCommand : public ICommand {
    public:
        Receiver *receiver;
        void execute() {
            std::cout << "This is default exeucute command" << std::endl;
        }
        void undo() {
            std::cout << "This is default undo command" << std::endl;
        }
};


class Invoker {
    public:
        ICommand *onCommands[buttonNum];
        ICommand *offCommands[buttonNum];
        Invoker() {
            for(int i = 0; i < buttonNum; i++) {
                onCommands[i]  = new NoReceiverCommand();
			    offCommands[i] = new NoReceiverCommand();
            }
        }
        void setCommand(int slot, ICommand *setOnCommands, ICommand *setOffCommands);
        void onButtonWasPushed(int slot);
	    void offButtonWasPushed(int slot);
};

void Invoker::setCommand(int slot, ICommand *setOnCommands, ICommand *setOffCommands) {
    onCommands[slot] = setOnCommands;
    offCommands[slot] = setOffCommands;
}

void Invoker::onButtonWasPushed(int slot) {
    onCommands[slot]->execute();
}
void Invoker::offButtonWasPushed(int slot) {
    offCommands[slot]->execute();
}

class LightOnCommand : public ICommand {
    public:
        Receiver *receiver;
        void execute() {
            receiver->light_on();
        }
        void undo() {
            receiver->light_off();
        }
};

class LightOffCommand : public ICommand {
    public:
        Receiver *receiver;
        void execute() {
            receiver->light_off();
        }
        void undo() {
            receiver->light_on();
        }
};

int main() {
    Invoker *remoteControl = new Invoker();
    remoteControl->setCommand(0, new LightOnCommand(), new LightOffCommand()); //替按鈕 0 綁定電燈
    remoteControl->onButtonWasPushed(0); //按鈕0被按下
    return 0;
}