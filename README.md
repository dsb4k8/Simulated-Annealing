# Simulated-Annealing
Solving a lab designation problem such that the net disutility for a set of 100 students is minimized.

Solved minimization problem using simulated annealing.
This problem involves the incremental evolution of a list of 100 students. All students have listed out their lab preferences in order. By finding the average utility of an arbitrary solution and comparing it with the utility of a slightly altered second solution, the agent determines the likelihood that a given solution will be accepted.
	Logic:
	-As the value of T drops, the agent becomes more restrictive of which maladaptive new solutions will be accepted.
	-With enough time, the probability of acceptance of a less optimal solution approaches asymptotically towards 0.
