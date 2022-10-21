#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
NodeT<Q> Class

As part of the red black tree implementation you should implement a NodeT<Q> class. Your NodeT<Q> class must be written in your RedBlackTree<Q>.h file, above and outside the RedBlackTree<Q> class definition. Your NodeT<Q> constructors should be written in the NodeT<Q> class definition, and not in a separate NodeT<Q>.cpp file. Like your RedBlackTree<Q> the NodeT<Q> class must also be a template class with a template variable that represents the node's data.

Nodes should contain the following attributes, which must all be made public, and must be given the names set out below

    data - a template type parameter
    left – NodeT<Q> poTer to the left child
    right – NodeT<Q> poTer to the right child
    parent – NodeT<Q> poTer to the parent
    isBlack – the colour of the node, either black or red but represented as a bool that is true if the node is black

And these methods:

    Constructor - sets the data to its template type parameter, poTers to null, and isBlack to false
    You may create other constructors if you wish

*/

template <class Q>
class NodeT
{
public:
Q data;
NodeT<Q>* left;
NodeT<Q>* right;
NodeT<Q>* parent;

bool isBlack;
NodeT();
NodeT(Q value) : data(value), left(nullptr), right(nullptr), parent(nullptr), isBlack(false) {};

};

template <class Q>
NodeT<Q>::NodeT(){

}

template <class Q>
class RedBlackTree{

  public:

int amount;
vector<Q>  contents;

void leftrotate(NodeT<Q>* ndx);
void rightrotate(NodeT<Q>* ndx);

void postorderprint(NodeT<Q>* nd);
void preorderprint(NodeT<Q>* nd);
void in_order_print(NodeT<Q>* nd);

NodeT<Q>* insert_helper(Q value);
NodeT<Q> search_helper(Q value);

void rbfix(NodeT<Q>* x);

NodeT<Q>* root;
  RedBlackTree<Q>();
  ~RedBlackTree<Q>();
  RedBlackTree<Q>(const RedBlackTree<Q> & rbt);
  RedBlackTree<Q> & operator=(const RedBlackTree<Q> & rbt);

  bool insert(Q value);
  bool remove(Q value);
  bool search (Q value);
  vector<Q> search(Q value_a, Q value_b);
Q closestLess ( Q value);
Q closestGreater (Q value);
vector<Q>  values();

 int size();

 NodeT<Q>* copy_help( NodeT<Q>*, NodeT<Q>*);

 void in_order_count(NodeT<Q>* nd);

 void in_order_vector(NodeT<Q>* nd);

 void clear();
 void clear(NodeT<Q>* nd);

 void insert_temp(Q value);

 void remove_temp (Q value);

 template <class T>
 friend NodeT<T>* JWMEgetRoot(const RedBlackTree<Q> & rbt);



};

template <class Q>
NodeT<Q>* RedBlackTree<Q>::copy_help(NodeT<Q>* node, NodeT<Q>* parent){

  if (node == nullptr){
    return nullptr;
  }
  
  NodeT<Q>* new_node = new NodeT<Q>(node->data);
  new_node->parent = parent;
  new_node->isBlack = node->isBlack;
  new_node->left = copy_help(node->left, new_node);
  new_node->right = copy_help(node->right, new_node);
  
return new_node;
}

template <class Q>
RedBlackTree<Q>::RedBlackTree()
{
  root = nullptr;
}

template <class Q>
RedBlackTree<Q>::~RedBlackTree(){
  	clear();
}
 //FROM : rbt, T0 :this
template <class Q> 
RedBlackTree<Q>::RedBlackTree(const RedBlackTree<Q> & rbt){
cout<<"Copy constructor called";
if (rbt.root == nullptr){
  root = nullptr;
  return;
}

root = copy_help(rbt.root, nullptr);

}

template <class Q>
RedBlackTree<Q> & RedBlackTree<Q>::operator=(const RedBlackTree<Q> & rbt)
{
  this->clear();
  this->root = nullptr;

root = copy_help(rbt.root, nullptr);

return* this;

}

