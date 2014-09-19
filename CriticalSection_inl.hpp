////////////////////////////////////////////////////////////////////////////
// CriticalSection_inl.hpp -- Win32 critical section
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

MZC_INLINE MCriticalSection::MCriticalSection()
{
    ::InitializeCriticalSection(&m_cs);
}

#if (_WIN32_WINNT >= 0x0403)
MZC_INLINE MCriticalSection::MCriticalSection(DWORD dwSpinCount)
#else
MZC_INLINE MCriticalSection::MCriticalSection(DWORD)
#endif
{
#if (_WIN32_WINNT >= 0x0403)
    ::InitializeCriticalSectionAndSpinCount(&m_cs, dwSpinCount);
#else
    MzcFootmarkThis();
    ::InitializeCriticalSection(&m_cs);
#endif
}

MZC_INLINE /*virtual*/ MCriticalSection::~MCriticalSection()
{
    ::DeleteCriticalSection(&m_cs);
}

MZC_INLINE /*virtual*/ BOOL MCriticalSection::Lock()
{
    ::EnterCriticalSection(&m_cs);
    return TRUE;
}

MZC_INLINE /*virtual*/ BOOL MCriticalSection::Lock(DWORD dwTimeout)
{
#if (_WIN32_WINNT >= 0x0400)
    if (dwTimeout != 0)
        MzcFootmarkThis();
    return ::TryEnterCriticalSection(&m_cs);
#else
    MzcFootmarkThis();
    return FALSE;
#endif
}

MZC_INLINE /*virtual*/ BOOL MCriticalSection::Unlock()
{
    ::LeaveCriticalSection(&m_cs);
    return TRUE;
}

MZC_INLINE MCriticalSection::operator LPCRITICAL_SECTION()
{
    return &m_cs;
}
