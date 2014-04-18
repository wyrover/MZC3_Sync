////////////////////////////////////////////////////////////////////////////
// Event.h -- Win32 event object
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#ifndef __MZC3_EVENT__
#define __MZC3_EVENT__

////////////////////////////////////////////////////////////////////////////

class MEvent : public MSyncObject
{
public:
    MEvent();
    MEvent(BOOL bInitiallyOwn, BOOL bManualReset = FALSE,
           LPCTSTR lpszName = NULL,
           LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
    BOOL CreateEvent(BOOL bInitiallyOwn = FALSE, BOOL bManualReset = FALSE,
           LPCTSTR lpszName = NULL,
           LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
    BOOL SetEvent();
    BOOL PulseEvent();
    BOOL ResetEvent();
    virtual BOOL Unlock();
};

////////////////////////////////////////////////////////////////////////////

#ifndef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE inline
    #include "Event_inl.h"
#endif

#endif  // ndef __MZC3_EVENT__
