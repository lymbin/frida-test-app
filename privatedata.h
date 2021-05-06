struct Data
{
    unsigned int m_ValueLen;
    char *m_Value;
    unsigned int m_MaskLen;
    char *m_Mask;
};



class PrivateData
{
private:

    /* data */
public:
    PrivateData(/* args */);
    ~PrivateData();

    bool dataMask(Data *data);
    bool dataUnmask(Data *data);
    void dataFree(void* memory, unsigned int bytes);
};
