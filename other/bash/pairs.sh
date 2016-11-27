#https://www.hackerrank.com/challenges/lonely-integer-2
#!/bin/bash
read n
xor=0
read ip
inputs=$(echo $ip | tr " " "\n")
for ips in $inputs 
do
	xor=$(( ips ^ xor ))
done
printf "%d" $(echo $xor)