### Predicate

- ```Predicate```是一个布尔值的函数，是一个功能接口，属于```java.util.function```包
- ```Predicate```的功能方法是```test(T t)```，其它方法是`test`、`isEqual`、`and`、`or`、`negate`和`not`(Java 11)

#### 1. test(T t)

```java
boolean test(T t)
```

`test`是`Predicate`的功能方法。它在给定的参数上评估这个谓词。

```java 
import java.util.function.Predicate;
public class PredicateTestDemo1 {
  public static void main(String[] args) {
	// Is username valid
	Predicate<String> isUserNameValid = u -> u != null && u.length() > 5 && u.length() < 10;
	System.out.println(isUserNameValid.test("Mahesh")); //true

	// Is password valid
	Predicate<String> isPasswordValid = p -> p != null && p.length() > 8 && p.length() < 15;
	System.out.println(isPasswordValid.test("Mahesh123")); //true
	
	// Word match
	Predicate<String> isWordMatched = s -> s.startsWith("Mr.");
	System.out.println(isWordMatched.test("Mr. Mahesh")); //true
	
	//Odd numbers
	Predicate<Integer> isEven = n -> n % 2 == 0;
	for(int i = 0 ; i < 5 ; i++) {
	  System.out.println("Is "+ i + " even: " + isEven.test(i));
	}
  }
} 
```

```java
import java.util.function.Function;
import java.util.function.Predicate;
public class PredicateTestDemo2 {
  public static void main(String[] args){
    Predicate<Student> maleStudent = s-> s.getAge() >= 20 && "male".equals(s.getGender());
    Predicate<Student> femaleStudent = s-> s.getAge() > 18 && "female".equals(s.getGender());
    
    Function<Student,String> maleStyle = s-> "Hi, You are male and age "+s.getAge();
    Function<Student,String> femaleStyle = s-> "Hi, You are female and age "+ s.getAge();
    
    Student s1 = new Student("Gauri", 20,"female");
    if(maleStudent.test(s1)){
        System.out.println(s1.customShow(maleStyle));
    }else if(femaleStudent.test(s1)){
        System.out.println(s1.customShow(femaleStyle));
    }      
  } 
```

#### 2. 在Stream中使用Predicate

`filter()`在处理给定的`Predicate`后，返回由过滤后的数据组成的`Stream`实例。

```java
filter(Predicate predicate) 
```

```java
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;
public class PredicateStreamDemo1 {
  public static void main(String[] args) {
	List<String> list = new ArrayList<>();	
	list.add("Vijay");
	list.add("Ramesh");
	list.add("Mahesh");
	
	Predicate<String> isNameEndsWithSh = s -> s.endsWith("sh");
	
	list.stream().filter(isNameEndsWithSh)
	  .forEach(s -> System.out.println(s));
  }
} 
```

#### 3. 在方法里调用demo

```java
public static boolean some(Predicate<Tile> tilePredicate, Board b) {
  for (int col = 0; col < b.size(); col++) {
	for (int row = 0; row < b.size(); row++) {
	  if (tilePredicate.test(b.tile(col, row))) {
        return true;
      }
    }
  }
  return false;
}
```

