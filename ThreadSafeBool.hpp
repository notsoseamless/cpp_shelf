//
// $Id: ThreadSafeBool.h 1989 2007-10-23 16:06:18Z stephend $
//
#include <boost/thread/mutex.hpp>

class ThreadSafeBool
{
public:
   explicit ThreadSafeBool(bool bInit);
   bool operator!() const;
   bool get() const;
   void set(bool bValue);
private:
   mutable boost::mutex m_mutex;
   bool bValue;
};
