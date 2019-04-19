// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.0
// Generated from file `qncsrinterface.ice'

#ifndef __qncsrinterface_h__
#define __qncsrinterface_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 302
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace csr
{

class ResultCallbackProxy;
bool operator==(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator!=(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator<(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator<=(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator>(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator>=(const ResultCallbackProxy&, const ResultCallbackProxy&);

class StreamInterface;
bool operator==(const StreamInterface&, const StreamInterface&);
bool operator!=(const StreamInterface&, const StreamInterface&);
bool operator<(const StreamInterface&, const StreamInterface&);
bool operator<=(const StreamInterface&, const StreamInterface&);
bool operator>(const StreamInterface&, const StreamInterface&);
bool operator>=(const StreamInterface&, const StreamInterface&);

}

}

namespace csr
{

class ResultCallbackProxy;
bool operator==(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator!=(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator<(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator<=(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator>(const ResultCallbackProxy&, const ResultCallbackProxy&);
bool operator>=(const ResultCallbackProxy&, const ResultCallbackProxy&);

class StreamInterface;
bool operator==(const StreamInterface&, const StreamInterface&);
bool operator!=(const StreamInterface&, const StreamInterface&);
bool operator<(const StreamInterface&, const StreamInterface&);
bool operator<=(const StreamInterface&, const StreamInterface&);
bool operator>(const StreamInterface&, const StreamInterface&);
bool operator>=(const StreamInterface&, const StreamInterface&);

}

namespace IceInternal
{

void incRef(::csr::ResultCallbackProxy*);
void decRef(::csr::ResultCallbackProxy*);

void incRef(::IceProxy::csr::ResultCallbackProxy*);
void decRef(::IceProxy::csr::ResultCallbackProxy*);

void incRef(::csr::StreamInterface*);
void decRef(::csr::StreamInterface*);

void incRef(::IceProxy::csr::StreamInterface*);
void decRef(::IceProxy::csr::StreamInterface*);

}

namespace csr
{

typedef ::IceInternal::Handle< ::csr::ResultCallbackProxy> ResultCallbackProxyPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::csr::ResultCallbackProxy> ResultCallbackProxyPrx;

void __write(::IceInternal::BasicStream*, const ResultCallbackProxyPrx&);
void __read(::IceInternal::BasicStream*, ResultCallbackProxyPrx&);
void __write(::IceInternal::BasicStream*, const ResultCallbackProxyPtr&);
void __patch__ResultCallbackProxyPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const ResultCallbackProxyPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const ResultCallbackProxyPtr&);
void __decRefUnsafe(const ResultCallbackProxyPtr&);
void __clearHandleUnsafe(ResultCallbackProxyPtr&);

typedef ::IceInternal::Handle< ::csr::StreamInterface> StreamInterfacePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::csr::StreamInterface> StreamInterfacePrx;

void __write(::IceInternal::BasicStream*, const StreamInterfacePrx&);
void __read(::IceInternal::BasicStream*, StreamInterfacePrx&);
void __write(::IceInternal::BasicStream*, const StreamInterfacePtr&);
void __patch__StreamInterfacePtr(void*, ::Ice::ObjectPtr&);

void __addObject(const StreamInterfacePtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const StreamInterfacePtr&);
void __decRefUnsafe(const StreamInterfacePtr&);
void __clearHandleUnsafe(StreamInterfacePtr&);

}

namespace csr
{

}

namespace IceProxy
{

namespace csr
{

class ResultCallbackProxy : virtual public ::IceProxy::Ice::Object
{
public:

    void sendStreamResult(const ::std::string& sessionid, const ::std::string& result)
    {
        sendStreamResult(sessionid, result, 0);
    }
    void sendStreamResult(const ::std::string& sessionid, const ::std::string& result, const ::Ice::Context& __ctx)
    {
        sendStreamResult(sessionid, result, &__ctx);
    }
    
private:

    void sendStreamResult(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class StreamInterface : virtual public ::IceProxy::Ice::Object
{
public:

    void initCallbackProxy(const ::csr::ResultCallbackProxyPrx& proxy)
    {
        initCallbackProxy(proxy, 0);
    }
    void initCallbackProxy(const ::csr::ResultCallbackProxyPrx& proxy, const ::Ice::Context& __ctx)
    {
        initCallbackProxy(proxy, &__ctx);
    }
    
private:

    void initCallbackProxy(const ::csr::ResultCallbackProxyPrx&, const ::Ice::Context*);
    
public:

    void sendStreamData(const ::std::string& channelid, const ::std::string& strdata, ::Ice::Int rate)
    {
        sendStreamData(channelid, strdata, rate, 0);
    }
    void sendStreamData(const ::std::string& channelid, const ::std::string& strdata, ::Ice::Int rate, const ::Ice::Context& __ctx)
    {
        sendStreamData(channelid, strdata, rate, &__ctx);
    }
    
private:

    void sendStreamData(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context*);
    
public:

    ::Ice::Int sendPackageData(const ::std::string& channelid, const ::std::string& packagedata)
    {
        return sendPackageData(channelid, packagedata, 0);
    }
    ::Ice::Int sendPackageData(const ::std::string& channelid, const ::std::string& packagedata, const ::Ice::Context& __ctx)
    {
        return sendPackageData(channelid, packagedata, &__ctx);
    }
    
private:

    ::Ice::Int sendPackageData(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

namespace IceDelegate
{

namespace csr
{

class ResultCallbackProxy : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void sendStreamResult(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;
};

class StreamInterface : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void initCallbackProxy(const ::csr::ResultCallbackProxyPrx&, const ::Ice::Context*) = 0;

    virtual void sendStreamData(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Ice::Int sendPackageData(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace csr
{

class ResultCallbackProxy : virtual public ::IceDelegate::csr::ResultCallbackProxy,
                            virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void sendStreamResult(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class StreamInterface : virtual public ::IceDelegate::csr::StreamInterface,
                        virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void initCallbackProxy(const ::csr::ResultCallbackProxyPrx&, const ::Ice::Context*);

    virtual void sendStreamData(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context*);

    virtual ::Ice::Int sendPackageData(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace csr
{

class ResultCallbackProxy : virtual public ::IceDelegate::csr::ResultCallbackProxy,
                            virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void sendStreamResult(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class StreamInterface : virtual public ::IceDelegate::csr::StreamInterface,
                        virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void initCallbackProxy(const ::csr::ResultCallbackProxyPrx&, const ::Ice::Context*);

    virtual void sendStreamData(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context*);

    virtual ::Ice::Int sendPackageData(const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

}

}

namespace csr
{

class ResultCallbackProxy : virtual public ::Ice::Object
{
public:

    typedef ResultCallbackProxyPrx ProxyType;
    typedef ResultCallbackProxyPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void sendStreamResult(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___sendStreamResult(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__ResultCallbackProxyPtr(void*, ::Ice::ObjectPtr&);

class StreamInterface : virtual public ::Ice::Object
{
public:

    typedef StreamInterfacePrx ProxyType;
    typedef StreamInterfacePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void initCallbackProxy(const ::csr::ResultCallbackProxyPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___initCallbackProxy(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void sendStreamData(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___sendStreamData(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int sendPackageData(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___sendPackageData(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__StreamInterfacePtr(void*, ::Ice::ObjectPtr&);

}

#endif
