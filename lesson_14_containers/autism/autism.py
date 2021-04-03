import re

def f(s):
    spaces_in_tab = 4;
    strs = [i.rstrip().replace('\t',' '*spaces_in_tab) for i in s.split('\n')]
    max_len = max(map(len, strs)) + 5
    for i in range(len(strs)):
            s = strs[i]
            if (m := re.search('([;{}]*)$', s)):
                s = strs[i] = re.sub('([;{}]*)$', ' '*(max_len-len(s) + len(m.group())) + r'\1', s)
            offset = len(s) - len(s.lstrip())
            if (m := re.search('^[{};]+', s.strip())):
                if not re.search(r'(\/\/|\/\*)', strs[i-1]):
                    strs[i-1] = strs[i-1].rstrip() + ' '*(max_len-len(strs[i-1].rstrip())) + m.group()
                else:
                    strs[i-1] += '\n' + ' '*max_len + m.group()
                s = strs[i] = ' '*offset + re.sub('^[{};]+ *', '', s.strip())
                
    s = '\n'.join(strs)
    return s


s = '''#pragma once                                                  

template <typename Type>
class List {
public:
    struct Node {
        Type data;
        Node * next;
        Node(Type const & d): data(d), next(nullptr) {}
    };

    struct iterator {
        Node * _node;
        iterator(Node * node = nullptr): _node(node) {}
        Type & operator*() const {
            return _node->data;
        }

        bool operator==(iterator const & it) {
            return _node == it._node;
        }

        bool operator!=(iterator const & it) {
            return !(*this == it);
        }

        iterator & operator++() {
            _node = _node->next;
            return *this;
        }

        iterator operator++(int) {
            Node * tmp = _node;
            _node = _node->next;
            return iterator(tmp);
        }
    };

private:
    Node * _root;
    size_t _size;
public:
    List():_root(nullptr), _size(0) {}

    List(Type * data, size_t size) {
        ///TODO: implement                                    
    }

    List(List const & source) {
        ///TODO: implement                                    
    }

    List & operator=(List const & source) {
        ///TODO: implement                                    
    }

    void clear() {
        while (_root != nullptr) {
            Node * tmp = _root;
            _root = _root->next;
            delete tmp;
        }
        _size = 0;
    }
    ~List() {
        clear();
    }

    void push_back(Type const & val);
    void erase(iterator to_die_it);

    iterator begin() { return iterator(_root); }
    iterator end() { return iterator(); }

    //void push_back(Type const& val)                         ;                         
    //void insert(Type& const val, iterator it_after)         ;         
    //void resize(size_t new_size)                            ;                            

    //iterator find(Type& const to_find)                      ;                      
};

template <class Type>
void List<Type>::push_back(Type const & val) {
    if (_root == nullptr) {
        _root = new Node(val);
        _size = 1;
        return;
    }

    Node * curr = _root;
    while (curr->next != nullptr)
        curr = curr->next;
    Node * new_node = new Node(val);
    curr->next = new_node;
    ++_size;
}

template <class Type>
void List<Type>::erase(iterator to_die_it) {
    if (_root == nullptr)
        throw std::runtime_error("empty list");

    Node * to_die = to_die_it._node;
    Node * curr = _root;
    while (curr->next != to_die && curr->next != nullptr)
        curr = curr->next;

    if (curr->next != nullptr) {
        curr->next = to_die->next;
        delete to_die;
    }
}'''
print(f(s))
