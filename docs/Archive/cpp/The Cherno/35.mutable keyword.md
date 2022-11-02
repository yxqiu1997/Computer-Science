## 35 The Mutable Keyword in C++

```cpp
int x = 8;
auto f = [=]() mutable {
  	x++;  // 不加mutable的话，不能修改x的值
  	std::cout << x << std::endl;
}；

f(); // 此时x = 8，因为是传值[=]，不是传引用[&]
```

