#include <iostream>
#include <queue>


class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

void preorderTraversal(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    
    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " ";
}

void levelOrderTraversal(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->data << " ";
        
        if(current->left != nullptr)
        {
            q.push(current->left);
        }

        if(current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

void printTreeStructure(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::cout << "         " << root->data << std::endl;
    std::cout << "        / \\" << std::endl;
    std::cout << "       " << root->left->data << "   " << root->right->data << std::endl;
    std::cout << "      / \\ / \\" << std::endl;
    std::cout << "     " << root->left->left->data << "  " << root->left->right->data << " " << root->right->left->data << "  " << root->right->right->data << std::endl;
}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    //left side
    root->left->left = new TreeNode(4);                                                             
    root->left->right = new TreeNode(5);

    //right side
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Tree Structure:" << std::endl;
    printTreeStructure(root);
    std::cout << std::endl;


    return 0;
}

    //
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    //