/*给定一个字符串S用以描述一棵树，其中S只由大写字母和#组成，大写字母表示结点的名称、#表示树中的空结点。
已知S中的序列以先序存储的逻辑进行描述，现请你设计一个程序用以存储这棵树，并遍历输出树的中序遍历序列。*/
#include <iostream>
using namespace std;
char c;
int rd = 0; //节点下标
struct node{
    char value;
    int left, right;
}tree[100001];
void traverse_first(int root){ //先序遍历
    if(root != 0){
        cout << tree[root].value << " ";
        traverse_first(tree[root].left);
        traverse_first(tree[root].right);
    }
}
void traverse_mid(int root){ //中序遍历
    if(root != 0){
        traverse_mid(tree[root].left);
        cout << tree[root].value << " ";
        traverse_mid(tree[root].right);
    }
}
void traverse_last(int root){ //后序遍历
    if(root != 0){
        traverse_last(tree[root].left);
        traverse_last(tree[root].right);
        cout << tree[root].value << " ";
    }
}
int build_tree(int root){ //建树
    cin >> c;
    if(c != '#'){ //若非空
        rd++;
        root = rd;
        tree[root].value = c;
        tree[root].left = build_tree(root);
        tree[root].right = build_tree(root);
    }
    else root = 0;
    return root;
}
int main(){
    int root = build_tree(0); //根节点下标
    // traverse_first(root);
    // cout << endl;
    // traverse_mid(root);
    // cout << endl;
    // traverse_last(root);
    // cout << endl;
    return 0;
}