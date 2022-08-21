#include<iostream>
using namespace std;

template<class t>
class BST
{
    private:
        /*----------Begin creating nodes----------*/
        struct node
        {
            t data;
            node* right;
            node* left;
            node() : right(NULL) , left(NULL){}
            node(t& v) : node(){data = v;}
        }* root;
        /*----------End of creating nodes----------*/
    public:
        BST() : root(NULL){}
        bool empty();
        void insert(t);
        void insert(node* , node*);
        t getMax();
        t getMax(node*);
        node* getMaxNode(node*);
        t getMin();
        t getMin(node*);
        node* getMinNode(node*);
        void remove(t);
        node* remove(node* , t);
        bool isThere(t);
        bool isThere(t , node*);
        void inorderShow();
        void inorderShow(node*);
        void preorderShow();
        void preorderShow(node*);
        void postorderShow();
        void postorderShow(node*);
};


template<class t>
bool BST<t>::empty()
{return root == NULL;}
/*----------Begin inserting nodes----------*/
template<class t>
void BST<t>::insert(t value)
{
    node* newnode = new node(value);
    if(empty())
        root = newnode;
    else
        insert(root , newnode);
}
template<class t>
void BST<t>::insert(node* r , node* newnode)
{
    if(newnode->data <= r->data)
    {
        if(!r->left) // = r->left == NULL
            r->left = newnode;
        else
            insert(r->left , newnode);
    }
    else
    {
        if(!r->right)
            r->right = newnode;
        else
            insert(r->right , newnode);
    }
}
/*----------End of inserting nodes----------*/
/*----------Begin of geting max node----------*/
template<class t>
t BST<t>::getMax()
{
    if(empty())
        return -1;
    else 
        getMax(root);

}
template<class t>
t BST<t>::getMax(node* r)
{
    if(!r->right)
        return r->data;
    else
        getMax(r->right);

}
template<class t>
typename BST<t>::node* BST<t>::getMaxNode(node* r)
{
    if(!r->right)
        return r;
    else
        getMax(r->right);

}
/*----------End of geting max node----------*/
/*----------Begin of geting min node----------*/
template<class t>
t BST<t>::getMin()
{
    if(empty())
        return -1;
    else
        getMin(root);

}
template<class t>
t BST<t>::getMin(node* r)
{
    if(!r->left)
        return r->data;
    else
        getMin(r->left);

}
template<class t>
typename BST<t>::node* BST<t>::getMinNode(node* r)
{
    if(!r->left)
        return r;
    else
        getMin(r->left);

}
/*----------End of geting min node----------*/
/*----------begin of deleting node----------*/
template<class t>
void BST<t>::remove(t target)
{
    if(empty())
        {cout <<"Empty tree\n";return;}
    else
        remove(root , target);
}
template<class t>
typename BST<t>::node* BST<t>::remove(node* r, t target)
{
    if(r == NULL)
        {cout << "There's no Node with that value\n";return r;}
    else if(target > r->data)
        r->right = remove(r->right , target);
    else if (target < r->data)
        r->left = remove(r->left , target);
    else
    {
        if(!r->right && !r->left)
            r = NULL;
        else if(!r->right || !r->left)
        {
            t d;
            if(!r->right)
                {d = r->left->data;remove(r , r->left->data);r->data = d;}
            else
                {d = r->right->data;remove(r , r->right->data);r->data =d;}
        }
        else
        {
            node* temp = getMaxNode(r->left);
            t d = temp->data;
            remove(r , temp->data);
            r->data = d;
        }   
    }
    return r;
}

/*----------End of deleting node----------*/
/*----------begin of checking existence node----------*/
template<class t>
bool BST<t>::isThere(t target)
{
    if(empty())
        {cout << "Empty tree\n";return false;}
    isThere(target , root);
}
template<class t>
bool BST<t>::isThere(t target , node*r)
{
    if(!r)
        return 0;
    else if(target == r->data)
        return true;
    else if(target > r->data)
        isThere(target , r->right);
    else
        isThere(target , r->left);
}
/*----------End of checking existence node----------*/
/*----------Displaying----------*/
/*----------begin of showing elements(inorder)----------*/
template<class t>
void BST<t>::inorderShow()
{
    if(empty())
        {cout << "No elements in the tree\n";return;}
    else
        inorderShow(root);
}
template<class t>
void BST<t>::inorderShow(node* r)
{
    if(!r)
        return;
    inorderShow(r->left);
    cout << r->data << '\t';
    inorderShow(r->right);

}
/*----------end of showing elements(inorder)----------*/
/*----------begin of showing elements(preorder)----------*/
template<class t>
void BST<t>::preorderShow()
{
    if(empty())
        {cout << "No elements in the tree\n";return;}
    else
        preorderShow(root);
}
template<class t>
void BST<t>::preorderShow(node* r)
{
    if(!r)
        return;
    cout << r->data << '\t';
    preorderShow(r->left);
    preorderShow(r->right);

}
/*----------end of showing elements(preorder)----------*/
/*----------begin of showing elements(postorder)----------*/
template<class t>
void BST<t>::postorderShow()
{
    if(empty())
        {cout << "No elements in the tree\n";return;}
    else
        postorderShow(root);
}
/*----------End displaying----------*/
template<class t>
void BST<t>::postorderShow(node* r)
{
    if(!r)
        return;
    postorderShow(r->left);
    postorderShow(r->right);
    cout << r->data << '\t';
}
/*----------end of showing elements(postorder)----------*/

int main()
{
    BST<int>btree;
	btree.insert(45);
	btree.insert(15);
	btree.insert(79);
	btree.insert(90);
	btree.insert(10);
	btree.insert(55);
	btree.insert(12);
	btree.insert(20);
	btree.insert(50);
    cout << " Display the Tree Contenet \n";
	btree.preorderShow();
	cout << " \n Delete Items \n ";
	btree.remove(12);
	cout << "\n preorder After Delete 12 \n ";
	btree.preorderShow();

	btree.remove(15);
	cout << "\n preorder After Delete 15 \n ";
	btree.preorderShow();


    return 0;
}