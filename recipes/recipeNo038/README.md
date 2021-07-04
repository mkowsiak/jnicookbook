# recipe № 038 - Passing HashMap to C code via JNI

This sample presents how to pass `HashMap` from Java to C via JNI.

This time, we pass keys and values via jobjectArray. This way
we don't have to deal with all these calls to HashMap.

To compile the code run

    make 
    make test
    make clean


