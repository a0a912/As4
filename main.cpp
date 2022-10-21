#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "RedBlackTree.h"

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
/*
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

statistics("file.txt"); */

cout << test_tree.remove(4) << endl;

}