////////////////////////////////////////////////////////////////////////////
// Semaphore.hpp -- Win32 semaphore
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#ifndef __MZC3_SEMAPHORE__
#define __MZC3_SEMAPHORE__

////////////////////////////////////////////////////////////////////////////

class MSemaphore : public MSyncObject
{
public:
    MSemaphore();
    MSemaphore(LONG lInitialCount, LONG lMaxCount = 1,
               LPCTSTR pstrName = NULL,
               LPSECURITY_ATTRIBUTES lpsaAttributes = NULL);
    BOOL CreateSemaphore(LONG lInitialCount = 1, LONG lMaxCount = 1,
                         LPCTSTR pstrName = NULL,
                         LPSECURITY_ATTRIBUTES lpsaAttributes = NULL);
    virtual BOOL Unlock();
    virtual BOOL Unlock(LONG lCount, LPLONG lprevCount = NULL);
};

////////////////////////////////////////////////////////////////////////////

#ifndef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE inline
    #include "Semaphore_inl.hpp"
#endif

#endif  // ndef __MZC3_SEMAPHORE__
