#include "ExampleBinderBody.h"

#define LOG_TAG "ExampleBinderServer"

int main(int argc, char **argv) 
{

    ALOGE("We're the service");
    
    defaultServiceManager()->addService(String16("ExampleBinderServer"),
            new ExampleBinderBody());
    ProcessState::self()->startThreadPool();
    ALOGE("ExampleBinder server is running now");
    IPCThreadState::self()->joinThreadPool();
    ALOGE("ExampleBinder server thread joined");

    return 0;
}


