I'm trying to write an operating system myself. It runs!

Run:
====
Install Dependencies:
---------------------
Perform the steps outlined in setup - that this will take a while

If you're feeling adventurous, you can just run the script and it should work. However, this is deemed not recommended because it downloads and runs code over an untrusted connection.

Build:
------
```tup upd```

Run:
----
```qemu-system-i386 -kernel os.bin```