/*
BST::BST(const BST & bst)

{

                 this->root = nullptr;
   stack<NodeT<Q> *> new_stack;
NodeT<Q> *curr = bst.root;
  
while (curr != NULL || new_stack.empty() == false )
{
while (curr != NULL)
{
new_stack.push(curr);
curr = curr->left;
}
curr = new_stack.top();
new_stack.pop();
       this->insert(curr->data);
curr = curr->right;
}

}
*/
/*

// Insert value in tree maTaining bst property
// PRE:
// PARAM: value = value to be inserted
// POST: value is inserted, in order, in tree
void BST::insert(Q value)
{
	NodeT<Q>* newNode = new NodeT<Q>(value);
	NodeT<Q>* parent = root;
	NodeT<Q>* next = root;

	if (empty()) {
		root = newNode;
	}
	else { //non-empty
		   // Find parent of new node
		while (next != nullptr) {
			parent = next;
			if (value < parent->data) {
				next = parent->left;
			}
			else {
				next = parent->right;
			}
		}
		// Insert new node
		if (value < parent->data) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
}


*/


//front ->nxt1 -> nxt2...->n
//root -> left, right

/*
template<class Q> 
QueueT::QueueT(const QueueT* QT){
cout<<"Copy constructor called";
if (QT->size == 0){
    front = NULL;
    rear = NULL;
    size = 0;
    return;
    }
NodeT<Q> *temp = QT->front;
//Creating first node
NodeT<Q>* curr = new NodeT<Q> (temp->data);
front = curr;
size = 1;
while (size <= QT->size ){
      if (temp->next != NULL)
      {
          temp = temp->next;
      }
      NodeT<Q>* nn_node = new NodeT<Q> (temp->data);
      //Connecting prior node to new
      curr->next= nn_node;
      curr = nn_node;
      size++;
    }
rear = curr;
}
*/

template <class Q>
bool RedBlackTree<Q>::search(Q value){
NodeT<Q>* p = root;
        while (p != nullptr) {
                if (value == p->data) {
                        return true;
                }
                else if (value < p->data) {
                        p = p->left;
                }
                else {
                        p = p->right;
                }
        }
        return false;
}

template <class Q>
vector<Q>  RedBlackTree<Q>::search(Q value_a, Q value_b){
  Q bigger;
  Q smaller;

  vector<Q> search_results ;

  if (value_a > value_b){
    bigger = value_a;
    smaller = value_b;
  }
    else if (value_b > value_a){
      bigger = value_b;
      smaller = value_a;
    }

    else if (value_a == value_b){

      if (this->search(value_a) == true){
        search_results.push_back(value_a);
      }
      return search_results;
    }

while (smaller <= bigger){
  if (this->search(smaller) == true){
        search_results.push_back(smaller);
      }

      smaller++;
}

return search_results;
}

template <class Q>
void RedBlackTree<Q>::in_order_count(NodeT<Q> *nd){
  if (nd != nullptr) {

                amount++;
                in_order_count(nd->left);

               // amount++;

                in_order_count(nd->right);

                //amount++;

        }
}

template <class Q>
void RedBlackTree<Q>::in_order_print(NodeT<Q> *nd){
  if (nd != nullptr) {

                
                in_order_count(nd->left);
                cout << nd->data << endl;

               // amount++;

                in_order_count(nd->right);
                cout << nd->data << endl;


                //amount++;

        }
}

template <class Q>
int RedBlackTree<Q>::size(){
  amount = 0;

  in_order_count(root);

  return amount;

}

template <class Q>
void RedBlackTree<Q>::in_order_vector(NodeT<Q> *nd){
  if (nd != nullptr) {

                in_order_vector(nd->left);

                contents.push_back(nd->data);

                in_order_vector(nd->right);

                //contents.push_back(nd->data);

        }
}

