# k-function-approximation
You are required to implement "function approximation" dynamic programming algorithm that was discussed in the class (Section 5.4 of the draft).
## Input format
&lt;k&gt;  &lt;errorType&gt;  
&lt;number Of Input Points&gt;  
&lt;point_x1&gt; &lt;point_y1&gt;  
&lt;point_x2&gt; &lt;point_y2&gt;  
&lt;point_x3&gt; &lt;point_y3&gt;  
.  
.  
.  
&lt;point_xN&gt; &lt;point_yN&gt;  

The first line gives 2 integers, the number of levels allowed in the step-function and type of error function  
The second line contains number of points (say N)  
The next N lines contains space seperated value of x-coordinate and y-coordinate of the points  
errorType will be one of the two integers (0: Mean Squared Error; 1: Max Error)  
## Output format
The first line of output should contain number of levels in your step function(say S)  
Next S lines should contain space seperated values of x-coordinate and y-coordinate of step  

## Points to Note
- X-coordinate of points in the input file will be strictly increasing  
- X-coordinate of points in the output should also be strictly increasing
- Suppose your step function contains 3 points (s1_x,s1_y),(s2_x,s2_y),(s3_x,s3_y); This means your step function's value is s1_y for \[s1_x,s2_x), s2_y for \[s2_x,s2_y) and s3_y for \[s3_x,infinity)
- So, you need to take care that step function should be defined from the smallest x-coordinate in input
- You should write only one DP that calls two different error functions to compute the best k-step approximation
- Correctness of your output will be checked by seeing you output error wrt. minimum error for that testcase.

## Submission Instructions
- Create a zip file with all your source code, "Makefile" file and pl.txt
- pl.txt should just contain the language of source code.(C,C++,Java,Python,etc)
- The make file should compile your source code (in case it needs any compilation, otherwise it may be empty)
- Name your zip file in the following format: <entry no>.zip. (Example: 2018MCS0001.zip)
- name of your executable should be **stepDp**
- Submission needs to be done on Moodle
  
## Check if Submission Zip file is in correct format
- You can check whether your zip file is in required format using the check script which will run your submission on sample test-cases using the below steps
  - Clone/Download this repository to your local machine 
  - Give executing permission to 'getErrorOfCorrectSolutions.sh' and 'runSampleCases.sh' (using chmod)
  - See the expected errors for Sample Inputs using **"sh getErrorOfCorrectSolutions.sh"**
  - Copy paste your zip file (say 2018MCS0001.zip) to this directory
  - Run your zip file code using **"sh runSampleCases.sh 2018MCS0001"(runSampleCasesJava.sh for Java)**
- **There's a penalty of 20% for submissions in improper format. So, do check using above script before submitting.**
- **If your Zip format is correct, then running "sh 2018MCS001(your entry number)" will give you an output similar to**  
  #############START_OUTPUT###################  
    *time taken for case1 :  
    0.46  
    Mean Squared Error: 0  
    time taken for case2 :  
    0.46  
    Mean Squared Error: 78438.4  
    time taken for case3 :  
    1.26  
    Mean Squared Error: 78887.9  
    time taken for case4 :  
    0.51  
    Mean Squared Error: 0  
    time taken for case5 :  
    0.53  
    Max Error: 0  
    time taken for case6 :  
    0.47  
    Max Error: 0  
    time taken for case7 :  
    0.45  
    Max Error: 285  
    time taken for case8 :  
    0.47  
    Max Error: 467  
    time taken for case9 :  
    1.94  
    Max Error: 497  
    time taken for case10 :  
    6.17  
    Max Error: 4965.5  
    time taken for case11 :  
    29.37  
    Max Error: 4813.5   
    Python/C++/Java*    
  #############END_OUTPUT###################



## Explanation of error and output step format
Suppose Input points are:
**(1,4),(3,3),(5,5),(7,1)**

Consider a non-optimal output being as follows:  
**3  
1 5  
3 2  
5 4**    
This corresponds to the step function as represented in image below:  
<img src="https://github.com/ayushgupt/k-function-approximation/blob/master/stepImage.jpg?raw=true" width="500">  
Distances of input points for wrt. above step function are
**d1=1,d2=1,d3=1,d4=3**

Now if input asks for 
- Max Error
  - Error = max(d1,d2,d3,d4) = 3
- Mean Squared Error
  - Error = mean(d1<sup>2</sup>,d2<sup>2</sup>,d3<sup>2</sup>,d4<sup>2</sup>) = 12/4 = 3




