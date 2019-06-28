#!/bin/bash

read A

case $A in
Y | y ) echo -n "YES";;
N | n ) echo -n "NO";;
esac
