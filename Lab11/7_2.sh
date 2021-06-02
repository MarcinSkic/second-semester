#! /bin/bash
./forkScript &
while true
do
    pgrep forkScript
    sleep 1
done