# 🔥 CodeForge

<div align="center">


**算法竞赛模板库 | Algorithm Template Library for CP**

[中文](README.md) | [English](README.en.md)
</div>

<p align="center">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-blue.svg">
  <img alt="Language" src="https://img.shields.io/badge/language-C++-orange.svg">
</p>


## 文件组织
```
CodeForge/
├─ graph/           # 图论
├─ data-struct/     # 数据结构
├─ math/            # 数论 & 多项式
├─ string/          # 字符串
├─ dp/              # 动态规划
└─ misc/            # 杂项（快读、对拍、调试宏）
```
每个 `.cpp` 都是独立模板，直接复制即可塞进任意工程。

## 一键编译
```bash
g++ -std=c++17 -O2 -Wall -Wextra -o main filename.cpp && ./a.out
```
**提示**  
- 需要 C++17 及以上  
- 模板里如果用到 `__int128`，请确保评测机支持，否则自行改 `long long`

## 常见算法速览
| 类别   | 模板文件                       | 说明                               |
| ------ | ------------------------------ | ---------------------------------- |
| 最短路 | `graph/dijkstra.cpp`           | 堆优化 Dijkstra，支持路径记录      |
| 网络流 | `graph/dinic.cpp`              | 当前弧优化 Dinic，复杂度 $O(n^2m)$ |
| 并查集 | `data-struct/dsu.cpp`          | 路径压缩 + 按秩合并                |
| 线段树 | `data-struct/segtree_lazy.cpp` | 区间加 / 区间求和                  |
| 数论   | `math/exgcd.cpp`               | 扩展欧几里得 + 逆元                |
| 字符串 | `string/kmp.cpp`               | 单模式串匹配                       |
| 几何   | `geo/convex_hull.cpp`          | Andrew 凸包，极点排序              |

（更多文件请直接翻目录，命名尽量自解释）

## 更新节奏
- 每场比赛后如果写了新板子就丢进来  
- 顺手修 typo，保证「复制即可过样例」

## 贡献方式
Issues & PR 都欢迎：  
1. Fork → 2. 新分支 → 3. 测样例 → 4. PR  
**注意**：请保持单文件独立、无外部依赖。

## 许可证
所有模板均以 [MIT](LICENSE) 协议发布，**复制无需署名**，改完商用也行。
