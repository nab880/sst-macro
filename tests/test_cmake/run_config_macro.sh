#!/bin/bash
SSTMAC_CONFIG=1 cmake -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_CXX_COMPILER=sst++ -DCMAKE_C_COMPILER=sstcc ./