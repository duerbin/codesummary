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

#include <qncsrinterface.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

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

static const ::std::string __csr__ResultCallbackProxy__sendStreamResult_name = "sendStreamResult";

static const ::std::string __csr__StreamInterface__initCallbackProxy_name = "initCallbackProxy";

static const ::std::string __csr__StreamInterface__sendStreamData_name = "sendStreamData";

static const ::std::string __csr__StreamInterface__sendPackageData_name = "sendPackageData";

void
IceInternal::incRef(::csr::ResultCallbackProxy* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::csr::ResultCallbackProxy* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::csr::ResultCallbackProxy* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::csr::ResultCallbackProxy* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::csr::StreamInterface* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::csr::StreamInterface* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::csr::StreamInterface* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::csr::StreamInterface* p)
{
    p->__decRef();
}

void
csr::__write(::IceInternal::BasicStream* __os, const ::csr::ResultCallbackProxyPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
csr::__read(::IceInternal::BasicStream* __is, ::csr::ResultCallbackProxyPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::csr::ResultCallbackProxy;
        v->__copyFrom(proxy);
    }
}

void
csr::__write(::IceInternal::BasicStream* __os, const ::csr::ResultCallbackProxyPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
csr::__write(::IceInternal::BasicStream* __os, const ::csr::StreamInterfacePrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
csr::__read(::IceInternal::BasicStream* __is, ::csr::StreamInterfacePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::csr::StreamInterface;
        v->__copyFrom(proxy);
    }
}

void
csr::__write(::IceInternal::BasicStream* __os, const ::csr::StreamInterfacePtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
csr::__addObject(const ResultCallbackProxyPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
csr::__usesClasses(const ResultCallbackProxyPtr& p)
{
    return p->__usesClasses();
}

void
csr::__decRefUnsafe(const ResultCallbackProxyPtr& p)
{
    p->__decRefUnsafe();
}

void
csr::__clearHandleUnsafe(ResultCallbackProxyPtr& p)
{
    p.__clearHandleUnsafe();
}

void
csr::__addObject(const StreamInterfacePtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
csr::__usesClasses(const StreamInterfacePtr& p)
{
    return p->__usesClasses();
}

void
csr::__decRefUnsafe(const StreamInterfacePtr& p)
{
    p->__decRefUnsafe();
}

void
csr::__clearHandleUnsafe(StreamInterfacePtr& p)
{
    p.__clearHandleUnsafe();
}

void
IceProxy::csr::ResultCallbackProxy::sendStreamResult(const ::std::string& sessionid, const ::std::string& result, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::csr::ResultCallbackProxy* __del = dynamic_cast< ::IceDelegate::csr::ResultCallbackProxy*>(__delBase.get());
            __del->sendStreamResult(sessionid, result, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::csr::ResultCallbackProxy::ice_staticId()
{
    return ::csr::ResultCallbackProxy::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::csr::ResultCallbackProxy::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::csr::ResultCallbackProxy);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::csr::ResultCallbackProxy::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::csr::ResultCallbackProxy);
}

bool
IceProxy::csr::operator==(const ::IceProxy::csr::ResultCallbackProxy& l, const ::IceProxy::csr::ResultCallbackProxy& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::csr::operator!=(const ::IceProxy::csr::ResultCallbackProxy& l, const ::IceProxy::csr::ResultCallbackProxy& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::csr::operator<(const ::IceProxy::csr::ResultCallbackProxy& l, const ::IceProxy::csr::ResultCallbackProxy& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::csr::operator<=(const ::IceProxy::csr::ResultCallbackProxy& l, const ::IceProxy::csr::ResultCallbackProxy& r)
{
    return l < r || l == r;
}

bool
IceProxy::csr::operator>(const ::IceProxy::csr::ResultCallbackProxy& l, const ::IceProxy::csr::ResultCallbackProxy& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::csr::operator>=(const ::IceProxy::csr::ResultCallbackProxy& l, const ::IceProxy::csr::ResultCallbackProxy& r)
{
    return !(l < r);
}

void
IceProxy::csr::StreamInterface::initCallbackProxy(const ::csr::ResultCallbackProxyPrx& proxy, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::csr::StreamInterface* __del = dynamic_cast< ::IceDelegate::csr::StreamInterface*>(__delBase.get());
            __del->initCallbackProxy(proxy, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::csr::StreamInterface::sendStreamData(const ::std::string& channelid, const ::std::string& strdata, ::Ice::Int rate, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::csr::StreamInterface* __del = dynamic_cast< ::IceDelegate::csr::StreamInterface*>(__delBase.get());
            __del->sendStreamData(channelid, strdata, rate, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::csr::StreamInterface::sendPackageData(const ::std::string& channelid, const ::std::string& packagedata, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__csr__StreamInterface__sendPackageData_name);
            __delBase = __getDelegate();
            ::IceDelegate::csr::StreamInterface* __del = dynamic_cast< ::IceDelegate::csr::StreamInterface*>(__delBase.get());
            return __del->sendPackageData(channelid, packagedata, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::csr::StreamInterface::ice_staticId()
{
    return ::csr::StreamInterface::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::csr::StreamInterface::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::csr::StreamInterface);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::csr::StreamInterface::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::csr::StreamInterface);
}

bool
IceProxy::csr::operator==(const ::IceProxy::csr::StreamInterface& l, const ::IceProxy::csr::StreamInterface& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::csr::operator!=(const ::IceProxy::csr::StreamInterface& l, const ::IceProxy::csr::StreamInterface& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::csr::operator<(const ::IceProxy::csr::StreamInterface& l, const ::IceProxy::csr::StreamInterface& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::csr::operator<=(const ::IceProxy::csr::StreamInterface& l, const ::IceProxy::csr::StreamInterface& r)
{
    return l < r || l == r;
}

bool
IceProxy::csr::operator>(const ::IceProxy::csr::StreamInterface& l, const ::IceProxy::csr::StreamInterface& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::csr::operator>=(const ::IceProxy::csr::StreamInterface& l, const ::IceProxy::csr::StreamInterface& r)
{
    return !(l < r);
}

void
IceDelegateM::csr::ResultCallbackProxy::sendStreamResult(const ::std::string& sessionid, const ::std::string& result, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __csr__ResultCallbackProxy__sendStreamResult_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(sessionid);
        __os->write(result);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::csr::StreamInterface::initCallbackProxy(const ::csr::ResultCallbackProxyPrx& proxy, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __csr__StreamInterface__initCallbackProxy_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::csr::__write(__os, proxy);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::csr::StreamInterface::sendStreamData(const ::std::string& channelid, const ::std::string& strdata, ::Ice::Int rate, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __csr__StreamInterface__sendStreamData_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
        __os->write(strdata);
        __os->write(rate);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::csr::StreamInterface::sendPackageData(const ::std::string& channelid, const ::std::string& packagedata, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __csr__StreamInterface__sendPackageData_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
        __os->write(packagedata);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateD::csr::ResultCallbackProxy::sendStreamResult(const ::std::string& sessionid, const ::std::string& result, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __csr__ResultCallbackProxy__sendStreamResult_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::csr::ResultCallbackProxy* __servant = dynamic_cast< ::csr::ResultCallbackProxy*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->sendStreamResult(sessionid, result, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::csr::StreamInterface::initCallbackProxy(const ::csr::ResultCallbackProxyPrx& proxy, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __csr__StreamInterface__initCallbackProxy_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::csr::StreamInterface* __servant = dynamic_cast< ::csr::StreamInterface*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->initCallbackProxy(proxy, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::csr::StreamInterface::sendStreamData(const ::std::string& channelid, const ::std::string& strdata, ::Ice::Int rate, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __csr__StreamInterface__sendStreamData_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::csr::StreamInterface* __servant = dynamic_cast< ::csr::StreamInterface*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->sendStreamData(channelid, strdata, rate, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::Ice::Int
IceDelegateD::csr::StreamInterface::sendPackageData(const ::std::string& channelid, const ::std::string& packagedata, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __csr__StreamInterface__sendPackageData_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::csr::StreamInterface* __servant = dynamic_cast< ::csr::StreamInterface*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->sendPackageData(channelid, packagedata, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::ObjectPtr
csr::ResultCallbackProxy::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __csr__ResultCallbackProxy_ids[2] =
{
    "::Ice::Object",
    "::csr::ResultCallbackProxy"
};

bool
csr::ResultCallbackProxy::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__csr__ResultCallbackProxy_ids, __csr__ResultCallbackProxy_ids + 2, _s);
}

::std::vector< ::std::string>
csr::ResultCallbackProxy::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__csr__ResultCallbackProxy_ids[0], &__csr__ResultCallbackProxy_ids[2]);
}

const ::std::string&
csr::ResultCallbackProxy::ice_id(const ::Ice::Current&) const
{
    return __csr__ResultCallbackProxy_ids[1];
}

const ::std::string&
csr::ResultCallbackProxy::ice_staticId()
{
    return __csr__ResultCallbackProxy_ids[1];
}

::IceInternal::DispatchStatus
csr::ResultCallbackProxy::___sendStreamResult(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sessionid;
    ::std::string result;
    __is->read(sessionid);
    __is->read(result);
    sendStreamResult(sessionid, result, __current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __csr__ResultCallbackProxy_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "sendStreamResult"
};

::IceInternal::DispatchStatus
csr::ResultCallbackProxy::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__csr__ResultCallbackProxy_all, __csr__ResultCallbackProxy_all + 5, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __csr__ResultCallbackProxy_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___sendStreamResult(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
csr::ResultCallbackProxy::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
csr::ResultCallbackProxy::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
csr::ResultCallbackProxy::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type csr::ResultCallbackProxy was not generated with stream support";
    throw ex;
}

void
csr::ResultCallbackProxy::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type csr::ResultCallbackProxy was not generated with stream support";
    throw ex;
}

void 
csr::__patch__ResultCallbackProxyPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::csr::ResultCallbackProxyPtr* p = static_cast< ::csr::ResultCallbackProxyPtr*>(__addr);
    assert(p);
    *p = ::csr::ResultCallbackProxyPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::csr::ResultCallbackProxy::ice_staticId();
        throw e;
    }
}

bool
csr::operator==(const ::csr::ResultCallbackProxy& l, const ::csr::ResultCallbackProxy& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
csr::operator!=(const ::csr::ResultCallbackProxy& l, const ::csr::ResultCallbackProxy& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
csr::operator<(const ::csr::ResultCallbackProxy& l, const ::csr::ResultCallbackProxy& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
csr::operator<=(const ::csr::ResultCallbackProxy& l, const ::csr::ResultCallbackProxy& r)
{
    return l < r || l == r;
}

bool
csr::operator>(const ::csr::ResultCallbackProxy& l, const ::csr::ResultCallbackProxy& r)
{
    return !(l < r) && !(l == r);
}

bool
csr::operator>=(const ::csr::ResultCallbackProxy& l, const ::csr::ResultCallbackProxy& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
csr::StreamInterface::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __csr__StreamInterface_ids[2] =
{
    "::Ice::Object",
    "::csr::StreamInterface"
};

bool
csr::StreamInterface::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__csr__StreamInterface_ids, __csr__StreamInterface_ids + 2, _s);
}

::std::vector< ::std::string>
csr::StreamInterface::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__csr__StreamInterface_ids[0], &__csr__StreamInterface_ids[2]);
}

const ::std::string&
csr::StreamInterface::ice_id(const ::Ice::Current&) const
{
    return __csr__StreamInterface_ids[1];
}

const ::std::string&
csr::StreamInterface::ice_staticId()
{
    return __csr__StreamInterface_ids[1];
}

::IceInternal::DispatchStatus
csr::StreamInterface::___initCallbackProxy(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::csr::ResultCallbackProxyPrx proxy;
    ::csr::__read(__is, proxy);
    initCallbackProxy(proxy, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
csr::StreamInterface::___sendStreamData(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string channelid;
    ::std::string strdata;
    ::Ice::Int rate;
    __is->read(channelid);
    __is->read(strdata);
    __is->read(rate);
    sendStreamData(channelid, strdata, rate, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
csr::StreamInterface::___sendPackageData(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string channelid;
    ::std::string packagedata;
    __is->read(channelid);
    __is->read(packagedata);
    ::Ice::Int __ret = sendPackageData(channelid, packagedata, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __csr__StreamInterface_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "initCallbackProxy",
    "sendPackageData",
    "sendStreamData"
};

::IceInternal::DispatchStatus
csr::StreamInterface::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__csr__StreamInterface_all, __csr__StreamInterface_all + 7, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __csr__StreamInterface_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___initCallbackProxy(in, current);
        }
        case 5:
        {
            return ___sendPackageData(in, current);
        }
        case 6:
        {
            return ___sendStreamData(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
csr::StreamInterface::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
csr::StreamInterface::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
csr::StreamInterface::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type csr::StreamInterface was not generated with stream support";
    throw ex;
}

void
csr::StreamInterface::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type csr::StreamInterface was not generated with stream support";
    throw ex;
}

void 
csr::__patch__StreamInterfacePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::csr::StreamInterfacePtr* p = static_cast< ::csr::StreamInterfacePtr*>(__addr);
    assert(p);
    *p = ::csr::StreamInterfacePtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::csr::StreamInterface::ice_staticId();
        throw e;
    }
}

bool
csr::operator==(const ::csr::StreamInterface& l, const ::csr::StreamInterface& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
csr::operator!=(const ::csr::StreamInterface& l, const ::csr::StreamInterface& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
csr::operator<(const ::csr::StreamInterface& l, const ::csr::StreamInterface& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
csr::operator<=(const ::csr::StreamInterface& l, const ::csr::StreamInterface& r)
{
    return l < r || l == r;
}

bool
csr::operator>(const ::csr::StreamInterface& l, const ::csr::StreamInterface& r)
{
    return !(l < r) && !(l == r);
}

bool
csr::operator>=(const ::csr::StreamInterface& l, const ::csr::StreamInterface& r)
{
    return !(l < r);
}
