# 🔥 CodeForge

**算法竞赛模板库 | Algorithm Template Library for CP**

[中文](README.md) | [English](README.en.md)

<p align="center">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-blue.svg">
  <img alt="Language" src="https://img.shields.io/badge/language-C++-orange.svg">
</p>


## Folder Layout
```
CodeForge/
├─ graph/           # graph algorithms
├─ data-struct/     # data structures
├─ math/            # number theory & poly
├─ string/          # string algorithms
├─ geo/             # computational geometry
└─ misc/            # utilities (fast IO, stress, debug macros)
```
Every `.cpp` is self-contained—just drop it into your project.

## Build in One Line
```bash
g++ -std=c++17 -O2 -Wall -Wextra -o main filename.cpp && ./a.out
```
**Notes**  
- C++17 or higher is required  
- Templates using `__int128` need judge support; fallback to `long long` if not available

## Quick Algorithm Index
| Category      | File                           | Description                                |
| ------------- | ------------------------------ | ------------------------------------------ |
| Shortest Path | `graph/dijkstra.cpp`           | heap-optimized Dijkstra with path printing |
| Max Flow      | `graph/dinic.cpp`              | current-arc Dinic, $O(n^2m)$               |
| Union-Find    | `data-struct/dsu.cpp`          | path compression + union by rank           |
| Segment Tree  | `data-struct/segtree_lazy.cpp` | range add / range sum                      |
| Number Theory | `math/exgcd.cpp`               | extended Euclidean & modular inverse       |
| String        | `string/kmp.cpp`               | single-pattern matching                    |
| Geometry      | `geo/convex_hull.cpp`          | Andrew's monotone chain                    |

(Browse the folders for more; filenames are self-explanatory.)

## Update Cadence
- New templates land after each contest  
- Typos are fixed on the fly so "copy → paste → pass samples" always holds

## Contributing
Issues & PRs are welcome:  
1. Fork → 2. branch → 3. test samples → 4. PR  
Please keep every template single-file and dependency-free.

## License
All code is released under the [MIT](LICENSE) license. **No attribution required**; commercial use is fine.