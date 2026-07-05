class Solution {
public:
    int ultparent(int a, vector<int>& size, vector<int>& parent) {
        if (parent[a] == a) {
            return a;
        }
        parent[a] = ultparent(parent[a], size, parent);
        return parent[a];
    }
    void join(int a, int b, vector<int>& size, vector<int>& parent) {
        if (ultparent(a, size, parent) == ultparent(b, size, parent)) {
            return;
        }
        if (size[a] >= size[b]) {
            parent[parent[b]] = a;
            size[a] += size[b];
        } else {
            parent[parent[a]] = b;
            size[b] += size[a];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> size(n, 1);
        vector<int> parent(n, 0);
        unordered_set<int> s;
        iota(parent.begin(), parent.end(), 0);
        for (auto i : connections) {
            join(i[0], i[1], size, parent);
        }
        int t_grps{};
        for (int i{}; i < n; i++) {
            s.insert(ultparent(i, size, parent));
        }
        t_grps = s.size();
        if(connections.size()<n-1){return -1;}
        return t_grps-1;
    }
};