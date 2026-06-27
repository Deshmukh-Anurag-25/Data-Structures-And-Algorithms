#include <algorithm>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &grid) {
  int row = grid.size();
  int col = grid[0].size();

  for (int i = 0; i < row; i++) {
    for (int j = i + 1; j < col; j++) {
      swap(grid[i][j], grid[j][i]);
    }
  }

  for (auto &it : grid) {
    reverse(it.begin(), it.end());
  }
}