template <class Q>
vector<Q>  RedBlackTree<Q>::values(){

this->in_order_vector(root);

return contents;

}



template <class Q>
Q RedBlackTree<Q>::closestLess(Q value){
  vector<Q>  closest_value = this->values();
  Q temp = value;

  for (Q ii = 0; ii<closest_value.size();ii++) {
  
  if (closest_value[ii] < value){
    temp = closest_value[ii];
  }


}

return temp;
}

template <class Q>
Q RedBlackTree<Q>::closestGreater(Q value){
  vector<Q>  closest_value = this->values();
  Q temp;

  for (Q ii = 0; ii<closest_value.size();ii++) {
  
  if (closest_value[ii] > value){
    temp = closest_value[ii];

    return temp;
  }


}

return temp;
}

template <class Q>
void RedBlackTree<Q>::clear()
{
	clear(root);
	root = nullptr;
}


template <class Q>
void RedBlackTree<Q>::clear(NodeT<Q>* nd)
{
	if (nd != nullptr) {
		clear(nd->left);
		clear(nd->right);
		delete nd;
	}
}

template <class Q>
void RedBlackTree<Q>::insert_temp(Q value)

{NodeT<Q>* newNode = new NodeT<Q>(value);

//Tweaking this for real insert;
newNode->isBlack = false;

        NodeT<Q>* parent = root;

        NodeT<Q>* next = root;

        if (root == nullptr) {

                root = newNode;

        }

        else { //non-empty

                   // Find parent of new node

                while (next != nullptr) {

                        parent = next;

                        if (value < parent->data) {

                                next = parent->left;

                        }

                        else {

                                next = parent->right;

                        }

                }

                // Insert new node

                if (value < parent->data) {

                        parent->left = newNode;

                }

                else {

                        parent->right = newNode;

                }

        }

}

template <class Q>
void RedBlackTree<Q>::leftrotate(NodeT<Q> * ndx){


NodeT<Q>* tempy = ndx->right;

if (tempy != nullptr)
{
  ndx->right = tempy->left;

}



// Set nodes’ parent references // y’s left child
if (tempy->left != nullptr)
{
  tempy->left->parent = ndx;
 
}

tempy->parent = ndx->parent;

// Set child reference of x’s parent 

if (ndx->parent == nullptr) //x was root
{
root = tempy;

}
else if (ndx == ndx->parent->left) //left child
{
ndx->parent->left = tempy;

}
else{
ndx->parent->right = tempy;

}
// Make x y’s left child 
tempy->left = ndx;
ndx->parent = tempy;

}

template <class Q>
void RedBlackTree<Q>::rightrotate(NodeT<Q> * ndx){


NodeT<Q>* tempy = ndx->left;

ndx->left = tempy->right;

// Set nodes’ parent references // y’s left child
if (tempy->right != nullptr)
{
  tempy->left->parent = ndx;
}

tempy->parent = ndx->parent;

// Set child reference of x’s parent 

if (ndx->parent == nullptr) //x was root
{
root = tempy;
}
else if (ndx == ndx->parent->right) //left child
{
ndx->parent->right = tempy;
}
else{
ndx->parent->left = tempy;
}
// Make x y’s left child 
tempy->right = ndx;
ndx->parent = tempy;
}

template <class Q>
void RedBlackTree<Q>::postorderprint(NodeT<Q> *nd)
{
  if (nd != nullptr){
  postorderprint(nd->left);
  postorderprint(nd->right);

  cout << "data = " << nd->data << endl;
}
}

template <class Q>
void RedBlackTree<Q>::preorderprint(NodeT<Q> *nd)
{
  if (nd != nullptr){

    cout << "data = " << nd->data << endl;
  preorderprint(nd->left);
  preorderprint(nd->right);

}
}


template <class Q>
bool RedBlackTree<Q>::insert(Q value)

