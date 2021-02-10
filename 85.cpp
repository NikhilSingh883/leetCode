class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows == 0)
      return 0;
    int cols = matrix[0].size();
    if (cols == 0)
      return 0;

    int ret = 0;

    std::vector<int> histogram(cols+1, 0);
    for (int i=0; i<rows; ++i) {
      std::vector<int> slope {-1};
      for (int j=0; j<=cols; ++j) {
        if (j < cols && matrix[i][j] == '1')
          ++histogram[j];
        else
          histogram[j] = 0;
        while (slope.back() >= 0 && histogram[slope.back()] >= histogram[j]) {
          int height = histogram[slope.back()];
          slope.pop_back();
          ret = max(ret, (j-slope.back()-1)*height);
        }
        slope.push_back(j);
      }
    }
    return ret;
  }
        
};