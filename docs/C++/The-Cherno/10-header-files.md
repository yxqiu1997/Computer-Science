## 10 C++ Header Files

### Header guard (头文件保护符)

**方法一：#pregma once（推荐）**

所有 # 开头的是 Pre-process command，意味它将在这个文件被编译之前被 C++ 的 pre processor 评估

``#pragma once`` 是一种 header guard (头文件保护符)，意思是只 include 这个文件一次，防止我们把单个头文件多次 include 到同一个翻译单元里**（不会防止我们把头文件 include 到程序的别处！！！）**

```cpp
#pragma once

void InitLog();
void Log(const char* message);

struct Player {};
```

**方法二：#ifdef**

首先检查 _LOG_H 是否被定义了，如果没有，执行中间代码，如果有，中间的都会被禁用

```cpp
#ifndef _LOG_H
#define _LOG_H

void InitLog();
void Log(const char* message);

struct Player {};

#endif
```

### " " 和 < > 的区别

当我们在编译程序时，我们可以告诉编译器某些 include 的路径，这是在我们电脑里通往包含 include 文件的文件夹的路径

如果我们想要 include 的那个文件在这些文件夹其中之一的话，我们可以用方括号让编译器在所有 include 路径里去搜索这个文件

而引号用于 include 文件存在于当前文件的相对位置，可以 ``../`` 、``./``，等。其实引号也可以用在任何地方，比如 ``#include "iostream"``

### 扩展名

为了区分 C 的标准库和 C++ 的标准库，C 标准库里的头文件一般都有 .h. 扩展名，而 C++ 没有