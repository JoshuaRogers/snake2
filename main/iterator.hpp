#ifndef __LISTITERATOR_HPP__
#define __LISTITERATOR_HPP__

#include <memory>
#include "globals.hpp"
#include "listnode.hpp"

template <class T>
class Iterator
{
    public:
        Iterator(std::shared_ptr<ListNode<T>> node) {
            _node = node;
        }

        bool moveNext() {
            if (hasNext()) {
                _node = _node->getNext();
                return true;
            } else {
                return false;
            }
        }

        T getValue() {
            return _node->getValue();
        }

    private:
        bool hasNext() {
            return _node->hasNext();
        }

        std::shared_ptr<ListNode<T>> _node;
};

#endif