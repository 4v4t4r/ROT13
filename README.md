# ROT13

__ROT13__ is a simple application that takes cleartext and implements the [ROT13](https://en.wikipedia.org/wiki/ROT13) substitution cipher. 

## Introduction

__ROT13__ is a variance of the ancient Caesar cipher, and was developed during the newsgroup days as a method of obscurity for content. It is not an actual encryption standard used in modern day systems, but it provides a great approach towards algorithmic
and critical thinking.

## How to use

    git clone https://github.com/ex0dus-0x/ROT13
    cd ROT13 && make
    ./rot13 test.txt

This application ensures that any non-alphabetical character is replaced to whitespace. 

You can specify a different cipher if you wish. Simply append it at the end of your input

    ./rot13 test.txt 15

Of course, as a person with interests in cybersecurity, I encourage you all to reverse engineer this. I'm not the best at writing secure C code, being someone accustomed to modern systems programming languages with much more type safety. Still, I really like C's performance, and I learn quite a lot about the Linux Kernel.

Have fun!