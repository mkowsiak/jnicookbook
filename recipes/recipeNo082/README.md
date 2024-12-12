# recipe № 082 - Simple `Hello world!` application with ASan enabled

This one is a super simple, plain stupid sample. What you can find here is a famous `Hello world!`. This time, `JNI` style. In this sample code I am calling very simple method inside `C` based shared library  - `displayMessage`.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo082
    > make all
    > make test
    > make test_asan
    > make clean
