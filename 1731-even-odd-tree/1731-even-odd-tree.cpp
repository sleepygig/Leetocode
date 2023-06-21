/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool isEvenOddTree(TreeNode* root) {
    vector<vector<int>> levels;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> levelValues;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            levelValues.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        levels.push_back(levelValues);
    }

    for (int i = 0; i < levels.size(); i++) {
        if (i % 2 == 0) {
            if (!isStrictlyIncreasing(levels[i]) || hasEvenValues(levels[i])) {
                return false;
            }
        } else {
            if (!isStrictlyDecreasing(levels[i]) || hasOddValues(levels[i])) {
                return false;
            }
        }
    }

    return true;
}

bool isStrictlyIncreasing(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isStrictlyDecreasing(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] >= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool hasEvenValues(vector<int>& arr) {
    for (int num : arr) {
        if (num % 2 == 0) {
            return true;
        }
    }
    return false;
}

bool hasOddValues(vector<int>& arr) {
    for (int num : arr) {
        if (num % 2 == 1) {
            return true;
        }
    }
    return false;
}

};