### 思路1 dp


这道题的意思是，最坏情况下，最少扔几次

https://leetcode.com/problems/super-egg-drop/discuss/158974/C%2B%2BJavaPython-2D-and-1D-DP-O(KlogN)

用逆向思维

dp[f][k]表示k个鸡蛋，f次操作，所能确定的楼层数量n

我们需要让能确定的楼层数量n > N，表示我们用k个鸡蛋扔了f次能覆盖题目给的N层楼

- 蛋碎了，k-1，f-1，说明在操作的这一层下面，
- 蛋没碎，k, f-1，说明真正的N在操作的这一层上面

（当前楼层下面，能覆盖的楼层数量 + 当前楼层上面，能覆盖的楼层数量 + 当前楼层1）就是k个鸡蛋，f次扔，能确定的楼层的总数量

dp[f][k] = dp[f-1][k-1] + dp[f-1][k] + 1