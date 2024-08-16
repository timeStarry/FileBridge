# FileBridge
基于 C++ 的端到端文件传输服务

开发中……

开发指南:

```bash
$ git clone https://github.com/timeStarry/FileBridge
$ cd FileBridge
$ git submodule update --init --recursive
$ make gcc_r # for release build and use g++ compiler, you can use gcc_b for debugging, and clang prefix to specify clang/llvm compilation
$ cmake --build build -j`nproc`
```
