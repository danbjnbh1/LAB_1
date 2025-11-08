FROM --platform=linux/amd64 ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# 32-bit toolchain on amd64
RUN dpkg --add-architecture i386 && \
    apt-get update && apt-get install -y \
      gcc \
      g++ \
      gcc-multilib \
      g++-multilib \
      libc6-dev-i386 \
      make \
      gdb \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /lab