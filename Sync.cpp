////////////////////////////////////////////////////////////////////////////
// Sync.cpp -- Win32 synchronization
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#ifdef MZC_NO_INLINING
    #undef MZC_INLINE
    #define MZC_INLINE  /*empty*/
    #include "SyncObject_inl.hpp"
    #include "CriticalSection_inl.hpp"
    #include "Event_inl.hpp"
    #include "Mutex_inl.hpp"
    #include "Semaphore_inl.hpp"
#endif

////////////////////////////////////////////////////////////////////////////
