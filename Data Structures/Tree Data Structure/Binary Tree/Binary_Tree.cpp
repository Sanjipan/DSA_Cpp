#include <iostream>
#define SPACE 10

using namespace std;

class TreeNode

{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value Inserted as root node!" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value Already exist,"
                         << "Insert another value!" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value Inserted to the left!" << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the right!" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    TreeNode *insertRecursive(TreeNode *r, TreeNode *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            cout << "Insertion successful" << endl;
            return r;
        }

        if (new_node->value < r->value)
        {
            r->left = insertRecursive(r->left, new_node);
        }
        else if (new_node->value > r->value)
        {
            r->right = insertRecursive(r->right, new_node);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }
        return r;
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
            return;
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->value << "\n";
        print2D(r->left, space);
    }

    void printPreorder(TreeNode *r)
    {
        if (r == NULL)
            return;

        cout << r->value << " ";

        printPreorder(r->left);

        printPreorder(r->right);
    }

    void printInorder(TreeNode *r)
    {
        if (r == NULL)
            return;

        printInorder(r->left);

        cout << r->value << " ";

        printInorder(r->right);
    }
    void printPostorder(TreeNode *r)
    {
        if (r == NULL)
            return;

        printPostorder(r->left);

        printPostorder(r->right);

        cout << r->value << " ";
    }

    TreeNode *iterativeSearch(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    return temp;
                }
                else if (v < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
            return r;

        else if (val < r->value)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }

    int height(TreeNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {

            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value << " ";
        else
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }

/////////////////BFS

    void printLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;

        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, int v)
    {

        if (r == NULL)
        {
            return NULL;
        }

        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }

        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }

        else
        {

            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minValueNode(r->right);

                r->value = temp->value;

                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }
    // Q1
    // Ans:
    void findNode(TreeNode*root,int level ,int &maxLevel ,int &res)
    {
        if(root != NULL)
        {
            findNode(root->left, ++level, maxLevel, res);
            if(level>maxLevel)
            {
                res = root->value;
                maxLevel = level;
            }
            findNode(root->right, level, maxLevel, res);
        }
    }
    int deepestNode(TreeNode*root)
    {
        int res = -1;
        int maxLevel = -1;
        findNode(root,0,maxLevel,res);
        return res;
    }
    // Q2
    // Ans:
    int addBT(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return(root->value + addBT(root->left)+ addBT(root->right));
    }
    // Q3
    // Ans:
    int getLeafCount(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return getLeafCount(root->left) + getLeafCount(root->right);
        }
    }


};

int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "7. Q1 Ans : Deepest element" << endl;
        cout << "8. Q2 Ans : Sum of all elements" << endl;
        cout << "9. Q3 Ans : No. of leaf Nodes" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insertRecursive(obj.root, new_node);

            cout << endl;
            break;

        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
            cin >> val;

            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout << endl;

            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        case 7:
            int c;
            c = obj.deepestNode(obj.root);
            cout<<c<<endl;
            break;
        case 8:
            int b;
            b = obj.addBT(obj.root);
            cout<<b<<endl;
            break;
        case 9:
            int d;
            d = obj.getLeafCount(obj.root);
            cout<<d<<endl;
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}