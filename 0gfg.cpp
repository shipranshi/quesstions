//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    void preOrderTrav(Node *curr, multimap<pair<int, int>, int> &mp, int position, int level)
    {
        if (curr == NULL)
            return;

        mp.insert({{position, level}, {curr->data}});
        // preOrder.push_back(curr -> val);
        preOrderTrav(curr->left, mp, position - 1, level + 1);
        preOrderTrav(curr->right, mp, position + 1, level + 1);
    }

    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        int position = 0, level = 0;
        vector<vector<int>> ans;
        vector<int> order;
        multimap<pair<int, int>, int> mp;
        preOrderTrav(root, mp, position, level);

        // lovely

        int i = mp.begin()->first.first;
        // cout<<i;

        for (auto it : mp)
        {
            //  cout<< it.first.first<<" "<<it.first.second<<" ";
            //  for(auto it1 :it.second)cout<<it1<<endl;
            //  }
            if (i == it.first.first)
            {
                order.push_back(it.second);
                i++;
                // cout<<it.second;
            }

            else
            {
                continue;
            }
        }

        return order;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends