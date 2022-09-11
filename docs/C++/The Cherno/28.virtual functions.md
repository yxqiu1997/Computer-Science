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

