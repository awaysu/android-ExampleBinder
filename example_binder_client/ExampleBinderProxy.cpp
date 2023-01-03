#include "ExampleBinderProxy.h"

#define LOG_TAG "ExampleBinderProxy"

ExampleBinderProxy::ExampleBinderProxy(const sp<IBinder>& impl) {
    ALOGE("ExampleBinderProxy::ExampleBinderProxy()");
    remote = impl;
}

void ExampleBinderProxy::print(const char *msg) {
    Parcel data, reply;
    data.writeInterfaceToken(ExampleBinderInterface::DESCRIPTOR);
    data.writeString16(String16(msg));

    aout << "ExampleBinderProxy::print parcel to be sent:n";
    data.print(aout);
    endl(aout);
    remote->transact(ExampleBinderInterface::PRINT, data, &reply, IBinder::FLAG_ONEWAY);
    ALOGE("ExampleBinderProxy::print() is returned");
}

int32_t ExampleBinderProxy::add(int32_t a, int32_t b) {
    Parcel data, reply;
    data.writeInterfaceToken(ExampleBinderInterface::DESCRIPTOR);
    data.writeInt32(a);
    data.writeInt32(b);

    aout << "ExampleBinderProxy::add parcel to be sent:n";
    data.print(aout);
    endl(aout);

    remote->transact(ExampleBinderInterface::ADD, data, &reply);
    ALOGE("ExampleBinderProxy::add transact reply");
    reply.print(aout);
    endl(aout);
    int32_t res;
    status_t status = reply.readInt32(&res);
    ALOGE("ExampleBinderProxy::add(%i, %i) = %i(status: %i)",
            a, b, res, status);
    return res;
}



