### Optional

"Hey I might not have a value here, so you have to be prepared to handler that situation.”

Optional are really intended to **only be used as a return type**, where without optional, your method has the possibility on returning null.

```java
private static Optional<Cat> findCatByName(String name) {
    Cat cat = new Cat(name, 3);
    return Optional.ofNullable(cat);
}

private static Optional<Cat> findCatByName(String name) {
    Cat cat = new Cat(name, 3);
    return Optional.empty();
}
```

```java
public static void main(String[] args) {
    Optional<Cat> optionalCat = findCatByName("Fred");
    
    optionalCat.get(); // return the value that insides the optional
    // optional里为空时，get()会NoSuchElementException
    optionalCat.isPresent();
    optionalCat.orElse(new Cat("UNKNOWN", 0)); // 括号里是empty时的default
    optionalCat.orElseGet(); // 括号里是supplier，lambda表达式
    optionalCat.orElseThrow(); // get()的替代

    optionalCat.map(Cat::getAge) // take cat optional and transform into an optional of another type
        .orElse(0); 
}
```