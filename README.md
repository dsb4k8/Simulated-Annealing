# Simulated-Annealing
This problem is similar to the "Hospitals and Residents Problem" .


The goal of this program find the optimum configuration of lab assignments such that the average disutility for a array of 100 students is minimized. In otherwords, perform the most egalitarian lab assignments with considetration of 100 student's individual lab  preferences.

This problem involves the incremental evolution of an array of 100 students. All students have listed their lab preferences in a string with their most preferred lab at index 0 and their least perferred lab at index 4. By finding the average utility of an arbitrary solution and comparing it with the utility of a slightly altered second solution, the agent determines the likelihood that a given solution will be accepted.

Utility is determined by taking the proposed lab assignment and finding it's position in the preferences string provided by the student. This value is then squared to give the individual utility of the assignment. Utility scores closer to 0 are preferred to higher ones. Squaring the result ensures that assigning 2 people to their second choice of labs is evaluated as a better configuration than assigning one student to their first choice of lab at the expense of assigning another student to their third choice

To illustrate :

2+2 == 1+3 

But 

(2^2 + 2^2) < (1^2 + 3^2) 



Logic:
	
-As the value of T drops, the agent becomes more restrictive of which maladaptive new solutions will be accepted.

-With enough time, the probability of acceptance of a less optimal solution approaches asymptotically towards 0.

# Understanding the Output

Each line represents the net disutility of 100 students caused by swapping 2 indexes

For each line: 

I have included the most recently accepted utility score. If this score was ignored, it will simply read "Skipped".

To the right of the accepted score or "Skipped" score, I display the retrospective probability of this score acceptance occuring.

The last field's display on the far left depends on whether or not the given newly proposed score was accepted.

If it was accept, it simply shows the current value of temperature T in the equation e^(-(s2-s1)/T).

If it was skipped, it shows the attempted replacement score and the current best.
