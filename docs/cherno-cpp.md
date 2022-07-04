## 04 How to Setup C++ on Linux

### CMakeLists.txt

```
cmake_minimum_required (VERSION 3.5)
project (HelloWorld)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")
add_executable (HelloWord ${source_files})
```

### build.sh

```bash
#!/bin/sh

cmake -G "CodeLite - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
```



## 06 How the C++ Compiler Works

### #include

```cpp
/* 将iostream里的代码直接复制到当前文件，不做任何处理 */
#include <iostream>
```

### 条件编译

```cpp
/* 条件为true时，执行代码 */
#if 1
int Multiply(int a, int b) {
  	int result = a * b;
    return result;
}
#endif

/* 条件为false时，不执行代码，相当于注释了 */
#if 0
int Multiply(int a, int b) {
  	int result = a * b;
    return result;
}
#endif
```

### 常量折叠 (Constant Folding)

``return 5 * 2`` 编译时直接当作 ``return 10`` 处理，**任何常量都可以在编译时计算出来**

 

## 07 How the C++ Linker Works

linking 是一个从 C++ 二进制源码 (.obj) 到真正可执行二进制的一个过程

主要工作：找到每个符号和函数的位置，并将它们链接在一起

每个文件被编译成一个**独立**的 obj 文件作为 translation unit 

即使只有一个文件也需要linking，因为要把函数入口 link 进来 (entry point 通常是 ``main()`` 函数，但不一定非要是) 

```cpp
/* 在compile阶段出现的错误信息 - C打头 */
error C2143: syntax error: missing ...
  
/* 在linking阶段出现的错误信息 - LNK打头 */
fatal error LNK1561: entry point must be defined
```

### 重复引入头函数解决办法

```cpp
/* Log.h */
#pragma once

void Log(const char* message) {
  	std::cout << message << std::endl;
}
```

```cpp
/* Log.cpp */
#include <iostream>
#include "Log.h"

void InitLog() {
  	Log("Initialized Log");
}
```

```cpp
/* Math.cpp */
#include <iostream>
#include "Log.h"

static int Multiply(int a, int b) {
  	Log("Multiply");
  	return a * b;
}

int main() {
  	std::cout << Multiply(5, 8) << std::endl;
  	std::cin.get()
}
```

在 Log.cpp 和 Math.cpp 中，都引入了 Log.h，此时 build 项目会出现

```
fatal error LNK1169: one or more multiply defined symbols found
```

**解决办法1：static**

linking 这个 Log 函数只会发生在文件内部，不影响其他文件

Log.h 被 include 在 log.cpp 中和 Math.cpp 时，只对该文件内部有效。两个文件有属于自己的 Log.h 版本，自己的版本对其它 obj 文件不可见

```cpp
/* Log.h */
#pragma once

static void Log(const char* message) {
  	std::cout << message << std::endl;
}
```

**解决办法2：inline**

inline 意思是把函数的 body 拿过来取代调用

```cpp
/* Log.h */
#pragma once

inline void Log(const char* message) {
  	std::cout << message << std::endl;
}
```

**解决方案3：将定义移动到一个 translation unit (cpp文件) 中（推荐）**

将函数的定义移动到一个cpp文件中，头文件只保留声明，不进行定义

```cpp
/* Log.h */
#pragma once

void Log(const char* message);
```

```cpp
/* Log.cpp */
#include <iostream>
#include "Log.h"

void InitLog() {
  	Log("Initialized Log");
}

void Log(const char* message) {
  	std::cout << message << std::endl;
}
```



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



## 16 POINTERS in C++

指针是一个整数，一个数字，存储一个内存地址

```cpp
/* 空指针，以下表示等价 */
void* ptr = 0;
void* ptr = NULL;  // #define NULL 0
void* ptr = nullptr;  // C++11引入的关键字 
```

如果只是 ```void``` 指针，计算机不知道这个指针指的内存是几个字节，也就没办法向这个内存中存入相应的数据类型

```cpp
/* 使用new关键字，该数据会被分配到heap上，处理完应该要删除这个数据 */
char* buffer = new char[8];
memset(buffer, 0, 8);
delete[] buffer;
```



## 17 REFERENCES in C++

引用变量必须引用一个已经存在的变量，它本身不是一个新的变量，不占用内存，不存储数据

```cpp
/* 编译时只会产生a一个变量
 * 在任何情况下，ref就时a
 * 引用不是一个指针，编译器没有必要创建一个新的变量
 */
int a = 5;
int& ref = a;  // ref是别名 (alias)，不是变量
```

```cpp
/* 指针版本 */
void Increment(int* value) {
    (*value)++;
}
int main() {
  	int a = 5;
  	Increment(&a);
}

/* 引用版本 */
void Increment(int& value) {
  	value++;
}
int main() {
  	int a = 5;
  	Increment(a);
}
```



## 18 CLASSES in C++

默认情况下，类中的成员的访问控制都是私有的，变公有要加 ```public```

默认情况下，结构体中的成员的访问控制都是公有的，变私有要加 ```private```

```cpp
class Player {
public:
  	int x, y;
  	int speed;
  	
  	void Move(int xa, int ya) {
      	x += xa * speed;
      	y += ya * speed;
    }
};
int main() {
		Player player;
  	player.Move(1, -1);
}
```



## 21 Static in C++

使用 ```extern``` 可以找到外部文件中定义的变量

在C++中一个类或一个结构体，```static``` 声明的静态函数或静态变量只会在声明的那个C++文件中可见



## 23 Local Static in C++

单例模式：

```cpp
#include <iostream>

class Singleton {
public:
  	static Singleton& Get() {
      	static Singleton instance;
      	return instance;
    }
  
  	void Hello() {}
}

int main() {
  	Singleton::Get()::Hello();
  	std::cin.get();
}
```



## 25 Constructors in C++

隐藏构造函数

```cpp
class Log {
public:
  	Log() = delete;
}
```



## 28 Virtual Functions in C++

```cpp
class Entity {
public:
  	virtual std::string GetName() {  // 使用virtual关键字建立虚函数表，否则不会进行动态分配
      	return "Entity";
    }
};

class Player : public Entity {
private:
  	std::string m_Name;
public:
    Player(const std::string& name) : m_Name(name) {}
  	std::string GetName() override {  // override可以省略
      	return m_Name;
    }
};
```

虚函数代价：

	1. 需要额外内存才能将信息存储在虚函数表中，以便我们可以分派到正确的函数。该函数包含实际基类中指向虚函数表的成员指针
	1. 每次我们调用虚函数，都需要遍历虚函数表以查看映射哪个函数



## 29 Interfaces in C++

```cpp
class Entity {
public:
  	virtual std::string GetName() = 0;
};
```



## 32 How Strings Work in C++

```CPP
#include <iostream>
#include <string>

// string复制很慢，所以要用const、reference
void PrintString(const std::string& string) {
  	std::cout << name << std::endl;
}

int main() {
  	std::string name = std::string("Cherno") + " hello!";  // 不能直接相加，要调用一下std::string的构造器
  	bool contains = name.find("no") != std::string::npos;  //  npos相当于-1
  	std::cout << name << std::endl;
  
  	std::cin.get();
}
```







