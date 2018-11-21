#!/usr/bin/env bash
echo "if you input 'exit' then quit program"
while : 
do
read word
if [ "$word" = "exit" ]
then exit 1
fi
echo "not exit"
done
