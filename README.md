<div align="center">

  # I2C-Bit-Bang

</div>

<div align="center">

### Software I2C master for ARM Versatile PB (QEMU)

</div>

## Table of Contents
 
- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Building](#building)
- [Resources](#resources)

## Overview

A software-only I2C master driver written in C, targeting the ARM926EJ-S processor on the QEMU versatilepb machine. A software slave (an in-memory register bank) stands in for a real I2C device, allowing a full write-then-read-back transaction to be verified in QEMU without any physical hardware.

## Features

- START/STOP conditions, MSB-first byte framing, and ACK/NACK handling
- PL061 GPIO driver with pin-level read, write, and direction control
- PL011 UART driver for serial debug output

## Requirements

- `arm-none-eabi-gcc`
- `qemu-system-arm`
- `make`

## Building

```bash
make clean && make run
```

## Resources

- [I2C Specification — NXP UM10204](https://www.nxp.com/docs/en/user-guide/UM10204.pdf)
- [ARM Versatile PB Technical Reference Manual](https://www.qemu.org/docs/master/system/arm/versatile.html)
- [ARM PL061 GPIO Technical Reference Manual](https://developer.arm.com/documentation/ddi0190/b/)
- [ARM PL011 UART Technical Reference Manual](https://developer.arm.com/documentation/ddi0183/g/)
- [ARM926EJ-S Technical Reference Manual](https://developer.arm.com/documentation/ddi0198/e/)

## License

This project is licensed under the Apache License 2.0. See the [LICENSE](./LICENSE) file for details.
