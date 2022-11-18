# 添加版本号和配置头文件

有时让在文件中定义的变量在源代码`CMakelists.txt`中也可用可能很有用。在这种情况下，我们想打印项目版本。
实现引起目的的一种方法是使用已配置的头文件。我们创建一个输入文件，其中包含一个或多个要替换的变量。这些变量有特殊的语法，看起来像`@var@`.然后,我们使用`configure_file()`命令将输入文件复制到综合的输出文件,并将这些变量替换为`var`文件中的当前值`CMakelists.txt`.
虽然我们可以直接在源代码中编辑版本，但首选使用此功能，因为它创建了单一的真实来源并避免了重复

## 目标

定义并报告项目的版本号.

## 有用的资源

- [`<PROJECT-NAME>_VERSION_MAJOR`](https://cmake.org/cmake/help/latest/variable/PROJECT-NAME_VERSION_MAJOR.html#variable:%3CPROJECT-NAME%3E_VERSION_MAJOR) 主要版本
- [`<PROJECT-NAME>_VERSIONMINOR`](https://cmake.org/cmake/help/latest/variable/PROJECT-NAME_VERSION_MINOR.html#variable:%3CPROJECT-NAME%3E_VERSION_MINOR) 最小版本
- [`configure_file()`](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 将文件复制到另一个位置并修改内容

``` cmake
configure_file(<input> <output>
               [NO_SOURCE_PERMISSIONS | USE_SOURCE_PERMISSIONS |
                FILE_PERMISSIONS <permissions>...]
               [COPYONLY] [ESCAPE_QUOTES] [@ONLY]
               [NEWLINE_STYLE [UNIX|DOS|WIN32|LF|CRLF] ])
```

将一个文件复制`<input>`到加一个文件，并替换作为输入文件内容或在输入文件内容中`<output>`每个变量引用都将替换为变量的当前值，如果未定义变量，则替换为空字符串。

- [`target_include_directories()`](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)
将包含目录添加到目标。

```cmake
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
```

指定编译给定目标时要使用的包含目录。named`<target>`必须是由命令创建的，例如add_executable()或者add_library()并且不能是 ALIAS 目标。

## 要编辑的文件

- `CMakeLists.txt`
- `main.cpp`

## 入门

