### 思路1 分组异或

如果只有一个不同的话，直接全部异或，参考136.

这道题先全部异或一次，结果就是两个只出现一次的数的异或的结果。假设是10010。

说明这两个数右边第二位不同。我们可以根据右边第二位是否是1，把数分成两组：

1. 相同的数分别归于两组
2. 不同的数（即两个目标数）分离在两组
