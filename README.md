I'm trying to write an operating system myself. It runs!

Run:
====
Install Dependencies:
---------------------
Perform the steps outlined in setup - be warned that this can take a while

If you're feeling adventurous, you can just run the script and it should work. However, this is deemed not recommended because it downloads and runs code over an untrusted connection.

Build:
------
```tup init; tup```

Run:
----
```qemu-system-i386 -kernel os.bin```
