# recipe № 056 - Unboxing primitive types - one method

This sample shows how to unbox values inside JNI code. This time, type checking is done inside JNI code. This is why we have one native method

```
public static native void passBoxedValue(Object obj);
```

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo056
    > make all
    > make test
    > make clean
