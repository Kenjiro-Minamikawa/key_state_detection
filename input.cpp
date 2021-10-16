/* input.c */

#include <cassert>
#include <fcntl.h>
#include <linux/input.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <string>
#include <vector>

std::vector<std::string> state = {"up\n", "down\n", "pressing\n"};


int main(void)
{
  int fd = open("/dev/input/event3", O_RDWR);
  assert(fd != -1);

  for (;;) {
    struct input_event event;
    assert(read(fd, &event, sizeof(event)) == sizeof(event));
    //printf("tv_sec: %lu, type: %04x, code: %04x, value: %08x\n", event.time.tv_sec, event.type, event.code, event.value);
    //printf("type: %04x, code: %04x, value: %08x\n", event.type, event.code, event.value);

    if(event.type == EV_KEY){
        switch(event.code){
            case KEY_A:
                std::cout << "a : " << std::endl;
                std::cout << state[event.value];
                break;
            case KEY_W:
                std::cout << "w : " << std::endl;
                std::cout << state[event.value];
                break;
            case KEY_S:
                std::cout << "s : " << std::endl;
                std::cout << state[event.value];
                break;
            case KEY_D:
                std::cout << "d : " << std::endl;
                std::cout << state[event.value];
                break;
                //printf("type: %04x, code: %04x, value: %08x\n", event.type, event.code, event.value);

            //default:
                //std::cout << "hoge" << std::endl;
        }
    }
    //fflush(stdout);
  }
  close(fd);
}

