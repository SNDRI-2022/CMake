# 基本起点-指定C++标准

## 练习2 - 指定C++标准

CMake 有一些特殊变量，这些变量要么在幕后创建，要么在项目代码设置++3
-时对CMake有意义。其中两个特殊的用户可以设置变量是`CMAKE_CXX_STANDARD`和`CMAKE_CXX_STANDARD_REQUIRED`.这些可以一起用来指定构建 项目所需的C++标准。

### 目标

添加需要C++11的功能。

### 说明

* `CMAKE_CXX_STANDARD`
* `CMAKE_CXX_STANDARD_REQUIRED`
* `set()`

### 要编辑的文件

* `CMakeListse.txt`
* `main.cpp`
