//* configure_file 将文件复制到另一个位置并修改其内容.
//* 该命令将<input> 文件复制到<output> 文件，并替换<input> 文件内容中引用为 或 的变量值为变量的当前值，
//* 如果未定义变量，则替换为空字符串。
//! 注意: 5 中 Exercise3对应CMakeLists.txt中的项目名称
//! 要注意大小写Exercise3为正确，EXERCISE3或exercise3将无法识别到,并当成未定义变量

#define Exercise3_VERSION_MAJOR 5
#define Exercise3_VERSION_MINOR 9
//* 主要版本, 例如`project(Exercise3 VERSION 5.9)`中为5
//* 次要版本,例如`project(Exercise3 VERSION 5.9)`中为9
