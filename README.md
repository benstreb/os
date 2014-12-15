I'm trying to write an operating system myself. It runs!

Run:
====
Install Dependencies:
---------------------
Install the binutils cross-compiler, following the steps outlined in setup (up until it starts mentioning gcc). If you'd rather build using gcc, follow all the steps in setup and swap the cc= line in the Tupfile. Make sure to add your new cross-compiler to your PATH.

Note that although setup is a shell script, it is not recommended that you just run it. It is preferred that you go through the steps manually to ensure that everything works.

Install qemu

Build:
------
```tup init; tup```

Run:
----
```qemu-system-i386 -kernel os.bin```


Full Setup:
-----------
```tup init; tup variant configs/\*.config```

Then:
```tup
qemu-system-i386 -kernel build-default/os.bin #Will run the OS
qemu-system-i386 -kernel build-test/os.bin #Will run the test suite as well```

To skip building the test suite, instead run ```tup build-default```
Or to skip building the normal operating system, run ```tup build-test```

