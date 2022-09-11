## 32 How Strings Work in C++

```CPP
#include <iostream>
#include <string>

// string复制很慢，所以要用const、reference
void PrintString(const std::string& string) {
  	std::cout << name << std::endl;
}

int main() {
  	std::string name = std::string("Cherno") + " hello!";  // 不能直接相加，要调用一下std::string的构造器
  	bool contains = name.find("no") != std::string::npos;  //  npos相当于-1
  	std::cout << name << std::endl;
  
  	std::cin.get();
}
```

