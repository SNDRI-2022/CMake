# 基本起点-构建一个基本项目

## 练习1 - 构建一个基本项目

最基本的CMake项目是从单个源代码文件构建的可执行文件。对于像这样的简单项目,CMakeLists.txt只需要包含三个命令的文件。
这里将构造并编译/链接最简单的Hello World C++项目。最后再运行并输出

**注意**:CMake支持大写、小写和混合大小写，但还是建议全程使用小写

在CMakeLists.txt文件中必须先指定最低版本`cmake_minimum_required()`命令
要启动一个项目，我们使用`project()`命令来设置项目名称。每个项目都需要调用这条命令。
最后，`add_executable()`命令告诉CMake使用抒写的源代码文件创建可执行文件。

### 目标

知道如何创建一个简单的CMake项目。

### 要编辑的文件

* `CMakeLists.txt`

* `main.cpp`

### 说明

* `设置CMake最小版本cmake\_minimum\_required()`
    `cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR])`
    3.12版本中新添加的功能`<policy_max>`
    2.6版本以上可忽略`FATAL_ERROR`  **通常只要写**`cmake_minimum_required(VERSION <版本号>)`
    [cmake\_minimum\_required()官方文档](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command\:cmake_minimum_required)

* `设置项目名称project()`
    `project(<PROJECT-NAME> [<language-name>...])`  **通常只要写**`project(<项目名称> VERSION <版本号>)`
    [project()官方文件](https://cmake.org/cmake/help/latest/command/project.html#command\:project)

* `添加可执行文件add\_executable()`
    `add_executable(<name> [WIN32] [MACOSX_BUNDLE]              [EXCLUDE_FROM_ALL]              [source1] [source2 ...])` **通常只要写**`add_executable(<项目名称> c++源文件)`
    [add\_executable()官方文档](https://cmake.org/cmake/help/latest/command/add_executable.html#command\:add_executable)

CMakeLists.txt

```cmake
    cmake_minimum_required(VERSION 3.10)
    
    project(hello VERSION 0.1.0)

    add_executable(hello main.cpp)
```

main.cpp

```cpp
#include <iostream>

int main(int argv, char **argc)
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```

### 构造并运行

#### 建立构造目录

* 建立个build目录`mkdir build && cd ./build`
* 进入build目录`cd ./build`

#### 构造

* Linux中使用`cmake ./`
* windows中使用`cmake ./ -G "MinGW Makefiles"` **注意:** windows下要配置MinGW

#### 编译/链接项目

* 输出`cmake --build ./`

#### 运行

* windows中输入`./hello.exe`
* Linux中输入 `./hello`
