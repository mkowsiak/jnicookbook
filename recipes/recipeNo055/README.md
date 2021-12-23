# recipe № 055 - Unboxing primitive types - multiple methods

This sample shows how to unbox values inside JNI code. It is based on simple JNI methods of shape

```
public static native void passBoolean(Boolean obj);
public static native void passByte(Byte obj);
public static native void passCharacter(Character obj);
public static native void passFloat(Float obj);
public static native void passInteger(Integer obj);
public static native void passLong(Long obj);
public static native void passShort(Short obj);
public static native void passDouble(Double obj);
```

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo055
    > make all
    > make test
    > make clean
