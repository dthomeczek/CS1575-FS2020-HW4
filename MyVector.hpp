/* Define all your MyVector-related functions here, including the swap and the
    get_identity functions.
 * You do not need to include MyVector.h in this hpp header file. It includes
    this file at the bottom.
 */

void get_identity(string &my_id)
{
    my_id = "djtpfr";
}

template <typename T>
void MySwap(T & a, T & b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
MyVector<T>::MyVector()
{
    reserved_size = 0;
    data_size = 0;
    m_data = new T[reserved_size];
}

// We're giving you this one for freenand as a guide for the syntax.
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
    data_size = source.data_size;
    reserved_size = source.reserved_size;
    for (int i = 0; i < data_size; i++)
    {
        m_data[i] = source.m_data[i];
    }
    
    return *this;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
    reserved_size = source.reserved_size;
    data_size = source.data_size;
    for (int i = 0; i < data_size; i++)
    {
        m_data[i] = source.m_data[i];
    }
}

template <typename T>
T & MyVector<T>::operator[](int i)
{
    return m_data[i];
}

// Another example: remember when writing an implementation in hpp,
// return type first, then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{
    if (index > data_size || index < 0)
    {
        throw std::out_of_range("Out of range error");
    }
    else
    {
        return m_data[index];
    }
}

template <typename T>
T & MyVector<T>::front()
{
    return m_data[0];
}

template <typename T>
T & MyVector<T>::back()
{
    return m_data[data_size - 1];
}

template <typename T>
int MyVector<T>::capacity()
{
    return reserved_size;
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
    if(new_cap > reserved_size)
    {
        if(reserved_size == 0)
        {
            delete[] m_data;

            reserved_size = new_cap;
            T *temp_arr = new T[reserved_size];
        }
        else
        {
            reserved_size = new_cap;
            T *temp_arr = new T[reserved_size];

            for(int i = 0; i < data_size; i++)
            {
            temp_arr[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new T[reserved_size];

            for(int j = 0; j < data_size; j++)
            {
                m_data[j] = temp_arr[j];
            }
            delete temp_arr;
        }
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    reserved_size = data_size * 2;
    T *tempArr = new T[reserved_size];

    for(int i = 0; i < data_size; i++)
    {
        tempArr[i] = m_data[i];
    }
    delete[] m_data;

    for(int j = 0; j < data_size; j++)
    {
        m_data[j] = tempArr[j];
    }
    delete[] tempArr;
}

template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
    delete[] m_data;
    m_data = new T[reserved_size];
    reserve(count);

    for(int i = 0; i < count; i++)
    {
        m_data[i] = value;
        data_size = count;
    }
    if((reserved_size / 4) > data_size)
    {    
        shrink_to_fit();
    }
}

template <typename T>
void MyVector<T>::clear()
{
    reserved_size = 0;
    data_size = 0;

    delete[] m_data;
    m_data = nullptr;
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{
    data_size++;
    if(data_size > reserved_size)
    {
        if(data_size == 1)
        {
            reserve(1);
        }
        else
        {
            reserve(data_size * 2);
        }
    }
    m_data[data_size -1] = x;
}

template <typename T>
void MyVector<T>::pop_back()
{
    data_size -= 1;
    if((reserved_size/4) > data_size)
    {    
        shrink_to_fit();
    }
}

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
    reserve(data_size + 1);

    for(int k = data_size - 1; k >= i; k--)
    {
        m_data[k+1] = m_data[k];
    }

    m_data[i] = x;
    data_size++;
}

template <typename T>
void MyVector<T>::erase(int i)
{
    if(data_size > 0)
    {
        for(int k = i; k < data_size - 1; k++)
        {
            m_data[k] = m_data[k+1];
        }
        data_size--;
        if((reserved_size / 4) > data_size)
        {
            shrink_to_fit();
        }
    }
}

template <typename T>
int MyVector<T>::size()
{
    return data_size;
}