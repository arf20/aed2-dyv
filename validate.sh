#!/bin/bash

i=1

if [[ $# -eq 1 ]]; then
    i=$1
fi

while :
do
    test=$(./generador $i)
    printf "$i "
    outdyv=$(echo $test | ./proyecto-cpp -dyv)
    outdir=$(echo $test | ./proyecto-cpp -dir)

    if [ "$outdyv" != "$outdir" ]; then
        printf "bad\n"
        printf "============== DEBUG INFO ==============\n"
        printf "test: $test\n\ndyv:\n$outdyv\n\ndir:\n$outdir\n\n"
        printf "dyv_exp:\n"
        echo $test | ./proyecto-cpp_exp
        printf "============ END DEBUG INFO ============\n"
    else
        printf "ok\n"
    fi
    ((i++))
done

