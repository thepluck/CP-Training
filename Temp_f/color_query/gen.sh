#!/usr/bin/bash

build "color_query_gen_balance"
build "color_query"

cnt=40
# ./color_query_gen_random 296156349 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 198436037 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 943019820 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 838431286 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 406720358 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 61706557 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 928661995 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 890229365 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 637332236 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 625638793 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 125353656 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 429040441 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 723971309 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 868677873 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 77613358 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 19916064 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 839781171 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 328084208 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 845335723 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 67293131 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 995033130 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 491526705 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 294244775 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 956597629 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 443471503 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 871004192 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 958291396 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 522936918 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 952480497 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_random 404730432 > "tests/test${cnt}.in"
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 352044900 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 29725650 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 242223010 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 21629569 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 475649000 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 101249688 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 45065764 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 31092250 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 762568262 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
# ./color_query_gen_kill 351660890 > tests/test${cnt}.in
# ./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
# (( cnt++ ))
./color_query_gen_balance 841463482 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 318973830 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 125890471 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 374737299 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 689907778 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 70369261 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 303464471 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 932695239 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 421973282 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))
./color_query_gen_balance 127184693 > tests/test${cnt}.in
./color_query < "tests/test${cnt}.in" > "tests/test${cnt}.out" 
(( cnt++ ))

