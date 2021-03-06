#ifndef __LISTNODE_HPP__
#define __LISTNODE_HPP__

#include <memory>
#include "globals.hpp"

template <class T>
class ListNode
{
    public:
        ListNode() {}
        ListNode(T value) : _value(value) {}

        bool hasNext() {
            return _next.get() != NULL;
        }

        std::shared_ptr<ListNode<T>> getNext() {
            if (hasNext()) {
                return _next;
            } else {
                log("Attempting to step past end of list iterator.");
                return std::shared_ptr<ListNode<T>>(NULL);
            }
        }

        void insertNext(std::shared_ptr<ListNode<T>> node) {
            if (node.get() == NULL) {
                log("Attempting to insert a NULL node");
            }

            node->_next = _next;
            _next = node;
        }

        void removeNext() {
            auto hasGrandChild = _next != NULL && _next->_next != NULL;
            if (hasGrandChild) {
                _next = _next->_next;
            } else {
                _next = NULL;
            }
        }

        T getValue() {
            return _value;
        }

        void setValue(T value) {
            _value = value;
        }

    private:
        std::shared_ptr<ListNode<T>> _next;
        T _value;
};

#endif