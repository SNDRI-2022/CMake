# 基本起点-指定C++标准

## 练习2 - 指定C++标准

CMake 有一些特殊变量，这些变量要么在幕后创建，要么在项目代码设置++3
-时对CMake有意义。其中两个特殊的用户可以设置变量是`CMAKE_CXX_STANDARD`和`CMAKE_CXX_STANDARD_REQUIRED`.这些可以一起用来指定构建 项目所需的C++标准。

### 目标

添加需要C++11的功能。

### 说明

* `CMAKE_CXX_STANDARD` CMake3.1中加入,设置CMAKE C++标准,缺省时为CXX_STANDARD(c++标准)
* `CMAKE_CXX_STANDARD_REQUIRED` CMake3.1中加入,设置CMAKE_CXX_STANDARD是否为强制启动，off为可选，on为强制，缺省时为CMAKE_CXX_STANDARD
* `set()` 将普通、缓存或环境变量设置为给定值
  `set(<variable> <value>... [PARENT_SCOPE])`variable在当前函数或目录范围内设置给定
  [set()官方文档](https://cmake.org/cmake/help/latest/command/set.html#command:set)
  
### 要编辑的文件+

* `CMakeListse.txt`
* `main.cpp`

### 操作

* 在main.cpp中添加c++11的功能语句 `vector<long long>,begin(),end()`
* 更新CMakeLists.txt以达到支持C++11功能
