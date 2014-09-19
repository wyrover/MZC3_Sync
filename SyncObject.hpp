////////////////////////////////////////////////////////////////////////////
// SyncObject.hpp -- Win32 synchronization object
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#ifndef __MZC3_SYNCOBJECT__
#define __MZC3_SYNCOBJECT__

////////////////////////////////////////////////////////////////////////////

class MSyncObject EXTENDS_MOBJECT
{
protected:
    HANDLE m_hObject;
    MSyncObject();

public:
    virtual ~MSyncObject();
    operator bool() const;
    bool operator!() const;
    operator HANDLE() const;
    MSyncObject& operator=(HANDLE hObject);
    bool operator==(HANDLE hObject) const;
    bool operator!=(HANDLE hObject) const;

    void Attach(HANDLE hObject);
    HANDLE Detach();

    virtual BOOL Lock(DWORD dwTimeout = INFINITE);
    virtual BOOL Unlock() = 0;

    BOOL CloseHandle();
};

////////////////////////////////////////////////////////////////////////////

#ifndef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE inline
    #include "SyncObject_inl.hpp"
#endif

#endif  // ndef __MZC3_SYNCOBJECT__
