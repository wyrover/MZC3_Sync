////////////////////////////////////////////////////////////////////////////
// Sync.cpp -- Win32 synchronization
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#ifdef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE  /*empty*/
    #include "SyncObject_inl.h"
    #include "CriticalSection_inl.h"
    #include "Event_inl.h"
    #include "Mutex_inl.h"
    #include "Semaphore_inl.h"
#endif

////////////////////////////////////////////////////////////////////////////
