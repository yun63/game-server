#!/bin/bash
grep path .gitmodules | awk '{ print $3 }' > /tmp/git-submodules-dirs

for line in `cat /tmp/git-submodules-dirs` 
do
    echo $line
    (cd ./$line && git checkout master && git pull)
done 

