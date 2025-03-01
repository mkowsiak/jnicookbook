# recipe № 001 - Simple `Hello world!` application

This one is a super simple, plain stupid sample. What you can find here is a famous `Hello world!`. This time, `JNI` style. In this sample code I am calling very simple method inside `C` based shared library  - `displayMessage`.

```
JNIEXPORT void JNICALL Java_recipeNo001_redux_HelloWorld_displayMessage
  (JNIEnv * env, jclass obj) {

  printf ("Hello world!\n");

}
```

As you can see, it's quite esoteric right from the start. The syntax you can see above is just a matter of convention. You can find it at [Oracle's pages](https://docs.oracle.com/en/java/javase/12/docs/specs/jni/index.html).

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo001
    > make all
    > make test
    > make clean
