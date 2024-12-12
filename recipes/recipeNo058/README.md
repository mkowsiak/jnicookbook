# recipe № 058 - Passing "unsigned long" to JNI

In Java there is no unsigned types. However, it's possible to pass sort of unsigned value as String to JNI and have it parsed there.

Remember to check maximum size. Note that C specification doesn't specify the limit on type. It only specifies the minimum maximum value it has to hold.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo058
    > make all
    > make test
    > make clean
