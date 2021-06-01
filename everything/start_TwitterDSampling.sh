#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
TwitterDSampling_Path="${PWD}/TwitterDSampling/"

./TwitterDSampling/TwitterDSampling ${Data_Path} ${TwitterDSampling_Path} >> ${TwitterDSampling_Path}output.out