{

  if (this->root == nullptr)
  {
      
    //this->insert_temp(value);
    //is this correct?
    //insert_temp(value);
root = new NodeT<Q>();
root->data = value;
root->left = nullptr;
root->right = nullptr;
root->parent = nullptr;
    root->isBlack = true;
    return true;
  }


  if (this->search(value) == true){
   
    return false;
  }
  
NodeT<Q> * y;

cout << "Value "<< value <<endl;
NodeT<Q> *x = insert_helper(value);
cout << "pdata "<< x->parent->data <<endl; 

//check if x is nullptr
 x->isBlack = false;


  cout <<((x->data));
  cout << (x->parent ==nullptr) << endl;

  while (x->data != this->root->data && x->parent->isBlack == false)

  {
      
  if (x->parent == x->parent->parent->left){
    NodeT<Q> * y = x->parent->parent->right; //x’s “uncle” 
  
  
    if (y->isBlack == false) //like x.p
      {
       
       
       x->parent->isBlack = true; 
       y->isBlack = true; 
        x->parent->parent->isBlack = false;
        x = x->parent->parent;
      }
  else //y.colour == black 
  { 
      
    if (x == x->parent->right)
    {
      x = x->parent;
      leftrotate(x); 

     
     
    }
  x->parent->isBlack = true;
  x->parent->parent->isBlack = false; 
  rightrotate(x->parent->parent);

 
 
  }
  }
  else 
  {
    y = x->parent->parent->left; //x’s “uncle”
   
   
    if (y->isBlack == false) //like x.p 
    {
        x->parent->isBlack = true;
        y->isBlack = true;
        x->parent->parent->isBlack = false;
        x = x->parent->parent;
  }
        else //y.colour == black 

        {
            
            if (x == x->parent->left)
            {
                
              x = x->parent;
              rightrotate(x);
            }


            x->parent->isBlack = true; 
            x->parent->parent->isBlack = false;
             leftrotate(x->parent->parent);
        }
  }
  }
root->isBlack = true;

  return true;
}


template <class Q>
NodeT<Q>* RedBlackTree<Q>::insert_helper(Q value)
{

NodeT<Q>* newNode = new NodeT<Q>(value);
//Tweaking this for real insert;
newNode->isBlack = false;
        NodeT<Q>* parent = root;
        NodeT<Q>* next = root;
        if (root == nullptr) {

                root = newNode;
        }
        else { //non-empty
                   // Find parent of new node

                while (next != nullptr) {
                        parent = next;
                        if (value < parent->data) {

                                next = parent->left;
                        }
                        else {

                                next = parent->right;
                        }
                }
                // Insert new node
                if (value < parent->data) {

						//cout << "Pdata Value:"<<parent->data<<endl;
						//cout << "Its :"<< newNode->data<<endl;
                        parent->left = newNode;
						newNode->parent = parent;
						//cout << "parentDataLeft "<<parent->left->data<<endl;
                        return newNode;
                }
                else {

                        parent->right = newNode;
						newNode->parent = parent;
                        return newNode;
                }

        }
return newNode;
}

template <class Q>
  bool RedBlackTree<Q>::remove(Q value)
  {
      if (this->root == nullptr)
  {

    return false;
  }


  if (this->search(value) == true){
   
    return true;
  }
  
  return false;
  }
  
  
  void statistics(string filename) {
      ifstream file (filename);
      
      string line;
      vector<double> container;
      
      RedBlackTree<double> stat_tree;
      
      if (file.is_open())
  {
    while ( getline (file,line) )
    {
      container.push_back(stod(line));
      
      stat_tree.insert_temp(stod(line));
    }
    file.close();
  }
  
  else cout << "Unable to open file" << endl; 
  double sum = 0;
  
  for (int i = 0; i < stat_tree.size();i++){
    sum = sum + container[i];
    
  }
  
  cout << "Number of Values = " << stat_tree.size() << endl;
  cout << "average = " << sum/stat_tree.size() << endl;
  cout << "Median = " << container[ceil(stat_tree.size()/2)]<< endl;
  cout << "closest < 42: = " << stat_tree.closestLess(42)<< endl;
  cout << "closest < 42: = " << stat_tree.closestGreater(42)<< endl;
  
  

  
  
  
  
  
  }

