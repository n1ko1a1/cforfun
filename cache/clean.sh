#!/bin/bash
root=$1; shift
exts=( "$@" )
for ext in ${exts[@]}; do
  paths=`find $root -name "*$ext*"`
  for entry in ${paths[@]};do
    if [ -f "$entry" ]; then
      rm -f "$entry"
    fi
  done
done