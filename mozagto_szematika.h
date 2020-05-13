// TODO Bátfai Norbert GNU GPL v3

/*
  
Version history

 z3a17
 
 https://www.twitch.tv/videos/569832719
 https://youtu.be/_mu54BDkqiQ
 
 z3a18
 
 https://www.twitch.tv/videos/570721110
 https://youtu.be/QBD3zh5OJ0Y
 
 z3a18qa
 
 https://www.twitch.tv/videos/578167025
 https://youtu.be/fvKYgMnu1z4
 
 z3a18qa2
 
 https://www.twitch.tv/videos/578115999
 https://youtu.be/qoVNeSoHwXw

 z3a18qa3
 
 https://www.twitch.tv/videos/578390753
 https://youtu.be/3Dn4EC7NVDw
 
 z3a18qa4
 
 https://www.twitch.tv/videos/579709757
 https://youtu.be/q1ZlpkrhcqI
 
 z3a18qa4
 
 https://www.twitch.tv/videos/579916908
 https://youtu.be/ch_TJKOVWNo
 
 */


#include <iostream>
#include <random>
#include <functional>
#include <chrono>

class Unirand {

    private:
        std::function <int()> random;

    public:
        Unirand(long seed, int min, int max): random(
            std::bind(
                std::uniform_int_distribution<>(min, max),
                std::default_random_engine(seed) 
            )
        ){}    

   int operator()(){return random();}
        
};

template <typename ValueType>
class BinRandTree {

protected:
    class Node {
        
    private:
        ValueType value;
        Node *left;
        Node *right;
        int count{0};
        
        // TODO rule of five
        Node(const Node &);
        Node & operator=(const Node &);
        Node(Node &&);
        Node & operator=(Node &&);
        
    public:
        Node(ValueType value, int count=0): value(value), count(count), left(nullptr), right(nullptr) {}
        ValueType getValue() const {return value;}
        Node * leftChild() const {return left;}
        Node * rightChild() const {return right;}
        void leftChild(Node * node){left = node;}
        void rightChild(Node * node){right = node;}
        int getCount() const {return count;}
        void incCount(){++count;}        
    };

    Node *root;
    Node *treep;    
    int depth{0};
    
private:     
    // TODO rule of five
    
public:
    BinRandTree(Node *root = nullptr, Node *treep = nullptr): root(root), treep(treep) {
//        std::cout << "BT ctor" << std::endl;        
    }
    
    BinRandTree(const BinRandTree & old) {
  //      std::cout << "BT copy ctor" << std::endl;
        
        root = cp(old.root, old.treep);
        
        eval();
        
    }
    
    Node * cp(Node *node, Node *treep) 
    {
        Node * newNode = nullptr;
        
        if(node)
        {
            newNode = new Node(node->getValue(), 42 /*node->getCount()*/);
            
            newNode->leftChild(cp(node->leftChild(), treep));            
            newNode->rightChild(cp(node->rightChild(), treep));
            
            if(node == treep)
                this->treep = newNode;
        }
        
        return newNode;
    }
    
    
    BinRandTree & operator=(const BinRandTree & old) {
        std::cout << "BT copy assign" << std::endl;
        
        BinRandTree tmp{old};
        std::swap(*this, tmp);
        return *this;
    }
    
    BinRandTree(BinRandTree && old) {
        std::cout << "BT move ctor" << std::endl;
        
        root = nullptr;
        *this = std::move(old);
    }
       
    BinRandTree & operator=(BinRandTree && old) {
        std::cout << "BT move assign" << std::endl;
        
        std::swap(old.root, root);
        std::swap(old.treep, treep);
        
        return *this;
    }
    
    ~BinRandTree(){
    //    std::cout << "BT dtor" << std::endl;
        deltree(root);
    }
    BinRandTree & operator<<(ValueType value);
    void print(){print(root, std::cout);}
    void printr(){print(*root, std::cout);}
    void print(Node *node, std::ostream & os);
    void print(const Node &cnode, std::ostream & os);
    void deltree(Node *node); 

    void eval() {rmean(); rvar();}    
    
    double mean;
    int msum;    
    int mcount;        
    double getMean() const {return mean;}
    void rmean() {

        msum = mcount = 0;    
        
        rmean(root);
        mean = (double) msum / (double) mcount;

        msum = mcount = 0;    
        
    }
    void rmean(Node *);
    
    
    double var;
    double vsum;    
    int vcount;    
    double getVar() const {return var;}
    void rvar() 
    {
        rmean();
        
        vsum = vcount = 0;    
        
        rvar(root);
        var = std::sqrt(vsum / (vcount-1));

        vsum = vcount = 0;    
        
    }
    void rvar(Node *);
    
    
    bool operator<(const BinRandTree & other) const { return getVar() < other.getVar();}
    
    
    Unirand ur{std::chrono::system_clock::now().time_since_epoch().count(), 0, 2};

    int whereToPut() {
        
            return ur();
    }
    
    
};


template <typename ValueType>
class BinSearchTree : public BinRandTree<ValueType> {

public:
    BinSearchTree() {}
    BinSearchTree & operator<<(ValueType value);
    
    
};

