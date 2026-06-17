#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    return (root1->val == root2->val) &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right);
}

int main() {
    int n1;
    cin >> n1;
    vector<int> val1(n1), l1(n1), r1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> val1[i] >> l1[i] >> r1[i];
    }

    int n2;
    cin >> n2;
    vector<int> val2(n2), l2(n2), r2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> val2[i] >> l2[i] >> r2[i];
    }

    vector<TreeNode*> nodes1(n1);
    for (int i = 0; i < n1; i++) {
        nodes1[i] = new TreeNode(val1[i]);
    }
    for (int i = 0; i < n1; i++) {
        if (l1[i] != -1) nodes1[i]->left = nodes1[l1[i]];
        if (r1[i] != -1) nodes1[i]->right = nodes1[r1[i]];
    }
    TreeNode* root1 = nodes1[0];

    vector<TreeNode*> nodes2(n2);
    for (int i = 0; i < n2; i++) {
        nodes2[i] = new TreeNode(val2[i]);
    }
    for (int i = 0; i < n2; i++) {
        if (l2[i] != -1) nodes2[i]->left = nodes2[l2[i]];
        if (r2[i] != -1) nodes2[i]->right = nodes2[r2[i]];
    }
    TreeNode* root2 = nodes2[0];

    cout << (areIdentical(root1, root2) ? "true" : "false") << endl;

    return 0;
}