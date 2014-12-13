I'm trying to write an operating system myself. It runs!

Run:
====
Install Dependencies:
---------------------
Perform the steps outlined in setup - be warned that this can take a while

If you're feeling adventurous, you can just run the script and it should work. However, this is deemed not recommended because it downloads and runs code over an untrusted connection.


Get started:
------------
```tup init; tup
qemu-system-i386 -kernel os.bin```


Full Setup:
-----------
```tup init; tup variant configs/\*.config```

Then:
```tup
qemu-system-i386 -kernel build-default/os.bin #Will run the OS
qemu-system-i386 -kernel build-test/os.bin #Will run the test suite as well```

To skip building the test suite, instead run ```tup build-default```
Or to skip building the normal operating system, run ```tup build-test```
