// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.0
// Generated from file `Printer.ice'

#ifndef __Printer_h__
#define __Printer_h__

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

namespace Demo
{

class Printer;
bool operator==(const Printer&, const Printer&);
bool operator!=(const Printer&, const Printer&);
bool operator<(const Printer&, const Printer&);
bool operator<=(const Printer&, const Printer&);
bool operator>(const Printer&, const Printer&);
bool operator>=(const Printer&, const Printer&);

}

}

namespace Demo
{

class Printer;
bool operator==(const Printer&, const Printer&);
bool operator!=(const Printer&, const Printer&);
bool operator<(const Printer&, const Printer&);
bool operator<=(const Printer&, const Printer&);
bool operator>(const Printer&, const Printer&);
bool operator>=(const Printer&, const Printer&);

}

namespace IceInternal
{

void incRef(::Demo::Printer*);
void decRef(::Demo::Printer*);

void incRef(::IceProxy::Demo::Printer*);
void decRef(::IceProxy::Demo::Printer*);

}

namespace Demo
{

typedef ::IceInternal::Handle< ::Demo::Printer> PrinterPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Demo::Printer> PrinterPrx;

void __write(::IceInternal::BasicStream*, const PrinterPrx&);
void __read(::IceInternal::BasicStream*, PrinterPrx&);
void __write(::IceInternal::BasicStream*, const PrinterPtr&);
void __patch__PrinterPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const PrinterPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const PrinterPtr&);
void __decRefUnsafe(const PrinterPtr&);
void __clearHandleUnsafe(PrinterPtr&);

}

namespace Demo
{

}

namespace IceProxy
{

namespace Demo
{

class Printer : virtual public ::IceProxy::Ice::Object
{
public:

    void printString(const ::std::string& s)
    {
        printString(s, 0);
    }
    void printString(const ::std::string& s, const ::Ice::Context& __ctx)
    {
        printString(s, &__ctx);
    }
    
private:

    void printString(const ::std::string&, const ::Ice::Context*);
    
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

namespace Demo
{

class Printer : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void printString(const ::std::string&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace Demo
{

class Printer : virtual public ::IceDelegate::Demo::Printer,
                virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void printString(const ::std::string&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace Demo
{

class Printer : virtual public ::IceDelegate::Demo::Printer,
                virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void printString(const ::std::string&, const ::Ice::Context*);
};

}

}

namespace Demo
{

class Printer : virtual public ::Ice::Object
{
public:

    typedef PrinterPrx ProxyType;
    typedef PrinterPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void printString(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___printString(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__PrinterPtr(void*, ::Ice::ObjectPtr&);

}

#endif
