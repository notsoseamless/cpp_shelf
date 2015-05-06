//
// $Id: GSoapService.cpp 1337 2007-09-27 17:08:48Z stephend $
//
#include "ThreadSafeBool.hpp"

ThreadSafeBool::ThreadSafeBool(bool bInit)
: bValue(bInit)
{
}

bool ThreadSafeBool::get() const
{
   boost::mutex::scoped_lock lock(m_mutex);
   return bValue;
}

bool ThreadSafeBool::operator!() const
{
   boost::mutex::scoped_lock lock(m_mutex);
   return !bValue;
}

void ThreadSafeBool::set(bool bNewValue)
{
   boost::mutex::scoped_lock lock(m_mutex);
   bValue = bNewValue;
}
