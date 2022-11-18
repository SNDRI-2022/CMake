# 添加版本号和配置头文件

有时让在文件中定义的变量在源代码`CMakelists.txt`中也可用可能很有用。在这种情况下，我们想打印项目版本。
实现引起目的的一种方法是使用已配置的头文件。我们创建一个输入文件，其中包含一个或多个要替换的变量。这些变量有特殊的语法，看起来像`@var@`.然后,我们使用`configure_file()`命令将输入文件复制到综合的输出文件,并将这些变量替换为`var`文件中的当前值`CMakelists.txt`.
虽然我们可以直接在源代码中编辑版本，但首选使用此功能，因为它创建了单一的真实来源并避免了重复

## 目标

定义并报告项目的版本号.

## 有用的资源

- [`<PROJECT-NAME>_VERSION_MAJOR`](https://cmake.org/cmake/help/latest/variable/PROJECT-NAME_VERSION_MAJOR.html#variable:%3CPROJECT-NAME%3E_VERSION_MAJOR) 主要版本,例如`project(Exercise3 VERSION 5.9)`中为5
- [`<PROJECT-NAME>_VERSIONMINOR`](https://cmake.org/cmake/help/latest/variable/PROJECT-NAME_VERSION_MINOR.html#variable:%3CPROJECT-NAME%3E_VERSION_MINOR) 次要版本,例如`project(Exercise3 VERSION 5.9)`中为9
- [`configure_file()`](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 将文件复制到另一个位置并修改内容

``` cmake
configure_file(<input> <output>
               [NO_SOURCE_PERMISSIONS | USE_SOURCE_PERMISSIONS |
                FILE_PERMISSIONS <permissions>...]
               [COPYONLY] [ESCAPE_QUOTES] [@ONLY]
               [NEWLINE_STYLE [UNIX|DOS|WIN32|LF|CRLF] ])
```

该命令将`<input>`文件复制到`<output>`文件，并替换`<input>`文件内容中引用为`@VAR@`或`${VAR}`的变量值为变量的当前值，如果未定义变量，则替换为空字符串

```cmake
//! 注意: @Exercise3_VERSION_MAJOR@ 中 Exercise3对应CMakeLists.txt中的项目名称
//! 要注意大小写Exercise3为正确，EXERCISE3或exercise3将无法识别到,并当成未定义变量
#define Exercise3_VERSION_MAJOR @Exercise3_VERSION_MAJOR@
#define Exercise3_VERSION_MINOR ${Exercise3_VERSION_MINOR}
//* 主要版本, 例如`project(Exercise3 VERSION 5.9)`中为5
//* 次要版本,例如`project(Exercise3 VERSION 5.9)`中为9
```

- [`target_include_directories()`](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)
将包含目录添加到目标。

```cmake
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])

# 指定可执行目标在何处找include文件(为main.cpp中包含头文件时不会报错) 
# 注意:文件中有空格时 "${CMAKE_BINARY_DIR}" 的双引号不能省
# 注意:PUBLIC为大写.
target_include_directories(Exercise3 PUBLIC "${CMAKE_BINARY_DIR}")
```

指定编译给定目标时要使用的包含目录。named`<target>`必须是由命令创建的，例如add_executable()或者add_library()并且不能是 ALIAS 目标。

## 要编辑的文件

- `CMakeLists.txt`
- `main.cpp`

## 入门

编辑Exercise3。在`./`中使用`configure_file()`将给定的输入文件复制到输出文件并替换输入文件内容中的一些变量值。

接下来,创建一个定义版本号的输入头文件`head.h`,它将接受从`configure_file()`.

最后,更新main.cpp打印它的版本号。

## 解决方案

在本练习中，我们通过打印版本号来改进我们的可执行文件。虽然我们可以专门在源代码中执行些操作，但使用`CMakeLists.txt`可以让我们维护版本号的单一数据源。

首先，我们修改`CMakeLists.txt`文件以使用`peoject()`命令设置项目名称和版本号。当`peoject()`命令被调用时,CMake在后台将`Exercise3_VERSIONMINOR`和`Exercise3_VERSIONMINOR`替换成`CMakeLists.txt`中变量的值。
