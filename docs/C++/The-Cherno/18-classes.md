## 18 CLASSES in C++

默认情况下，类中的成员的访问控制都是私有的，变公有要加 ```public```

默认情况下，结构体中的成员的访问控制都是公有的，变私有要加 ```private```

```cpp
class Player {
public:
  	int x, y;
  	int speed;
  	
  	void Move(int xa, int ya) {
      	x += xa * speed;
      	y += ya * speed;
    }
};
int main() {
	Player player;
  	player.Move(1, -1);
}
```

