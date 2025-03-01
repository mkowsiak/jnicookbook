# recipe № 061 - passing std::map<std::string, std::string> from C++ to Java

In this sample, I will pass map of strings: `std::map<std::string, std::string>` to Java, using `HashMap<String, String>`. It's a little bit cumbersome task.

First of all, we have to create `HashMap` object. Then, for each pair inside `C++ - map` I have to extract values and embed them inside `java.lang.String`. Once I have it, I can call `put` method from `HashMap`. However, getting there will require few dozens of JNI based calls.

What I want to call from `C++` looks like this:

```
public class Main {

  public static void displayMap(HashMap<String, String> map) {
    ...
    ...
  }
}
```

Most of the `C++` code is related to initializing `JVM`, instantiating `HashMap` class, transfering data from `std::map` to `java.util.HashMap` and calling `Main.displayMap` method.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo061
    > make all
    > make test
    > make clean
