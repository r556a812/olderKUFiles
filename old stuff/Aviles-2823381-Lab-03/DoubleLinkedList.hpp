/**
*	@file : DoubleLinkedList.h
*	@author : Richard Aviles
*	@date : 2015.09.24
        Purpose:
*/

#include "DoubleLinkedList.h"
#include "Node.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while (!isEmpty())
    {
        removeFront();
    }
}


template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
    if (m_size == 0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}


template <typename T>
int DoubleLinkedList<T>::size() const
{
    return (m_size);
}


template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
    Node<T>* temp = nullptr;

    if (isEmpty())
    {
        m_front = new Node<T>();
        m_front -> setValue(value);
        m_back = m_front;
        m_size++;
    }
    else
    {
        temp = new Node<T>();
        temp -> setValue(value);
        m_front -> setPrevious(temp);
        temp -> setNext(m_front);
        temp -> setPrevious(nullptr);
        m_front = temp;
        while (m_back -> getNext() != nullptr)
        {
            m_back = m_back -> getNext();
        }
        m_size++;
    }
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
    Node<T>* temp = nullptr;
    Node<T>* last = nullptr;

    if (isEmpty())
    {
        m_front = new Node<T>();
        m_front -> setValue(value);
        m_back = m_front;
        m_size++;
    }
    else
    {
        last = m_front;
        while (last->getNext() != nullptr)
        {
            last = last->getNext();
        }
        temp = new Node<T>();
        temp -> setValue(value);
        temp -> setPrevious(last);
        last -> setNext(temp);
        m_back = temp;
        m_size++;

    }
}

template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
    if (isEmpty())
    {
        return(false);
    }
    else
    {
        Node<T>* temp = m_front;
        m_front = m_front->getNext();
        m_front -> setPrevious(nullptr);
        delete temp;
        temp = nullptr;
        m_size--;
        return(true);
    }
}

template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
    if (isEmpty())
    {
        return (false);
    }
    else
    {
        Node<T>* last = nullptr;
        last = m_front;

        while (last->getNext() != nullptr)
        {
            last = last->getNext();
        }
        Node<T>* temp = last;
        last = last -> getPrevious();
        last ->setNext(nullptr);
        delete temp;
        temp = nullptr;

        m_back = last;
        m_size--;
        return (true);

    }
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
    Node<T>* search = m_front;
    while (search -> getValue() != value)
    {
        search = search -> getNext();
    }



    if (search -> getValue() == value)
    {
        if (m_size == 1)
        {
            delete m_front;
            m_front = nullptr;
            m_back = nullptr;
            m_size = 0;
            return (true);
        }
        else
        {
          Node<T>* temp = search;
          if (search -> getNext() == nullptr)
          {
              search = search -> getPrevious();
              search -> setNext(nullptr);
              temp -> setPrevious(nullptr);
              delete temp;

              while (m_back -> getNext() != nullptr)
              {
                  m_back = m_back -> getNext();
              }

              m_size--;

              return (true);
          }
          else
          {
              temp = temp -> getPrevious();
              temp -> setNext(search -> getNext());
              temp = temp -> getNext();
              temp -> setPrevious(search -> getPrevious());
              delete search;
              search -> setNext(nullptr);
              search -> setPrevious(nullptr);

              while (m_back -> getNext() != nullptr)
              {
                  m_back = m_back -> getNext();
              }

              m_size--;

              return(true);

          }
        }
    }
    else
    {
        return (false);
    }

}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
   if (!isEmpty())
   {
       Node<T>* add = m_front;
       Node<T>* temp = new Node<T>();
       Node<T>* add2 = nullptr;

       while (add -> getValue() != listValue)
       {
           add = add -> getNext();
       }

       add2 = add;
       temp -> setValue(newValue);
       temp -> setPrevious(add -> getPrevious());
       temp -> setNext(add);
       add = add -> getPrevious();
       add -> setNext(temp);
       add2 -> setPrevious(temp);

       while (m_back -> getNext() != nullptr)
       {
           m_back = m_back -> getNext();
       }
       m_size++;


   }
   else
   {
       throw (std::runtime_error ("Not in the list"));
   }

}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
    if (!isEmpty())
    {
        Node<T>* add = m_front;
        Node<T>* temp = new Node<T>();

        while (add -> getValue() != listValue)
        {
            add = add -> getNext();
        }

        Node<T>* add2 = add;
        temp -> setValue(newValue);
        temp -> setPrevious(add);
        temp -> setNext(add -> getNext());
        add = add -> getNext();
        add -> setPrevious(temp);
        add2 -> setNext(temp);

        while (m_back -> getNext() != nullptr)
        {
            m_back = m_back -> getNext();
        }
        m_size++;


    }
    else
    {
        throw (std::runtime_error ("Not in the list"));
    }
}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
    Node<T>* temp = m_front;
    while (temp -> getValue() != value)
    {
        temp = temp -> getNext();
    }

    return (temp);
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
    if (isEmpty())
    {
        std::cout << "";
    }
    else
    {
        Node<T>* last = m_front;

        while(last != nullptr)
        {
            std::cout << last->getValue() << " ";
            last = last->getNext();
        }

    }

}
