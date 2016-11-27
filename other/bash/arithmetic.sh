#!/bin/bash
read expression
printf "%.3f" $(echo "scale = 3; $expression " | bc -l)