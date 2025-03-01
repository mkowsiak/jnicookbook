# recipe № 053 - GetByteArrayElements vs. GetPrimitiveArrayCritical

This sample shows the difference between two calls that access data on `JVM's` heap. These two means of accessing data differ and have their advantages and dissadvantages.

Anyway, you can easily spot the time difference between both:

```
Access via PrimitiveArray
       14.64 real        14.55 user         0.12 sys
Access via ArrayElements
       51.55 real        35.94 user        15.13 sys
```

Results are for accessing 64M table (100x). Input array is copied to output array and values are modified by adding 1 to each element of input.

# Building and running

The easiest way to build and run codes is to clone the repo and run the sample.

    > git clone https://github.com/mkowsiak/jnicookbook.git
    > cd jnicookbook/recipes/recipeNo053
    > make all
    > make test
    > make clean
