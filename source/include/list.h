#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>  // cout, endl
using std::cout;
using std::endl;

#include <iterator>  // bidirectional_iterator_tag
#include <cassert>   // assert()
#include <algorithm> // copy
using std::copy;
#include <cstddef>   // std::ptrdiff_t
#include <type_traits>

namespace sc { // linear sequence. Better name: sequence container (same as STL).
    /*!
     * A class representing a biderectional iterator defined over a linked list.
     *
     * \note
     * This iterator only works for traversing elements inside the same list.
     *
     * This class is incomplete and it is provided "as is".
     *
     * \date May, 2nd 2017.
     * \author Selan R. dos Santos
     */

    template < typename T >
    class list
    {
        private:
        //=== the data node.
        struct Node
        {
            T data; // Tipo de informação a ser armazenada no container.
            Node * next;
            Node * prev;

            Node( const T &d=T{} , Node * n=nullptr, Node * p=nullptr )
                : data {d}, next{n}, prev{p}
            { /* empty */ }
        };


        //=== The iterator classes.
        public:

        class const_iterator : public std::bidirectional_iterator_tag 
        {
            //=== Some aliases to help writing a clearer code.
            public:
                using value_type        = T;         //!< The type of the value stored in the list.
                using pointer           = T *;       //!< Pointer to the value.
                using reference         = T &;       //!< reference to the value.
                using const_reference   = const T &; //!< const reference to the value.
                using difference_type   = std::ptrdiff_t;
                using iterator_category = std::bidirectional_iterator_tag;

            private:
                Node * m_ptr; //!< The raw pointer.

            public:
                const_iterator( Node * ptr = nullptr ){/*TODO*/}
                ~const_iterator() = default;
                const_iterator( const const_iterator & ) = default;
                const_iterator& operator=( const const_iterator & ) = default;
                reference  operator*() { /* TODO */ return m_ptr->data; }
                const_reference  operator*() const { /* TODO */ return nullptr; }
                const_iterator operator++() { /* TODO */ return const_iterator{}; }
                const_iterator operator++(int) { /* TODO */ return const_iterator{}; }
                const_iterator operator--() { /* TODO */ return const_iterator{}; }
                const_iterator operator--(int) { /* TODO */ return const_iterator{}; }
                bool operator==( const const_iterator & rhs ) const { /* TODO */ return false; }
                bool operator!=( const const_iterator & rhs ) const { /* TODO */ return false; }

                //=== Other methods that you might want to implement.
                /// it += 3; // Go back  3 positions within the container. 
                const_iterator operator+=( difference_type step) { /* TODO */ return const_iterator{}; }
                /// it -= 3; // Go back  3 positions within the container. 
                const_iterator operator-=(  difference_type step ) { /* TODO */ return const_iterator{}; }
                /// it->method()
                pointer operator->( void ) const { /* TODO */ return nullptr; }
                /// it1 - it2
                difference_type operator-( const const_iterator & rhs ) const { /* TODO */ return 0; }

                // We need friendship so the list<T> class may access the m_ptr field.
                friend class list<T>;

                friend std::ostream & operator<< ( std::ostream & os_, const const_iterator & s_ )
                {
                    os_ << "[@"<< s_.m_ptr << ", val = " << s_.m_ptr->data << "]";
                    return os_;
                }
        };


        class iterator : public std::bidirectional_iterator_tag 
        {
            //=== Some aliases to help writing a clearer code.
            public:
                using value_type        = T; //!< The type of the value stored in the list.
                using pointer           = T *; //!< Pointer to the value.
                using reference         = T &; //!< reference to the value.
                using const_reference   = const T &; //!< const reference to the value.
                using difference_type   = std::ptrdiff_t;
                using iterator_category = std::bidirectional_iterator_tag;

            private:
                Node * m_ptr; //!< The raw pointer.

            public:
                iterator( Node * ptr = nullptr ){/*TODO*/}
                ~iterator() = default;
                iterator( const iterator & ) = default;
                iterator& operator=( const iterator & ) = default;
                reference  operator*() { /* TODO */ return m_ptr->data; }
                const_reference  operator*() const { /* TODO */ return nullptr; }
                iterator operator++() { /* TODO */ return iterator{}; }
                iterator operator++(int) { /* TODO */ return iterator{}; }
                iterator operator--() { /* TODO */ return iterator{}; }
                iterator operator--(int) { /* TODO */ return iterator{}; }
                bool operator==( const iterator & rhs ) const { /* TODO */ return false; }
                bool operator!=( const iterator & rhs ) const { /* TODO */ return false; }

