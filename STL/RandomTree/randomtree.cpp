#include <iostream>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdlib>


class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int getRandomDepth()
{
    return rand() % 11;
}

TreeNode* createRandomTree(int currentDepth, int maxDepth)
{
    if(currentDepth > maxDepth)
    {
        return nullptr;
    }
    
    int value = rand() % 100 + 1;
    TreeNode* node = new TreeNode(value);

    int childCount = rand() % 3;
    if(childCount >= 1)
    {
        node->left = createRandomTree(currentDepth + 1, maxDepth);
    }
    if(childCount == 2)
    {
        node->right = createRandomTree(currentDepth + 1, maxDepth);
    }

    return node;
}

void levelOrderTraversal(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
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



int main()
{
    srand(time(0));

    int depth = getRandomDepth();
    std::cout << "Random Tree Depth: " << depth << std::endl;

    TreeNode* root = createRandomTree(0, depth);

    std::cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    std::cout << std::endl;
}