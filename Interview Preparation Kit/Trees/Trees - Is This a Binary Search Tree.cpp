/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    vector<int> nodes;  //vector to hold node data from the in order traversal

    void inOrder(Node *root) //in order traversal function
    {
        if(root == NULL)
        {
            return;
        }
        inOrder(root->left);
        nodes.push_back(root->data);
        inOrder(root->right);
    }

//compares the node data in the nodes vector, and if at any point the current number is less or equal to the previous number, returns false
	bool checkBST(Node* root)
    {
		inOrder(root);

        for(int i = 1; i < nodes.size(); i++)
        {
            if(nodes[i] <= nodes[i - 1])
            {
                return false;
            }
        }
        return true;
	}
