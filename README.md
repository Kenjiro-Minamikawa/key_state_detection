You can observe a,w,s,d key's state(up, down, pressing) on Linux.

You need to adjust event number, line 17 input.c.

```
int fd = open("/dev/input/event3", O_RDWR);
```

Change the number event? to your computer's key event file.

Just compile `g++ input.cpp`.

When you excecute this program, you need sudo permission.(due to get key state information from /dev/input/event?)

`sudo ./a.out`
