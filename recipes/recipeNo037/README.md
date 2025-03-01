# recipe № 037 - Passing HashMap to C code via JNI

This sample presents how to pass `HashMap` from Java to C via JNI.

It's little bit messy as we need to look for classes, methods, objects, etc.

And we need to descent from top to bottom piece, by piece.

I think that it's way better to use jobjectArrays instead and pass two arrays instead of
one HashMap.

To compile the code run

    make clean
    make 
    make test


