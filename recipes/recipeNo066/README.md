# recipe № 066 - How to embeed JDK inside macOS application

This one is a super simple, plain stupid sample. What you can find here is a famous `Hello world!`. This time, `JNI` style. In this sample code I am calling very simple method inside `Java` class - `displayMessage`.

```
public static void displayMessage() {
  System.out.println("Hello from Java");
}
```

Most of the code is related to initializing `JVM`, and then, instantiating the class and calling the method. `main` method is written in `Objective-C`.

# Final structure of the `recipeNo066.app`

In this sample, I am generating macOS based application. So, what you get at the end is something like this:

```
recipeNo066-redux.app
`-- Contents
    |-- MacOS
        `-- recipeNo066                  - executable
    `-- Resources
        |-- jvm                          - JVM generated using jlink
        |   |-- bin
        |   |-- conf
        |   |   `-- security
        |   |       `-- policy
        |   |           |-- limited
        |   |           `-- unlimited
        |   |-- include
        |   |   `-- darwin
        |   |-- legal
        |   |   `-- java.base
        |   `-- lib
        |       |-- jli
        |       |-- security
        |       `-- server
        `-- target
            `-- recipeNo066              - Java classes
```

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo066
    > make all
    > make test
    > make clean
