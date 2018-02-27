# Simulated-Annealing
This problem is similar to the "Hospitals and Residents" problem.

This solves a lab designation problem such that the average disutility for a array of 100 students is minimized.

This problem involves the incremental evolution of an array of 100 students. All students have listed out their lab preferences in order. By finding the average utility of an arbitrary solution and comparing it with the utility of a slightly altered second solution, the agent determines the likelihood that a given solution will be accepted.

Logic:
	
-As the value of T drops, the agent becomes more restrictive of which maladaptive new solutions will be accepted.

-With enough time, the probability of acceptance of a less optimal solution approaches asymptotically towards 0.
