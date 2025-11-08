#!/bin/bash
# Minimal dev launcher for Lab 1 (gcc -m32 + gdb)
set -e

docker build --platform linux/amd64 -t lab-1 -f dockerfile .

docker run --platform linux/amd64 -it --rm \
  --cap-add=SYS_PTRACE \
  --security-opt seccomp=unconfined \
  -v "$(pwd):/lab" \
  -w /lab \
  lab-1 \
  bash