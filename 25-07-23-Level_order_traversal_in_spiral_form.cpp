/*
Problem Description: Level order traversal in spiral form

Given a binary tree and the task is to find the spiral order traversal of the tree.

Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2


Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 10^5
0 <= Data of a node <= 10^5
*/

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    bool rightToleft = true;
    
    while(!q.empty()){
        int n = q.size();
        
        vector<int>temp(n);
        
        for(int i=0; i<n; i++){
            Node* front = q.front();
            q.pop();
            int ind = rightToleft ? n-1-i:i;
            temp[ind] = front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        
        for(auto it:temp)
            ans.push_back(it);
        
        rightToleft = !rightToleft;
    }
    
    return ans;
}
