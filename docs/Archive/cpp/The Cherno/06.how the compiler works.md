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

