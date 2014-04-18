////////////////////////////////////////////////////////////////////////////
// Semaphore_inl.h -- Win32 semaphore
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

MZC_INLINE MSemaphore::MSemaphore()
{
}

MZC_INLINE MSemaphore::MSemaphore(LONG lInitialCount,
    LONG lMaxCount/* = 1*/, LPCTSTR pstrName/* = NULL*/,
    LPSECURITY_ATTRIBUTES lpsaAttributes/* = NULL*/)
{
    assert(lMaxCount > 0);
    assert(lInitialCount <= lMaxCount);

    CreateSemaphore(lInitialCount, lMaxCount, pstrName, lpsaAttributes);
}

MZC_INLINE /*virtual*/ BOOL MSemaphore::Unlock()
{
    return Unlock(1);
}

MZC_INLINE BOOL MSemaphore::CreateSemaphore(
    LONG lInitialCount/* = 1*/, LONG lMaxCount/* = 1*/,
    LPCTSTR pstrName/* = NULL*/,
    LPSECURITY_ATTRIBUTES lpsaAttributes/* = NULL*/)
{
    assert(lMaxCount > 0);
    assert(lInitialCount <= lMaxCount);

    Attach(::CreateSemaphore(
        lpsaAttributes, lInitialCount, lMaxCount, pstrName));
    return m_hObject != NULL;
}

MZC_INLINE /*virtual*/ BOOL MSemaphore::Unlock(LONG lCount, LPLONG lprevCount/* = NULL*/)
{
    return ::ReleaseSemaphore(m_hObject, lCount, lprevCount);
}
