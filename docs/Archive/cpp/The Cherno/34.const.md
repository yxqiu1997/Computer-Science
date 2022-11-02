## 34 CONST in C++

```cpp
const int MAX_AGE = 90;

// const在*左侧，不可以改变指针所指内容，即指针指向常量
int const* a = new int;
const int* a = new int;
*a = 2  // error!
a = (int*)&MAX_AGE;  // correct


// const在*右侧，不可以reassign指针，即指针本身是常量
int* const a = new int;
const int* const a = new int;
*a = 2  // correct
a = (int*)&MAX_AGE;  // error!
```

```cpp
class Entity {
private:
  	int m_X, m_Y;
public:
  	int GetX() const {  // 这种用法只能用在类中，这个函数无法改变类的成员变量的值
      	m_X = 2; // error!
      	return m_X;
    }
}
```

```cpp
class Entity {
private:
  	int* m_X, *m_Y;  // 两个都是指针
public:
  	// 第一个const：返回的指针所指的内容为常量，不能修改
  	// 第二个const：函数返回的常量指针，不能reassign
  	// 第三个const：函数无法改变类的成员变量的值
  	const int* const GetX() const {
      	return m_X;
    }
}
```

```cpp
class Entity {
private:
  	int* m_X, *m_Y;  
  	mutable int var;
public:
  	int* GetX() const {
      	var = 2;  // 带mutable的变量可以在const里被改变
      	return m_X;
    }
  	
  	// 这个函数无法保证m_X不被修改，所以PrintEntity()调用时不会调用这个方法
  	int* GetX() {
      	return m_X;
    }
}

void PrintEntity(const Entity& e) {
  	std::cout << e.GetX() << std::endl; 
}
```

