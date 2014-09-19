////////////////////////////////////////////////////////////////////////////
// CriticalSection.hpp -- Win32 critical section wrapper
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#ifndef __MZC3_CRITICALSECTION__
#define __MZC3_CRITICALSECTION__

////////////////////////////////////////////////////////////////////////////

class MCriticalSection : public MSyncObject
{
public:
    MCriticalSection();
    MCriticalSection(DWORD dwSpinCount);
    virtual ~MCriticalSection();
    operator LPCRITICAL_SECTION();
    virtual BOOL Lock();
    virtual BOOL Lock(DWORD dwTimeout);
    virtual BOOL Unlock();

protected:
    CRITICAL_SECTION m_cs;
};

////////////////////////////////////////////////////////////////////////////

#ifndef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE inline
    #include "CriticalSection_inl.hpp"
#endif

#endif  // ndef __MZC3_CRITICALSECTION__