                //=== Other methods that you might want to implement.
                /// it += 3; // Go back  3 positions within the container. 
                iterator operator+=( difference_type step) { /* TODO */ return iterator{}; }
                /// it -= 3; // Go back  3 positions within the container. 
                iterator operator-=(  difference_type step ) { /* TODO */ return iterator{}; }
                /// it->method()
                pointer operator->( void ) const { /* TODO */ return nullptr; }
                /// it1 - it2
                difference_type operator-( const iterator & rhs ) const { /* TODO */ return 0; }

                // We need friendship so the list<T> class may access the m_ptr field.
                friend class list<T>;

                friend std::ostream & operator<< ( std::ostream & os_, const iterator & s_ )
                {
                    os_ << "[@"<< s_.m_ptr << ", val = " << s_.m_ptr->data << "]";
                    return os_;
                }
        };


        //=== Private members.
        private:
            size_t m_len;    // comprimento da lista.
            Node * m_head; // nó cabeça.
            Node * m_tail; // nó calda.

        public:
        //=== Public interface

        //=== [I] Special members
        list()
        { 
            /*  Head & tail nodes.
             *     +---+    +---+
             *     |   |--->|   |--+
             *     | H |    | T |  |
             *  +--|   |<---|   |  |
             *  |  +---+    +---+  |
             *  |                  |
             * ===                ===
             *  =                  =
             */
        }

        explicit list( size_t count ) { /* TODO */ }
        template< typename InputIt >
        list( InputIt first, InputIt last ) { /* TODO */ }
        list( const list & clone_ ) { /* TODO */ }
        list( std::initializer_list<T> ilist_ ) { /* TODO */ }
        ~list() { /* TODO */ }
        list & operator=( const list & rhs ) { /* TODO */ return *this;}
        list & operator=( std::initializer_list<T> ilist_ ) { /* TODO */ return *this;}
        //=== [II] ITERATORS
        iterator begin() { /* TODO */ return iterator{}; }
        const_iterator cbegin() const  { /* TODO */ return const_iterator{}; }
        iterator end() { /* TODO */ return iterator{}; }
        const_iterator cend() const  { /* TODO */ return const_iterator{}; }
        //=== [III] Capacity/Status
        bool empty ( void ) const { /* TODO */  return true; }
        size_t size(void) const { /* TODO */  return 0; }
        //=== [IV] Modifiers
        void clear()  { /* TODO */ }
        T front( void ) { /* TODO */ return T{}; }
        T front( void ) const  { /* TODO */ return T{}; }
        T back( void ) { /* TODO */ return T{}; }
        T back( void ) const  { /* TODO */ return T{}; }

        void push_front( const T & value_ ) { /* TODO */ }

        void push_back( const T & value_ ) { /* TODO */ }

        void pop_front( ) { /* TODO */ }

        void pop_back( ) { /* TODO */ }

        //=== [IV-a] MODIFIERS W/ ITERATORS
        template < class InItr >
        void assign( InItr first_, InItr last_ )
        { /* TODO */ }

        void assign( std::initializer_list<T> ilist_ )
        { /* TODO */ }

        /*!
         *  Inserts a new value in the list before the iterator 'it'
         *  and returns an iterator to the new node.
         *
         *  \param pos_ An iterator to the position before which we want to insert the new data.
         *  \param value_ The value we want to insert in the list.
         *  \return An iterator to the new element in the list.
         */
        iterator insert( iterator pos_, const T & value_ )
        { /* TODO */ return iterator{}; }

        template < typename InItr >
        iterator insert( iterator pos_, InItr first_, InItr last_ ) 
        { /* TODO */ return iterator{}; }
        
        iterator insert( iterator cpos_, std::initializer_list<T> ilist_ )
        { /* TODO */ return iterator{}; }

        /*!
         *  Erases the node pointed by 'it_' and returns an iterator
         *  to the node just past the deleted node.
         *
         *  \param it_ The node we wish to delete.
         *  \return An iterator to the node following the deleted node.
         */
        iterator erase( iterator it_ )
        { /* TODO */ return iterator{}; }
        // Erase items from [start; end) and return a iterator just past the deleted node.
        iterator erase( iterator start, iterator end )
        { /* TODO */ return iterator{}; }

        const_iterator find( const T & value_ ) const
        { /* TODO */ return const_iterator{}; }

        iterator find( const T & value_ )
        { /* TODO */ return iterator{}; }

        //=== [V] UTILITY METHODS
        void merge( list & other ){ return; }
        void splice( const_iterator pos, list & other ){ return; }
        void reverse( void ){ return; }
        void unique( void ){ return; }
        void sort( void ){ return; }
    };

    //=== [VI] OPETARORS
    template < typename T >
    inline bool operator==( const sc::list<T> & l1_, const sc::list<T> & l2_ )
    {
        /* TODO */ return true;
    }

    template < typename T >
    inline bool operator!=( const sc::list<T> & l1_, const sc::list<T> & l2_ )
    {
        /* TODO */ return true;
    }
}
#endif

