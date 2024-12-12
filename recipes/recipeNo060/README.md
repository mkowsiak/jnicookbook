# recipe № 060 - How to run Java code (with Log4j) from C

This time, I am calling Java code that depends on Log4J. Inside JNI based code we have to make sure to point to the jar file we depend on.

```
public class Main {

  private static final Logger logger = LogManager.getLogger("Main");

  public static void displayMessage() {
    logger.info("Hello from Java");
  }
}
```

Most of the code is related to initializing `JVM`, and then, instantiating the class and calling the method.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo060
    > make all
    > make test
    > make clean
