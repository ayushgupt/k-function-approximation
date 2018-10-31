unzip $1".zip"
cd $1
make
chmod 777 stepDp
g++ ../checkError.cpp -std=c++11 -o checkError

echo "time taken for case1 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp1.txt > myout1.txt
./checkError ../sampleTestCases/inp1.txt myout1.txt

echo "time taken for case2 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp2.txt > myout2.txt
./checkError ../sampleTestCases/inp2.txt myout2.txt

echo "time taken for case3 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp3.txt > myout3.txt
./checkError ../sampleTestCases/inp3.txt myout3.txt

echo "time taken for case4 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp4.txt > myout4.txt
./checkError ../sampleTestCases/inp4.txt myout4.txt

echo "time taken for case5 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp5.txt > myout5.txt
./checkError ../sampleTestCases/inp5.txt myout5.txt

echo "time taken for case6 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp6.txt > myout6.txt
./checkError ../sampleTestCases/inp6.txt myout6.txt

echo "time taken for case7 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp7.txt > myout7.txt
./checkError ../sampleTestCases/inp7.txt myout7.txt

echo "time taken for case8 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp8.txt > myout8.txt
./checkError ../sampleTestCases/inp8.txt myout8.txt

echo "time taken for case9 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp9.txt > myout9.txt
./checkError ../sampleTestCases/inp9.txt myout9.txt

echo "time taken for case10 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp10.txt > myout10.txt
./checkError ../sampleTestCases/inp10.txt myout10.txt

echo "time taken for case11 :"
/usr/bin/time -f "%e" ./stepDp < ../sampleTestCases/inp11.txt > myout11.txt
./checkError ../sampleTestCases/inp11.txt myout11.txt


head -1 pl.txt
