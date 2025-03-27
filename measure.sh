#!/bin/bash

# measure.sh [initial n] [measure points] [mode: {lin1: n++, linn:n+=n_0, exp:n*=2}] [mode: {best, worst, random}]

n=6
if [[ $# -gt 0 ]]; then
    n=$1
fi

points=10
if [[ $# -gt 1 ]]; then
    points=$2
fi

mode="lin1"
if [[ $# -gt 2 ]]; then
    mode=$3
fi

case="random"
if [[ $# -gt 3 ]]; then
    case=$4
fi

step=$n

printf "length,timedyv,timedir,ratio\n"

TIMEFORMAT='%6U';

i=1
while [ $i -le $points ]
do
    ./generador $n $case > /tmp/test
    timedyv=$(bash -c "TIMEFORMAT='%6U'; time cat /tmp/test | ./proyecto-cpp -dyv" 2>&1 1>/dev/null)
    timedir=$(bash -c "TIMEFORMAT='%6U'; time cat /tmp/test | ./proyecto-cpp -dir" 2>&1 1>/dev/null)

    ratio=$(echo "scale=6; $timedyv/$timedir" | bc -l)

    printf "$n,$timedyv,$timedir,$ratio\n"

    if [ "$mode" == "lin1" ]; then
        ((n++))
    elif [ "$mode" == "linn" ]; then
        ((n+=step))
    elif [ "$mode" == "exp" ]; then
        ((n*=2))
    fi

    ((i++))
done


