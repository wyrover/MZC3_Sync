////////////////////////////////////////////////////////////////////////////
// SyncObject_inl.h -- Win32 synchronization object
// This file is part of MZC3.  See file "ReadMe.txt" and "License.txt".
////////////////////////////////////////////////////////////////////////////

MZC_INLINE MSyncObject::MSyncObject() : m_hObject(NULL)
{
}

MZC_INLINE /*virtual*/ MSyncObject::~MSyncObject()
{
    if (m_hObject)
        CloseHandle();
}

MZC_INLINE MSyncObject::operator HANDLE() const
{
    return m_hObject;
}


MZC_INLINE MSyncObject::operator bool() const
{
    return m_hObject != NULL;
}

MZC_INLINE bool MSyncObject::operator!() const
{
    return m_hObject == NULL;
}

MZC_INLINE bool MSyncObject::operator==(HANDLE hObject) const
{
    return m_hObject == hObject;
}

MZC_INLINE bool MSyncObject::operator!=(HANDLE hObject) const
{
    return m_hObject != hObject;
}

MZC_INLINE MSyncObject& MSyncObject::operator=(HANDLE hObject)
{
    if (m_hObject != hObject)
    {
        if (m_hObject)
            CloseHandle();
        m_hObject = hObject;
    }
    return *this;
}

MZC_INLINE VOID MSyncObject::Attach(HANDLE hObject)
{
    assert(hObject);
    assert(m_hObject == NULL);
    m_hObject = hObject;
}

MZC_INLINE HANDLE MSyncObject::Detach()
{
    HANDLE hObject = m_hObject;
    m_hObject = NULL;
    return hObject;
}

MZC_INLINE /*virtual*/ BOOL MSyncObject::Lock(DWORD dwTimeout/* = INFINITE*/)
{
    return ::WaitForSingleObject(m_hObject, dwTimeout) == WAIT_OBJECT_0;
}

MZC_INLINE BOOL MSyncObject::CloseHandle()
{
    BOOL bOK = ::CloseHandle(m_hObject);
    assert(bOK);
    m_hObject = NULL;
    return bOK;
}
