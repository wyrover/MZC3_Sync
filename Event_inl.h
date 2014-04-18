////////////////////////////////////////////////////////////////////////////
// Event_inl.h -- Win32 event object
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

MZC_INLINE MEvent::MEvent()
{
}

MZC_INLINE MEvent::MEvent(BOOL bInitiallyOwn,
    BOOL bManualReset, LPCTSTR lpszName/* = NULL*/,
    LPSECURITY_ATTRIBUTES lpsaAttribute/* = NULL*/)
{
    CreateEvent(bInitiallyOwn, bManualReset, lpszName, lpsaAttribute);
    assert(m_hObject != NULL);
}
    
MZC_INLINE BOOL MEvent::CreateEvent(
    BOOL bInitiallyOwn/* = FALSE*/, BOOL bManualReset/* = FALSE*/,
    LPCTSTR lpszName/* = NULL*/,
    LPSECURITY_ATTRIBUTES lpsaAttribute/* = NULL*/)
{
    assert(m_hObject == NULL);
    Attach(::CreateEvent(
        lpsaAttribute, bManualReset, bInitiallyOwn, lpszName));
    return m_hObject != NULL;
}

MZC_INLINE /*virtual*/ BOOL MEvent::Unlock()
{
    return TRUE;
}

MZC_INLINE BOOL MEvent::SetEvent()
{
    assert(m_hObject != NULL);
    return ::SetEvent(m_hObject);
}

MZC_INLINE BOOL MEvent::PulseEvent()
{
    assert(m_hObject != NULL);
    return ::PulseEvent(m_hObject);
}

MZC_INLINE BOOL MEvent::ResetEvent()
{
    assert(m_hObject != NULL);
    return ::ResetEvent(m_hObject);
}
