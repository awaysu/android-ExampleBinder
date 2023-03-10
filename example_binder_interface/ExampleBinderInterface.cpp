/**
 * Demonstrate how to us Binder in Native C++ codes.
 *
 * The interface describes the RPC calls.
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#include "ExampleBinderInterface.h"

const String16 ExampleBinderInterface::DESCRIPTOR("ExampleBinderInterface");

ExampleBinderInterface::ExampleBinderInterface() {
    ALOGE("ExampleBinderInterface::ExampleBinderInterface()");
}

ExampleBinderInterface::~ExampleBinderInterface() {
    ALOGE("ExampleBinderInterface::~ExampleBinderInterface()");
}
