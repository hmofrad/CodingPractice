#!/bin/bash
# (C) Mohammad H. Mofrad <hasanzadeh@cs.pitt.edu>
# Originally downloaded from "https://outflux.net/coccinelle/"
# and change it to save the generated patch file
# RUN: ./para_spatch.sh --sp-file rule.cocci --dir ~/linux-4.7.2  > patch-file

set -e
MAX=$(getconf _NPROCESSORS_ONLN)
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
