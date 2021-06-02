#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
GetD_Path="${PWD}/getDistances/
./getDistances/make_byte_matrix ${Data_Path} >> ${GetD_Path}output.out