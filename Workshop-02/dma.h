#ifndef SENECA_DMA_H
namespace seneca {
    struct Contact {
        char
            m_name[21],
            m_lastname[31];
        long long
            m_phoneNumber;
    };

   
    /// Receives an unknown number of double numbers from the console and prints them in reverse order.
        
    void reverse();

    Contact* getContact();
    void display(const Contact& contact);
    void deallocate(Contact* contact);
    void setEmpty(Contact& contact);

}
#endif // !SENECA_DMA_H
