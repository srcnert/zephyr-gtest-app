## Getting Started
This project is prepared to use GoogleTest platform with Zephyr RTOS.
To support googletest platform on Zephyr RTOS, two files, gtest.cc and gtest-port.h, 
must be updated. I prepared two example projects which are calculator and
random_generator. It is possible to run these on mps2/an385 board or real hw.

### Initialization
```shell
# Initialize workspace
west init -m https://github.com/srcnert/zephyr-gtest-app zephyr-gtest-workspace
# Update modules
cd zephyr-gtest-workspace
west update
```