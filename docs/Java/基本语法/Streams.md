### Streams

#### 1. 定义

```java
List<Person> people = getPeople();
```

```java
// Imperative approach
List<Person> females = new ArrayList<>();
for (Person person : people) {
    if (person.getGender().equals(Gender.FEMALE)) {
        female.add(person);
    }
}
females.forEach(System.out::println);
```

```java
// Declarative approach - Filter
List<Person> females = people.stream()
    .filter(person -> person.getGender().equals(Gender.FEMALE)) // filter takes a predicate, which simply returns true or false
    .collect(Collectors.toList());
```

```java
// Declarative approach - Sort
List<Person> sorted = people.stream()
    .sorted(Comparator.comparing(Person::getAge))
    .collect(Collectors.toList());

List<Person> sorted = people.stream()
    .sorted(Comparator.comparing(Person::getAge).reversed())
    .collect(Collectors.toList());

List<Person> sorted = people.stream()
    .sorted(Comparator.comparing(Person::getAge).thenComparing(Person::getGender).reversed())
    .collect(Collectors.toList());
```

```java
// Declarative approach - All match
boolean allMatch = people.stream()
    .allMatch(person -> person.getAge() > 5);

// Any match
boolean allMatch = people.stream()
    .anyMatch(person -> person.getAge() > 5);

// None match
boolean noneMatch = people.stream()
    .noneMatch(person -> person.getName().equals("Antonio"));
```

```java
// Declarative approach - Max
people.stream()
    .max(Comparator.comparing(Person::getAge))
    .ifPresent(System.out::println);

// Declarative approach - Min
people.stream()
    .min(Comparator.comparing(Person::getAge))
    .ifPresent(System.out::println);
```

```java
// Declarative approach - Group
Map<Gender, List<Person>> groupByGender = people.stream()
    .collect(Collectors.groupingBy(Person::getGender));
groupByGender.forEach((gender, people1) -> {
    System.out.println(gender);
    people1.forEach(System.out::println);
})
```

```java
Optional<String> oldestFemaleAge = people.stream()
    .filter(person -> person.getGender().equals(Gender.FEMALE))
    .max(Comparator.comparing(Person::getAge))
    .map(Person::getName);
oldestFemaleAge.ifPresent(System.out::println);
```

#### 2. Demo in UCB CS 61B Project 0

```java
private static Coordinate[] getAdjacentCoordinates(Tile tile, int size) {
  Coordinate[] coordinates = Coordinate.of(new int[][] {
    {tile.col() - 1, tile.row()}, {tile.col() + 1, tile.row()},
    {tile.col(), tile.row() - 1}, {tile.col(), tile.row() + 1}
  });
  return Arrays.stream(coordinates).filter(coordinate ->
    coordinate.col >= 0 && coordinate.col < size
      && coordinate.row >= 0 && coordinate.row < size).toArray(Coordinate[]::new);
}
```

