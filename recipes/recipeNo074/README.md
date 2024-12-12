# recipe № 074 - Passing errno via JNI routine's arguments

This sample illustrates how to "return" `errno` value via `JNI` routine's arguments. In this sample we pass two additional objects into routine: `errnoValue` (AtomicInteger) and `errnoString` (StringBuilder) - both mutable. Inside `JNI` based code (in case of error) we alter values of these objects such way they reflect values of `errno` and `strerror(errno)` - once returned to `Java`.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipeNo074
    > make all
    > make test
    > make clean
