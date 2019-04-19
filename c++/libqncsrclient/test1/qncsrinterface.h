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

}

namespace IceInternal
{

void incRef(::csr::ResultCallbackProxy*);
void decRef(::csr::ResultCallbackProxy*);

void incRef(::IceProxy::csr::ResultCallbackProxy*);
void decRef(::IceProxy::csr::ResultCallbackProxy*);

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

}

#endif
