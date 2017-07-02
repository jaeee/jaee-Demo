#########################################################################
# File Name: procbar.sh
# Author: liumin
# mail: 1106863227@qq.com
# Created Time: Sun 02 Jul 2017 09:21:46 AM CST
#########################################################################
#!/bin/bash

num=0
str='#'
max=100
pro=('|' '/' '-' '\')
while [ $num -le $max ]
do
	((colour=30+num%8))
	echo -en "\e[1;"$colour"m"
	let index=num%4
	printf "[%-100s %d%% %c]\r" "$str" "$num" "${pro[$index]}"
	let num++
	sleep 0.1
	str+='#'
done
printf "\n"
echo -e "\e[1;30;m"



