#!/bin/bash
# (C) 2016 Mohammad H. Mofrad <hasanzadeh@cs.pitt.edu>
# Originally downloaded from "https://outflux.net/coccinelle/"
# and modified to save the generated patch file
# RUN: ./para_spatch.sh --sp-file rule.cocci --dir ~/linux-X.Y.Z  > patch-file

MAX=$(nproc)
dir=$(mktemp -d)

for i in $(seq 0 $(( MAX - 1)) ); do
    spatch --mod-distrib --timeout 0 --max $MAX --index $i --very-quiet "$@" > $dir/$i.out &
done

wait
cat $dir/*.out

if [ "$i" = $((MAX - 1)) ]; then
    rm -f $dir/*.out
    rmdir $dir
fi
