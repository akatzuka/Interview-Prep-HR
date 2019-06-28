#!/bin/bash

read A

printf "%.3f\n" `echo $A | bc -l`
