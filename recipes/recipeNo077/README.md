# recipe № 077 - Passing null as method argument inside JNI

It's perfectly possible to pass `null` into `Java` method inside `JNI` based code. All you have to do is to use `NULL`.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo077
    > make all
    > make test
    > make clean
