////////////////////////////////////////////////////////////////////////////
// Mutex.hpp -- Win32 mutex object
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#ifndef __MZC3_MUTEX__
#define __MZC3_MUTEX__

////////////////////////////////////////////////////////////////////////////

class MMutex : public MSyncObject
{
public:
    MMutex();
    MMutex(BOOL bInitiallyOwn, LPCTSTR lpszName = NULL,
           LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
    BOOL CreateMutex(BOOL bInitiallyOwn = FALSE, LPCTSTR lpszName = NULL,
           LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
    virtual BOOL Unlock();
};

////////////////////////////////////////////////////////////////////////////

#ifndef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE inline
    #include "Mutex_inl.hpp"
#endif

#endif  // ndef __MZC3_MUTEX__
