#pragma once                                                              
#include <exception>                                                      
                                                                          
template <typename Type>                                                  
class List                                                                {                                                               
public:                                                                   
    struct Node                                                           {                                                          
        Type data                                                         ;                                                         
        Node * next                                                       ;                                                       
        Node(Type const & d): data(d), next(nullptr)                      {}};
                                                                          
                                                                          
    struct iterator                                                       {                                                      
        Node * _node                                                      ;                                                      
        iterator(Node * node = nullptr): _node(node)                      {}                     
        Type & operator*() const                                          {                                         
            return _node->data                                            ;}
                                                                          
                                                                          
        bool operator==(iterator const & it)                              {                             
            return _node == it._node                                      ;}
                                                                          
                                                                          
        bool operator!=(iterator const & it)                              {                             
            return !(*this == it)                                         ;}
                                                                          
                                                                          
        iterator & operator++()                                           {                                          
            _node = _node->next                                           ;                                           
            return *this                                                  ;}
                                                                          
                                                                          
        iterator operator++(int)                                          {                                         
            Node * tmp = _node                                            ;                                            
            _node = _node->next                                           ;                                           
            return iterator(tmp)                                          ;}
                                                                          };
                                                                          
                                                                          
private:                                                                  
    Node * _root                                                          ;                                                          
    size_t _size                                                          ;                                                          
public:                                                                   
    List():_root(nullptr), _size(0)                                       {}                                      
                                                                          
    List(Type * data, size_t size)                                        {                                       
        ///TODO: implement                                                
                                                                          }
                                                                          
                                                                          
    List(List const & source)                                             {                                            
        ///TODO: implement                                                
                                                                          }
                                                                          
                                                                          
    List & operator=(List const & source)                                 {                                
        ///TODO: implement                                                
                                                                          }
                                                                          
                                                                          
    void clear()                                                          {                                                         
        while (_root != nullptr)                                          {                                         
            Node * tmp = _root                                            ;                                            
            _root = _root->next                                           ;                                           
            delete tmp                                                    ;}
                                                                          
        _size = 0                                                         ;}
                                                                          
    ~List()                                                               {                                                              
        clear()                                                           ;}
                                                                          
                                                                          
    void push_back(Type const & val)                                      ;                                      
    void erase(iterator to_die_it)                                        ;                                        
                                                                          
    iterator begin() { return iterator(_root);                            }                           
    iterator end() { return iterator();                                   }                                  
                                                                          
    //void push_back(Type const& val)                                     ;      
    //void insert(Type& const val, iterator it_after)                     ;      
    //void resize(size_t new_size)                                        ;      
                                                                          
    //iterator find(Type& const to_find)                                  ;      
                                                                          };
                                                                          
                                                                          
template <class Type>                                                     
void List<Type>::push_back(Type const & val)                              {                             
    if (_root == nullptr)                                                 {                                                
        _root = new Node(val)                                             ;                                             
        _size = 1                                                         ;                                                         
        return                                                            ;}
                                                                          
                                                                          
    Node * curr = _root                                                   ;                                                   
    while (curr->next != nullptr)                                         
        curr = curr->next                                                 ;                                                 
    Node * new_node = new Node(val)                                       ;                                       
    curr->next = new_node                                                 ;                                                 
    ++_size                                                               ;}
                                                                          
                                                                          
template <class Type>                                                     
void List<Type>::erase(iterator to_die_it)                                {                               
    if (_root == nullptr)                                                 
        throw "empty list"                                                ;                                                
                                                                          
    Node * to_die = to_die_it._node                                       ;                                       
    Node * curr = _root                                                   ;                                                   
    while (curr->next != to_die && curr->next != nullptr)                 
        curr = curr->next                                                 ;                                                 
                                                                          
    if (curr->next != nullptr)                                            {                                           
        curr->next = to_die->next                                         ;                                         
        delete to_die                                                     ;}
                                                                          }