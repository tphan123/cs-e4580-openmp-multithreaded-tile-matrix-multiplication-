#!/usr/bin/env python3

from ppcgrader.cli import cli
import ppci8mm

if __name__ == "__main__":
    cli(
        ppci8mm.Config(code='i8mm_cpu_fast',
                       gpu=False,
                       openmp=True,
                       vnni=False,
                       turing=False))
