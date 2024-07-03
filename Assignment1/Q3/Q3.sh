#!/bin/bash
# mkdir Result 2> "/dev/null"
(cd Result 2> "/dev/null")||(mkdir  Result)
> "Result/output.txt"
while read x y o ; do
    if [ "$o" = "xor" ] 
    then
        z=$(($x ^ $y))
    elif [ "$o" = "product" ]
    then 
        z=$(($y*$x))
    elif [ "$o" = "compare" ]
    then
        if [ $x -gt $y ]
        then
            z=$x
        else
            z=$y
        fi
    else
        z=$((0))
    fi
    echo "Resut of $o is -> $z" >> "Result/output.txt"
done < "input.txt"