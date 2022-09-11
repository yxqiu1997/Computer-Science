## 38 How to CREATE INSTANTIATE OBJECTS in C++

```cpp
#include <iostream>
#include <string>

using String = std::string;

class Entity {
private:
  	String m_Name;
public:
  	Entity() : m_Name("Unknown") {}
  	Entity(const String& name) : m_Name(name) {}
  
  	const String& GetName() const { return m_Name; }
};

// Stack Allocation
int main() {
  	Entity entity;  // 自动调用默认的构造函数（已经初始化好了，不像Java）
  	Entity entity("Cherno");  // 能用这两种尽量用，最快
  
  	std::cin.get();
}

// Heap Allocation，在对象很大的时候使用
// 对象不会因为函数结束而被释放，需要手动free
int main() {
  	Entity* e;
  	{
      	Entity* entity = new Entity("Cherno");
      	e = entity;
      	std::cout << (*entity).GetName() << std::endl; // 或者
      	std::cout << entity)->GetName() << std::endl;
    }
  
  	std::cin.get();
  	delete e;
}
```

