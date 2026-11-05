#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *llink;
    nodeType *rlink;
};

void insertBST(nodeType* &root, int item)
{
    nodeType *newNode = new nodeType;
    newNode->info = item;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    nodeType *current = root;
    nodeType *trailCurrent = NULL;

    while (current != NULL)
    {
        trailCurrent = current;
        if (current->info == item)
        {
            cout << item << " is already in the tree" << endl;
            delete newNode;
            return;
        }
        else if (current->info > item)
        {
            current = current->llink;
        }
        else
        {
            current = current->rlink;
        }
    }

    if (trailCurrent->info > item)
    {
        trailCurrent->llink = newNode;
    }
    else
    {
        trailCurrent->rlink = newNode;
    }
}

bool searchBST(nodeType *root, int item)
{
    nodeType *current = root;
    while (current != NULL)
    {
        if (current->info == item)
            return true;
        else if (current->info > item)
            current = current->llink;
        else
            current = current->rlink;
    }
    return false;
}

void inorderHelp(nodeType *p)
{
    if (p != NULL)
    {
        inorderHelp(p->llink);
        cout << " " << p->info;
        inorderHelp(p->rlink);
    }
}

void printInorder(nodeType *root)
{
    cout << "Inorder:";
    inorderHelp(root);
    cout << endl;
}

void preorderHelp(nodeType *p)
{
    if (p != NULL)
    {
        cout << " " << p->info;
        preorderHelp(p->llink);
        preorderHelp(p->rlink);
    }
}

void printPreorder(nodeType *root)
{
    cout << "Preorder:";
    preorderHelp(root);
    cout << endl;
}

void freeTree(nodeType* &root)
{
    if (root != NULL)
    {
        freeTree(root->llink);
        freeTree(root->rlink);
        delete root;
        root = NULL;
    }
}

void deleteBST(nodeType* &root, int item)
{
    nodeType *current = root;
    nodeType *trailCurrent = NULL;

    while (current != NULL && current->info != item)
    {
        trailCurrent = current;
        if (current->info > item)
            current = current->llink;
        else
            current = current->rlink;
    }

    if (current == NULL)
    {
        cout << item << " is not in the tree" << endl;
        return;
    }

    if (current->llink == NULL && current->rlink == NULL)
    {
        if (current == root)
        {
            root = NULL;
        }
        else if (trailCurrent->llink == current)
        {
            trailCurrent->llink = NULL;
        }
        else
        {
            trailCurrent->rlink = NULL;
        }
        delete current;
    }
    else if (current->llink == NULL)
    {
        if (current == root)
        {
            root = current->rlink;
        }
        else if (trailCurrent->llink == current)
        {
            trailCurrent->llink = current->rlink;
        }
        else
        {
            trailCurrent->rlink = current->rlink;
        }
        delete current;
    }
    else if (current->rlink == NULL)
    {
        if (current == root)
        {
            root = current->llink;
        }
        else if (trailCurrent->llink == current)
        {
            trailCurrent->llink = current->llink;
        }
        else
        {
            trailCurrent->rlink = current->llink;
        }
        delete current;
    }
    else
    {
        nodeType *pred = current->llink;
        nodeType *predTrail = current;

        while (pred->rlink != NULL)
        {
            predTrail = pred;
            pred = pred->rlink;
        }

        current->info = pred->info;

        if (predTrail == current)
        {
            predTrail->llink = pred->llink;
        }
        else
        {
            predTrail->rlink = pred->llink;
        }
        delete pred;
    }
}

int main()
{
    cout << "Part 1" << endl;
    nodeType *root = NULL;

    int keys1[] = {60, 50, 70, 30, 58, 80, 46, 77};
    for (int i = 0; i < 8; i++)
    {
        insertBST(root, keys1[i]);
    }

    printInorder(root);
    printPreorder(root);

    insertBST(root, 46);

    int searchKeys[] = {58, 77, 65};
    for (int i = 0; i < 3; i++)
    {
        if (searchBST(root, searchKeys[i]))
            cout << searchKeys[i] << " found in the tree" << endl;
        else
            cout << searchKeys[i] << " not found in the tree" << endl;
    }

    freeTree(root);

    cout << endl;

}

