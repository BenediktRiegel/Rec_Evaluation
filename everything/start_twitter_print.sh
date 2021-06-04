#!/bin/sh

Data_Path="${PWD}/Data/Twitter/"
Print_Path="${PWD}/Twitter_byte_sample_print/"

./Twitter_byte_sample_print/Twitter_byte_sample_print ${Data_Path} ${Print_Path} 10 0 500 >> ${Print_Path}byte_sample_twitter_print.out &
