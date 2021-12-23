# recipe № 051 - How to run Java code from C

This one is a super simple, plain stupid sample. What you can find here is a famous `Hello world!`. This time, `JNI` style. In this sample code I am calling very simple method inside `Java` class - `displayMessage`.

```
public static void displayMessage() {
  System.out.println("Hello from Java");
}
```

Most of the code is related to initializing `JVM`, and then, instantiating the class and calling the method.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipses/recipeNo051
    > make all
    > make test
    > make clean