template <typename ValueType, ValueType vr, ValueType v0>
class ZLWTree : public BinRandTree<ValueType> {

public:
    ZLWTree(): BinRandTree<ValueType>(new typename BinRandTree<ValueType>::Node(vr)) {
        this->treep = this->root;
    }
    ZLWTree & operator<<(ValueType value);
    
    
};

template <typename ValueType>
BinRandTree<ValueType> & BinRandTree<ValueType>::operator<<(ValueType value)
{
    
    int rnd = whereToPut();
    
    if(!treep) {
       
        root = treep = new Node(value);
        
    } else if (treep->getValue() == value) {
        
        treep->incCount();
        
    } else if (!rnd) {
 
        treep = root;
        *this << value;
        
    } else if (rnd == 1) {
        
        if(!treep->leftChild()) {
            
            treep->leftChild(new Node(value));
            
        } else {
            
            treep = treep->leftChild();
            *this << value;
        }
        
    } else if (rnd == 2) {
        
        if(!treep->rightChild()) {
            
            treep->rightChild(new Node(value));
            
        } else {
            
            treep = treep->rightChild();
            *this << value;
        }
        
    }
        
    return *this;
}


template <typename ValueType>
BinSearchTree<ValueType> & BinSearchTree<ValueType>::operator<<(ValueType value)
{
    if(!this->treep) {
       
        this->root = this->treep = new typename BinRandTree<ValueType>::Node(value);
        
    } else if (this->treep->getValue() == value) {
        
        this->treep->incCount();
        
    } else if (this->treep->getValue() > value) {
        
        if(!this->treep->leftChild()) {
            
            this->treep->leftChild(new typename BinRandTree<ValueType>::Node(value));
            
        } else {
            
            this->treep = this->treep->leftChild();
            *this << value;
        }
        
    } else if (this->treep->getValue() < value) {
        
        if(!this->treep->rightChild()) {
            
            this->treep->rightChild(new typename BinRandTree<ValueType>::Node(value));
            
        } else {
            
            this->treep = this->treep->rightChild();
            *this << value;
        }
        
    }
    
    this->treep = this->root;
    
    return *this;
}


template <typename ValueType, ValueType vr, ValueType v0>
ZLWTree<ValueType, vr, v0> & ZLWTree<ValueType, vr, v0>::operator<<(ValueType value)
{
    
    if(value == v0) {
        
        if(!this->treep->leftChild()) {
            
            typename BinRandTree<ValueType>::Node * node = new typename BinRandTree<ValueType>::Node(value);
            this->treep->leftChild(node);
            this->treep = this->root;
            
        } else {
            
            this->treep = this->treep->leftChild(); 
        }
        
    } else {

        if(!this->treep->rightChild()) {
            
            typename BinRandTree<ValueType>::Node * node = new typename BinRandTree<ValueType>::Node(value);
            this->treep->rightChild(node);
            this->treep = this->root;
            
        } else {
            
            this->treep = this->treep->rightChild(); 
        }
        
    }
    
    return *this;
}


template <typename ValueType>
void BinRandTree<ValueType>::rmean(Node *node) 
{
    if(node)
    {
        ++depth;
        rmean(node->leftChild());
                
        rmean(node->rightChild());
        --depth;
        
        if(!node->leftChild() and !node->rightChild())
        {
            ++mcount;
            msum += depth;
        }
    }
    
}

template <typename ValueType>
void BinRandTree<ValueType>::rvar(Node *node) 
{
    if(node)
    {
        ++depth;
        rvar(node->leftChild());
                
        rvar(node->rightChild());
        --depth;
        
        if(!node->leftChild() and !node->rightChild())
        {
            ++vcount;
            vsum += (depth - mean) * (depth - mean);
        }
    }
    
}


template <typename ValueType>
void BinRandTree<ValueType>::print(Node *node, std::ostream & os) 
{
    if(node)
    {
        ++depth;
        print(node->leftChild(), os);
        
        for(int i{0}; i<depth; ++i)
            os << "---";            
        os << node->getValue() << " " << depth << " " << node->getCount() << std::endl;     
        
        print(node->rightChild(), os);
        --depth;
    }
    
}


template <typename ValueType>
void BinRandTree<ValueType>::print(const Node &node, std::ostream & os) 
{

        ++depth;
        
        if(node.leftChild())
            print(*node.leftChild(), os);
        
        for(int i{0}; i<depth; ++i)
            os << "---";            
        os << node.getValue() << " " << depth << " " << node.getCount() << std::endl;     
        
        if(node.rightChild())
            print(*node.rightChild(), os);
        
        --depth;
    
}


template <typename ValueType>
void BinRandTree<ValueType>::deltree(Node *node) 
{
    if(node)
    {
        deltree(node->leftChild());
        deltree(node->rightChild());
        
        delete node;
    }
    
}


BinRandTree<int> bar()
{    
    BinRandTree<int> bt;
    BinRandTree<int> bt2;

    Unirand r(0, 0, 1);
    
    bt << 0 << 0 << 0;
    bt2 << 1 << 1 << 1;
    bt.print();
    std::cout << " --- " << std::endl;
    bt2.print();
    
    
    return r()?bt:bt2;
}



BinRandTree<int> foo()
{    
    return BinRandTree<int>();
}


