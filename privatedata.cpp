#include <stdlib.h>
#include "privatedata.h"

PrivateData::PrivateData(/* args */)
{
}

PrivateData::~PrivateData()
{
}

bool PrivateData::dataMask(Data *data)
{
    if (data->m_MaskLen)
        return true;
    
    if (data->m_Mask && data->m_MaskLen < data->m_ValueLen)
    {
        dataFree(data->m_Mask, data->m_MaskLen);
        data->m_Mask = nullptr;
        data->m_MaskLen = 0;
    }

    if (!data->m_Mask)
    {
        data->m_Mask = new char [data->m_ValueLen];
        data->m_MaskLen = data->m_ValueLen;
    }
    return true;
}

bool PrivateData::dataUnmask(Data *data)
{
    if (!data->m_MaskLen)
        return true;

    for (int i=0; data->m_MaskLen > i; ++i)
    {
        data->m_Value[i] ^= data->m_Mask[i];
    }

    dataFree(data->m_Mask, data->m_MaskLen);
    data->m_Mask = nullptr;
    data->m_MaskLen = 0;

    return true;
}

void PrivateData::dataFree(void *memory, unsigned int bytes)
{
    if (memory)
        delete(memory);
}