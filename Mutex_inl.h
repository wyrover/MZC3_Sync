////////////////////////////////////////////////////////////////////////////
// Mutex_inl.h -- Win32 mutex object
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

MZC_INLINE MMutex::MMutex()
{
}

MZC_INLINE MMutex::MMutex(BOOL bInitiallyOwn/* = FALSE*/,
    LPCTSTR lpszName/* = NULL*/,
    LPSECURITY_ATTRIBUTES lpsaAttribute/* = NULL*/)
{
    CreateMutex(bInitiallyOwn, lpszName, lpsaAttribute);
}

MZC_INLINE BOOL MMutex::CreateMutex(BOOL bInitiallyOwn/* = FALSE*/,
    LPCTSTR lpszName/* = NULL*/,
    LPSECURITY_ATTRIBUTES lpsaAttribute/* = NULL*/)
{
    Attach(::CreateMutex(lpsaAttribute, bInitiallyOwn, lpszName));
    return m_hObject != NULL;
}

MZC_INLINE /*virtual*/ BOOL MMutex::Unlock()
{
    return ::ReleaseMutex(m_hObject);
}
