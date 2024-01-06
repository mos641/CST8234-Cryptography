#!/bin/sh

#
# acceptance test script for Caesar Cipher
# Version: 4
# @author Gerald.Hurdle@AlgonquinCollege.com
#

for unit_test in ./unit_tests/unit_test_*.txt; do
    echo $unit_test
    if [ $unit_test = "./unit_tests/unit_test_2.txt" ]; then
        ./cc_decrypt < $unit_test
    elif [ $unit_test = "./unit_tests/unit_test_4.txt" ]; then
        ./cc_decrypt < $unit_test
    elif [ $unit_test = "./unit_tests/unit_test_6.txt" ]; then
        ./cc_decrypt < $unit_test
    else
        ./cc_encrypt < $unit_test
    fi
    echo " "
done

exit 0
