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

\