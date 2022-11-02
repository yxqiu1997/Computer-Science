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

