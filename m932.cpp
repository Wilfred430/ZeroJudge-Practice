#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  // 讀取矩陣的行數、列數及指令數
  int m, n, k;
  cin >> m >> n >> k;
  
  // 定義一個 m x n 的字元矩陣
  char matrix[m][n];
  
  // 讀取矩陣的內容
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }

  // 初始位置設為矩陣的左下角
  int posX, posY;
  posX = 0;
  posY = m - 1;

  int input; // 儲存每次的移動指令
  string ans = ""; // 儲存收集到的字元
  int points = 0; // 不重複字元的數量

  for (int i = 0; i < k; i++)
  {
    cin >> input;
    // 根據指令移動位置
    if (input == 0)
    {
      if ((posY - 1) >= 0)
      {
        posY -= 1; // 向上移動
      }
    }
    else if (input == 1)
    {
      if ((posX + 1) <= (n - 1))
      {
        posX += 1; // 向右移動
      }
    }
    else if (input == 2)
    {
      if ((posX + 1) <= (n - 1) and (posY + 1) <= (m - 1))
      {
        posX += 1; // 向右下移動
        posY += 1;
      }
    }
    else if (input == 3)
    {
      if ((posY + 1) <= (m - 1))
      {
        posY += 1; // 向下移動
      }
    }
    else if (input == 4)
    {
      if ((posX - 1) >= 0)
      {
        posX -= 1; // 向左移動
      }
    }
    else if (input == 5)
    {
      if ((posX - 1) >= 0 and (posY - 1) >= 0)
      {
        posX -= 1; // 向左上移動
        posY -= 1;
      }
    }
    
    // 判斷當前字元是否已經收集過
    bool repeat = false;
    for (int i = 0; i < ans.size(); i++)
    {
      if (matrix[posY][posX] == ans[i])
      {
        repeat = true;
        break;
      }
    }
    
    // 若當前字元未被收集過，則計入 points
    if (repeat == false)
    {
      points += 1;
    }
    
    // 將當前字元加入 ans 字串中
    ans = ans + matrix[posY][posX];
  }

  // 輸出收集到的字元和不重複的字元數量
  cout << ans << endl;
  cout << points << endl;

  return 0;
}
