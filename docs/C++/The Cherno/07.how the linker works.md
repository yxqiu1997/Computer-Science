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

