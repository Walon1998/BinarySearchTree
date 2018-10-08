#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct BinarySearchTree {
    struct Node *root;
};


struct Node {
    float value;
    struct Node *leftchild;
    struct Node *rightchild;

};


insert(struct BinarySearchTree *tree, float value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;

    if (tree->root == NULL) {
        tree->root = newNode;

    } else {

        struct Node *currentNode = tree->root;

        while (1) {
            if (currentNode->value > value) {
                if (currentNode->leftchild == NULL) {
                    currentNode->leftchild = newNode;
                    break;
                }
                currentNode = currentNode->leftchild;
            } else if (currentNode->value < value) {
                if (currentNode->rightchild == NULL) {
                    currentNode->rightchild = newNode;
                    break;
                }
                currentNode = currentNode->rightchild;
            } else {
                // Key is already in tree
                break;
            }


        }


    }
}

lookup(struct BinarySearchTree tree, float value) {

    struct Node *currentNode = tree.root;

    while (1) {
        if (currentNode->value > value) {
            if (currentNode->leftchild == NULL) {
                printf("Tree does not contain: %g \n",value);
                //Not Found!
                return 0;

            }
            currentNode = currentNode->leftchild;
        } else if (currentNode->value < value) {
            if (currentNode->rightchild == NULL) {
                printf("Tree does not contain: %g\n ",value);
                return 0;
                //Not Found;
            }
            currentNode = currentNode->rightchild;
        } else {
            printf("Tree does contain: %g\n",value);
            return 1;
        }


    }

}

delete(struct BinarySearchTree *tree, float value ){
//   TODO

}


int main() {
    struct BinarySearchTree tree = {NULL};

    insert(&tree, 4);
    insert(&tree, 5);
    insert(&tree, 3);
    insert(&tree, 1);
    insert(&tree, 1);

    lookup(tree,1);
    lookup(tree,6);
    delete(&tree,10);




    return 0;
}