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
## Output format
The first line of output should contain number of levels in your step function(say S)  
Next S lines should contain space seperated values of x-coordinate and y-coordinate of step  

# Points to Note
- X-coordinate of points in the input file will be strictly increasing  
- X-coordinate of points in the output should also be strictly increasing
- Suppose your step function contains 3 points (s1_x,s1_y),(s2_x,s2_y),(s3_x,s3_y); This means your step function's value is s1_y for [s1_x,s2_x), s2_y for [s2_x,s2_y) and s3_y for [s3_x,infinity)
- So, you need to take care that step function should be defined from the smallest x-coordinate in input