/*
void RedBlackTree<Q>:: rbfix(NodeT<Q> *x){

  while (x->data != this->root->data and x->isBlack == true)
  {
    if (x == x->parent->left) //x is left child
    {
      NodeT<Q>* y = x->parent->right; //x’s sibling

      if (y-> isBlack == false)
      {
        y-> isBlack = true;
        x->parent->isBlack = false; //x’s parent must have been black since y is red
        leftrotate(x->parent);
        y = x->parent->right;
      }
      if (y->left->isBlack == true && y->right->isBlack == true)
      {
        y->isBlack = false;
        x = x->parent; //and To while again ...
      }
      else 
      {
        if (y->right->isBlack == true)
        {
            y->left->isBlack = true ;
            y->isBlack = false ;
            rightrotate(y);
            y = x->parent->right;
        }

        y->isBlack = x->parent->isBlack;
        x->parent->isBlack = true;
        y->right->isBlack = true;
        leftrotate(x->parent);
        x = root;
      }
    }
    else
    {
      //symmetric to if
    }
  }

  x->isBlack = true;
}


NodeT<Q> RedBlackTree<Q>::search_helper(Q value){
NodeT<Q>* p = root;
        while (p != nullptr) {
                if (value == p->data) {
                        return p;
                }
                else if (value < p->data) {
                        p = p->left;
                }
                else {
                        p = p->right;
                }
        }
        return false;
}



Q RedBlackTree<Q>::remove(Q value)

{
  if (this->search(value) == true){
    return false;
  }

  NodeT<Q>* z = search_helper(value);

  NodeT<Q>* y;
  if (z->left == nullptr || z->right == nullptr)
  {
      y = z //node to be removed else

  }
  else
  {
  y = z->parent; //or successor 



  if (y->left != nullptr)
  {
    x = y->left;
  }
  else
  {
    x = y->right;
  }
  x->parent = y->parent; //detach x from y; if not null 
  if (y->parent == nullptr) //y is the root
  {
    root = x;
  }
  else
  {
    // Attach x to y’s parent
    if (y == y->parent->left) //left child
    {
      y->parent->left = x;
    }
    else
    {
      y->parent->right = x;
    }
  }
  if (y != z) //i.e. y moved up
  {
    z->data = y->data; //replace z with y 
  }
  if (y->isBlack == true)
  {
    rbFix(x) ;//note that x could be null
  }


}
return true;
}
*/
/*
int main(){


cout << "hello world" << endl;

RedBlackTree<int> test_tree;

test_tree.insert_temp(5);

test_tree.insert_temp(4);

test_tree.insert_temp(6);

test_tree.insert_temp(10);


RedBlackTree<int> test_tree_2;
cout << "setting up tree" << endl;
test_tree_2.insert(5);

cout << "Inserted 5" << endl;
test_tree_2.insert(4);
cout << "Inserted 4" << endl;
test_tree_2.insert(6);
cout << "Inserted 6" << endl;
test_tree_2.insert(10);
cout << "Inserted 10" << endl;
//   5
// 4   6
//       10
//
 //test_tree.~RedBlackTree() ;

cout << "size = " << test_tree.size() << endl;
cout << "search = " << test_tree.search(4) << endl;
vector<int> ans = test_tree.search(5, 10);
cout << "vector<Q> search = " <<  endl;
for (int i = 0; i < ans.size();i++)
    cout<<" " << ans[i];

int ans2 = test_tree.closestLess(6);
cout << "Closest Less = " << ans2 <<  endl;


int ans3 = test_tree.closestGreater(5);
cout << "Closest Greater = " << ans3 <<  endl;


cout << "Testing postorderprint with tree 1" << endl;

test_tree.postorderprint(test_tree.root);

test_tree.leftrotate(test_tree.root->right);

cout << "Testing prT with tree 2" << endl;
test_tree_2.in_order_print(test_tree_2.root);


cout << "Testing postorderprint and left rotate with tree 1" << endl;

test_tree.postorderprint(test_tree.root);

statistics("file.txt");

}
*/
/*
You are to implement and test a red-black tree template class. 

Please read the requirements carefully, paying attention to the names and input and output requirements of the class and its methods. We will be testing your class in our test program, so if you do not follow the requirements the test program will not compile, and will not be marked. As usual refer to the General Requirements page - if you have not looked at it recently, look at it again as I may add to it.
Part 1 - Red Black Tree Class

Implement a red-black tree template class to store data of any (comparable) type. Your class must be named RedBlackTree<Q>.
Attributes

Your class must have a NodeT<Q>* attribute which represents the root of the tree which must be called root. Your class may have other attributes as you see fit, though the tree must be a reference structure as described in class.
Public Methods

Methods must preserve the red-black and binary search tree properties.

    default constructor – creates an empty tree whose root is a null poTer
    copy constructor – a constructor that creates a deep copy of its RedBlackTree<Q> reference parameter
    operator= – overloads the assignment operator for RedBlackTree<Q> objects – (deep) copies its RedBlackTree<Q> reference parameter To the calling object and returns a reference to the calling object after de-allocating any dynamic memory associated with the original contents of the calling object; if the calling object is the same as the parameter the operator should not copy it
    destructor – deletes dynamic memory allocated by the tree
    insert – if the tree does not contain the method's single template parameter, inserts the parameter and returns true; otherwise does not insert the parameter and returns false; i.e. the tree will never contain duplicate values
    remove – removes the method's template parameter from the tree and returns true; if the tree does not contain the parameter returns false
    search – searches the tree for the method's single template parameter and returns true if it is found and false otherwise
    search – returns a vector<Q> that contains all of the values between the method's first and second template parameters, including both parameter values if they are in the tree; the contents of the returned vector<Q> are in ascending order; if there are no such values the returned vector<Q> should be empty; note that the order of the parameters is not important, so search(3, 17) and search(17,3) should return the same vector<Q>
    closestLess - returns the largest value stored in the tree that is less than the method's single template parameter; returns the value of the parameter if there is no such value; e.g. if the tree contains the values 3,5,9,12,17 then closestLess(10) returns 9, closestLess (17) returns 12 and closestLess(3) returns 3
    closestGreater - returns the smallest value stored in the tree that is greater than the method's single template parameter; returns the value of the parameter if there is no such value; e.g. if the tree contains the values 3,5,9,12,17 then closestGreater(10) returns 12, closestGreater(17) returns 17 and closestGreater(3) returns 5
    values– returns a vector<Q> that contains all of the values in the tree; the contents of the vector<Q> are in ascending order; if the tree is empty the returned vector<Q> should also be empty
    size – returns the number of values stored in the tree

Friend Function Declaration

In the public section of your RedBlackTree<Q> class definition you must include the friend function declaration shown below:

template <class Q>
friend NodeT<Q>* JWMEgetRoot(const RedBlackTree<Q> & rbt);

This is related to our testing. Other than including the declaration shown above you have no other responsibilities relating to this function - you should not attempt to define the function in your submission, or do anything with it whatsoever except what is described above.
NodeT<Q> Class

As part of the red black tree implementation you should implement a NodeT<Q> class. Your NodeT<Q> class must be written in your RedBlackTree<Q>.h file, above and outside the RedBlackTree<Q> class definition. Your NodeT<Q> constructors should be written in the NodeT<Q> class definition, and not in a separate NodeT<Q>.cpp file. Like your RedBlackTree<Q> the NodeT<Q> class must also be a template class with a template variable that represents the node's data.

Nodes should contain the following attributes, which must all be made public, and must be given the names set out below

    data - a template type parameter
    left – NodeT<Q> poTer to the left child
    right – NodeT<Q> poTer to the right child
    parent – NodeT<Q> poTer to the parent
    isBlack – the colour of the node, either black or red but represented as a bool that is true if the node is black

And these methods:

    Constructor - sets the data to its template type parameter, poTers to null, and isBlack to false
    You may create other constructors if you wish

File Structure

Template classes are often contained in a single .h file as there are compilation issues with breaking them down To separate files, and this is what I want you to do for this assignment. I still want you to keep the implementation separate from the Terface as much as possible within this structure, so your method implementations should appear below your RedBlackTree<Q> class definition. Your .h file will therefore have this general structure.

//include statements
// template declaration
class NodeT<Q>{
   //… includes constructor definitions …
};

// template declaration
class RedBlackTree<Q>{
   //…
   template <class Q> 
   friend NodeT<Q>* JWMEgetRoot(const RedBlackTree<Q> & rbt);
   //…
};

// RedBlackTree<Q> method implementations
// template declaration
RedBlackTree<Q>::RedBlackTree<Q>()
{
   //…
}
//…

Additional Notes

    Your RedBlackTree<Q> class should be implemented as discussed in class
    Calling objects and parameters should be made constant when appropriate
    Helper methods and attributes of the tree should be made private
    The RedBlackTree<Q> class must have a NodeT<Q> poTer attribute for the root of the tree, and an Teger attribute that records the size, you may add other attributes as you see fit
    Method parameters and return values are noted (and highlighted) in the method descriptions – you must not add additional parameters to the methods; if the method description does not mention a parameter it does not have one, similarly if no return value is mentioned the method is void (or a constructor or destructor)
    Parameter types of some methods, and the type of returned vector<Q>s should be your template variables
    If you are unable to complete a method comment it out and return a default value – i.e. create a stub function

HTs

    As usual write, and test, one (or two) functions at a time
    For complex methods (such as the insert and remove algorithms) I would suggest writing and testing one or two cases at a time, attempting to write the entire remove method before testing it is likely to result in considerable pain and misery
    Write your NodeT<Q> and RedBlackTree<Q> classes as regular (non-template) classes that store base typed data (like Tegers and characters) first, test them thoroughly and only then convert them To template classes
    If your insert method does not work we cannot test your class; if you are unable to implement the red-black tree insert algorithm you can still write a bst insert algorithm that will allow us to test your search methods

Part 2 - Statistics Function

Write a function - not a method of your RedBlackTree<Q> - with the following prototype:

void statistics(string filename)

Functionality

The function should:

    Open a file whose name is stored in the function's parameter
    Read the contents of the file To a RedBlackTree<Q><double> object
    PrT the following:
        The number of unique values in the file
        The average of the unique values in the file
        The median of the unique values in the file (if there are an even number of values the median is the average of the two central values)
        The  two closest values less and greater than the value 42.0

Your prT statement should be formatted such that it is obvious what is being prTed. For example:

# of values:  xx
average:      xxx.xx
median:       xx.xx
closest < 42: xx.x
closest > 42: xx.xxx

Feel free to make it prettier than the above. You should not format the output to any particular number of decimal places.

Input File Format

The input file should contain floating poT numbers, with one number per line.

2.71828
3.14159
42
7917.5
1.61803398875

Notes

    The function should declare and use a RedBlackTree<Q> object but should have no other connection with the class, specifically it should not be a method of the RedBlackTree<Q> class and should not be a friend of the class.
    The function does not need to handle any file errors including, but not limited to: non-existent files, un-openable files, files in the wrong format.
    You must use your RedBlackTree<Q> methods to compute these statistics - you may use the result of the values method to determine the average and median.
    You should include the <string> library (since the function has a string parameter).
    The function only needs to call some of your RedBlackTree<Q> methods. It is Tended to demonstrate your knowledge of how to use a template object (i.e. of the RedBlackTree<Q> class) not to test all its methods.
    If you are unable to complete the function write a stub for it.

File Structure

The function should be defined in your RedBlackTree<Q> (.h) file

*/