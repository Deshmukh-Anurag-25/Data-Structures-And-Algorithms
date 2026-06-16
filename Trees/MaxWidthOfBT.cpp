#include<queue>
#include<algorithm>
#include"Node.h"
using namespace std;

long long int maxWidth(Node* root){
    if(!root) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int ans = 0;

    while(!q.empty()){
        int n = q.size();
        int mmin = q.front().second;

        int first, last;

        for(int i = 0; i < n; i++){
            int curr = q.front().second - mmin;
            Node* front = q.front().first;
            q.pop();

            if(i == 0) first = curr;
            if(i == n-1) last = curr;

            if(front->left) q.push({front->left, curr*2 + 1});
            if(front->right) q.push({front->right, curr*2 + 2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}