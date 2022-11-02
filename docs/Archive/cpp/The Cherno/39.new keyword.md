## 39 The NEW Keyword in C++

```cpp
Entity* e = new Entity();  // 分配内存 + 调用构造函数
Entity* e = (Entity*)malloc(sizeof(Entity));  // 仅分配内存，最好不要这样用

delete e;
```

```cpp
// delete[]会逐个调用所有元素的destructor
int* b = new int[50];  // 200 bytes
delete[] b;
```

