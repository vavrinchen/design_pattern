//Thread Pool
#include <iostream>
const int thread_num = 2;
class ICommand {
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
};
class ProgramX { //就像 Command Pattern 的 Receiver, Invoker 目的是觸發 Receiver 的 action, 但不在 Invoker 中寫死綁定哪個 Receiver 
    public:
        void programX_Run(){}
        void programX_Undo(){}
};
class Thread_X_Command : public ICommand{ //就像 Command Pattern 的 Concrete Command
    public:
        ProgramX *programX;
        void execute() {
            std::cout << "Thread_X_Command execute" << std::endl;
        }
        void undo() { 
            std::cout << "Thread_X_Command undo" << std::endl;
        }
};
class ThreadPool { //就像 Commad Pattern 的 Invoker
    public:
        ICommand *iCommands[thread_num];
        ThreadPool() {
            for(int i = 0; i < thread_num; i++) {
                iCommands[i] = new Thread_X_Command(); //假設每個 thread pool 初始化都會先做 thread x
            }
        }
        void onThreadStart(int threadId){
            iCommands[threadId]->execute();
        }
        void onThreadUndo(int threadId){
            iCommands[threadId]->undo();
        }        
};

// int main(){
//     ThreadPool *threadPool = new ThreadPool();
//     threadPool->onThreadStart(0);
//     return 0;
// }