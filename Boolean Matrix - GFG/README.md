# Boolean Matrix
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a boolean matrix of size RxC where each cell contains either&nbsp;0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its i<sup>th</sup> row and j<sup>th</sup> column will become 1.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input:</strong>
R = 2, C = 2
matrix[][] = {{1, 0},
              {0, 0}}
<strong>Output: </strong>
1 1
1 0 </span>
<span style="font-size:18px"><strong>Explanation:</strong>
Only cell that has 1 is at (0,0) so all 
cells in row 0 are modified to 1 and all 
cells in column 0 are modified to 1.</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input:</strong>
R = 4, C = 3
matrix[][] = {{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}}</span>
<span style="font-size:18px"><strong>Output: </strong>
1 1 1
1 1 1
1 1 1
1 0 0 </span>
<span style="font-size:18px"><strong>Explanation:</strong>
The position of cells that have 1 in
the original matrix are (0,0), (1,0)
and (2,0). Therefore, all cells in row
0,1,2 are and column 0 are modified to 1. </span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You dont need to read input or print anything. Complete the function <strong>booleanMatrix()</strong> that takes the matrix as input parameter and modifies it <strong>in-place</strong>.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(R * C)<br>
<strong>Expected Auxiliary Space:</strong> O(R + C)&nbsp;</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ R, C ≤ 1000<br>
0 ≤ matrix[i][j] ≤ 1</span></p>
 <p></p>
            </div>