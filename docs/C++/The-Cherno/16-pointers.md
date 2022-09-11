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

