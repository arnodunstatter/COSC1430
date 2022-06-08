#Compile the code
# if the file calculate exits then remove it
program=main
group=3
#                    
#parameter1=(0 1 4 5)
#parameter2=(0 0 3 2)
#parameter3=(0 0 3 4)
timeout="1s"
for i in `seq 1 1 3`; do
    if [ -f output${group}${i}.txt ]; then
        rm output${group}${i}.txt
    fi
    if [ -f ${i}.diff ]; then
	rm ${i}.diff
    fi
    if [ -f ${i}.stdeer ]; then
	rm ${i}.stderr
    fi
    if [ -f ${i}.stdcout ]; then
	rm ${i}.stdcout
    fi
done

if [ -f ${program} ]; then
    rm ${program}
fi
g++ -std=c++11 *.cpp -o ${program}
# if the file densemult does not exit then exit the test
if [ ! -f ${program} ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
# For test case 1
# input 1.txt and output 1.out
for i in `seq 1 1 3`; do
  #echo -e "timeout -k $timeout $timeout ./${program} ${parameter1[$i]} ${parameter2[$i]} 1>$i.stdcout 2>$i.stderr"
	timeout -k $timeout $timeout ./${program} input=input${group}${i}.txt output=output${group}${i}.txt 1>$i.stdcout 2>$i.stderr
	# compare 1.out with 1.ans, output the difference to 1.diff
	diff -iEBwu ans${group}$i.txt output${group}$i.txt > $i.diff
	# if diff returns nothing, it means you pass the test case (Your ourput file 1.out is correct)
	if [ $? -ne 0 ]; then
	    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
	    echo -e "Test case $i    \033[1;91mFAILED.\033[0m"
	else
	    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
	    echo -e "Test case $i    \033[1;92mPASSED.\033[0m"
 	   # remove the file 1.diff
 	    rm -f $i.diff
      rm -f $i.stderr
	fi
done


# For test case 2
# input2.txt and output2.out
#./${program} "input=input${group}2.txt;command=command${group}2.txt;output=output${group}2.txt" 1>2.stdcout 2>2.stderr
# compare 1.out with 1.ans, output the difference to 1.diff
#diff -iEBwu ans${group}2.txt output${group}2.txt > 2.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 1.out is correct)
#if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
#    echo -e "Test case 2    \033[1;91mFAILED.\033[0m"
#else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
#    echo -e "Test case 2    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
#    rm -f 2.diff
#fi
# For test case 3
# input 3.txt and output 3.out
#./${program} "input=input${group}3.txt;command=command${group}3.txt;output=output${group}3.txt" 1>3.stdcout 2>3.stderr
# compare 1.out with 1.ans, output the difference to 1.diff
#diff -iEBwu ans${group}3.txt output${group}3.txt > 3.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 1.out is correct)
#if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
#    echo -e "Test case 1    \033[1;91mFAILED.\033[0m"
#else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
#    echo -e "Test case 1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
#    rm -f 3.diff
#fi


