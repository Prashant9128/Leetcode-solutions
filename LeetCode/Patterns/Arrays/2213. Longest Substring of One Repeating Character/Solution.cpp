class Solution {
public:

    struct Node {
        int prefix;
        int suffix;
        int best;
        
        Node(int p = 0, int s = 0, int b = 0) {
            prefix = p;
            suffix = s;
            best = b;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node left, Node right, int l, int mid, int r) {

        Node ans;

        // Initially take the best from both sides
        ans.best = max(left.best, right.best);

        // Prefix
        ans.prefix = left.prefix;

        // Suffix
        ans.suffix = right.suffix;

        // If boundary characters are same,
        // we can combine suffix of left + prefix of right
        if (s[mid] == s[mid + 1]) {

            ans.best = max(ans.best,
                           left.suffix + right.prefix);

            // Entire left part has same character
            if (left.prefix == mid - l + 1) {
                ans.prefix += right.prefix;
            }

            // Entire right part has same character
            if (right.suffix == r - mid) {
                ans.suffix += left.suffix;
            }
        }

        return ans;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node] = Node(1, 1, 1);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] =
            merge(tree[node * 2],
                  tree[node * 2 + 1],
                  l, mid, r);
    }

    void update(int node, int l, int r, int idx, char ch) {

        if (l == r) {
            s[idx] = ch;
            tree[node] = Node(1, 1, 1);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, ch);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, ch);
        }

        tree[node] =
            merge(tree[node * 2],
                  tree[node * 2 + 1],
                  l, mid, r);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        // Build initial segment tree
        build(1, 0, n - 1);

        vector<int> answer;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            // Update character
            update(1, 0, n - 1, index, ch);

            // Root contains answer for complete string
            answer.push_back(tree[1].best);
        }

        return answer;
    }
};