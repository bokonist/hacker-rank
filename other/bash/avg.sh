#https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average
#!/bin/bash    
sum=0
read n #number of inputs
while read -r line || [[ -n "$line" ]]; do #while a line is read and it is not EOF
    sum=$(($sum + $line))
done
printf "%.3f" $(echo "scale=10; $sum/$n" | bc -l) #use bc to handle floating points in bash