#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include <memory>
#include "globals.hpp"
#include "iterator.hpp"

template <class T>
class List
{
    public:
        List() : _length(0) {
            _head = std::make_shared<ListNode<T>>(ListNode<T>());
        }

        void add(T item)
        {
            add(item, _length);
        }

        void add(T item, int index)
        {
            auto parent = getBefore(index);
            auto node = std::make_shared<ListNode<T>>(ListNode<T>(item));
            parent->insertNext(node);

            _length++;
        }

        void remove(int index)
        {
            auto node = getBefore(index);
            node->removeNext();

            _length--;
        }

        T get(int index)
        {
            return getBefore(index + 1)->getValue();
        }

        Iterator<T> getIterator()
        {
            return Iterator<T>(_head);
        }

        int getLength()
        {
            return _length;
        }

     private:
        std::shared_ptr<ListNode<T>> _head;
        int _length;

        std::shared_ptr<ListNode<T>> getBefore(int index)
        {
            auto node = _head;
            for (int i = 0; i < index; i++) {
                node = node->getNext();
            }
            return node;
        }
};

#endif