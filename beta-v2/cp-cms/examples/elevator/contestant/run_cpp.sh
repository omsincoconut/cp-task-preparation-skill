#!/bin/bash

task="elevator"
memory=65536 # 64 MB
stack_size=65536  # 64 MB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${task}"
