# recipe № 033 - running simple "Hello world!" code

This sample code shows difference between JNI/JNA call and Process based call to C code.

Simply call make, then you can test every solution all together

    make test

or you can run them separatelly

    make testprocess
    make testjni
    make testjna

If you want to set number of iterations to value other than 44 just use RECIPE_NO_033_ITER=some_number. Where does this number (44) come from, anyway? Remember the slogan "Made in Poland with love and passion" ;) You will find the origin, I belive in you.

    make testjni RECIPE_NO_033_ITER=1000
    make testprocess RECIPE_NO_033_ITER=10000
    make testjna RECIPE_NO_033_ITER=1

Don't pass negative numbers or some meaningless values like `RECIPE_NO_033_ITER=I_h4Ck3d_7h3_C0D3` as I don't care about error checking ;)

