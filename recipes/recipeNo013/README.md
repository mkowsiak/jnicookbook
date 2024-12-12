# recipe № 013 - 0 vs. JNI_COMMIT vs. JNI_ABORT

This sample is the illustration of passings changes back to `Java` from `C` after you have changed the array content. Be careful with `0` vs. `JNI_COMMIT` vs. `JNI_ABORT` while calling `Release...ArrayElements`. Take a look here: [JDK-8258185](https://bugs.openjdk.java.net/browse/JDK-8258185), and here [Release...ArrayElements Routines](https://docs.oracle.com/en/java/javase/14/docs/specs/jni/functions.html#releaseprimitivetypearrayelements-routines).

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo013
    > make all
    > make test
    > make clean
