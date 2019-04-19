#ifndef __SAFEQUEUE_H__
#define __SAFEQUEUE_H__

#include <IceUtil/Mutex.h>
#include <IceUtil/Monitor.h>
#include <list>

template <class T>
class SafeQueue : public IceUtil::Monitor<IceUtil::Mutex>
{
public:
	SafeQueue() 
		: _waitingReaders(0)
	{}

	void put(const T& item) {
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);

		_q.push_back(item);
		if (_waitingReaders)
			notify();
	}

	T get() {
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		while (_q.empty()) {
			try {
				++_waitingReaders;
				wait();
				--_waitingReaders;
			} catch (...) {
				--_waitingReaders;
				throw;
			}

		}
		T item = _q.front();
		_q.pop_front();
		return item;
	}
	bool timedGet(T & ret,int timeout)
	{
		IceUtil::Monitor<IceUtil::Mutex>::Lock lock(*this);
		++_waitingReaders;
		if (_q.empty())
			timedWait(IceUtil::Time::seconds(timeout));
		if (_q.empty())
		{
			--_waitingReaders;
			return false;
		}
		ret = _q.front();
		_q.pop_front();
		--_waitingReaders;
		return true;
	}

	inline int size()
	{
		return static_cast<int>(_q.size());
	}

	inline int waiterNum()
	{
		return _waitingReaders;
	}
private:
	std::list<T>    _q;
	short           _waitingReaders;


};


#endif /*__SAFEQUEUE_H__*/

