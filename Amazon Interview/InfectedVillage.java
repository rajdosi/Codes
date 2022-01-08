/*

Q. Village Problem. 

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 1 1 1 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 1 2 0 0 0 0 0 0 0 
0 1 1 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 1 2 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

0 0 0 1 
0 0 2 0  
0 1 2 0


infectedArea = {1,2}


days = 1

affectedPersons queue:
[1,3], [0,2], [2,2]

--------
[1,2] - [1,1], [1,3], [0,2], [2,2]

// Area 1 Healthy and we have to check whether 
//any member of the area is connected to a infected person.

3-Area 

0 -> empty space. 
1 -> heathy person
2 -> infected person. 

infection characteristics-
a. can transfer human to human
b. doesn't transfer via air. 
c. once a person get infected, it develops anti-bodies for that virus. 
d. if a person is infected, it can spread the infection further to its adjacent neighbours in one day. 

I/P : Village Grid. 
O/P : Number of days it will take so that whole village has developed anti-bodies (or in a way whole village is infected). 
*/


public int getDaysCount(int[][] input) 
{
	Queue<Pair<Integer, Integer>> infectedQueue = new Queue<>();
	Set<Pair<Integer, Integer>> uninfectedSet = new HashSet<>();

	for (int i = 0; i < input.length; i++) {
		for (int j = 0; j < input[i].length; j++) {
			if (input[i][j] == 2) {
				infectedQueue.enqueue(new Pair<>(i, j));
			}
			eles if (input[i][j] == 1) {
				uninfectedSet.add(new Pair<>(i, j));
			}
		}
	}


	infectedPostion.enqueue(new Pair<>(-1,-1));
	return calculateMaxDays(input, infectedQueue, uninfectedQueue);
}

private int calculateMaxDays(int[][] input, Queue<Pair<Integer, Integer>> infectedQueue, Set<Pair<Integer, Integer>> uninfectedSet)
{
	int days = 0;
	while (infectedQueue.size() != 0) {
		if (uninfectedSet.size() == 0) {
		 	break;
		}

		Pair<Integer, Integer> infectedPosition = infectedQueue.dequeue();
		if (infectedPosition.getRight() == -1 && infectedPosition.getLeft() == -1) {
			infectedPosition.enqueue(new Pair<>(-1, -1));
			days++;
			continue;
		}

		int x = infectedPosition.getLeft();
		int y = infectedPosition.getRight();

		if (x + 1 < input.length) {
			if (y + 1 < input[y - 1].length) {
				if (input[x + 1][y + 1] == 1) {
					input[x + 1][y + 1] = 2;
					infectedPosition.push(new Pair(x + 1, y + 1));
					uninfectedSet.remove(new Pair<>(x + 1, y + 1));
				}
			}
			else if (y - 1 >= 0) {
				if (input[x + 1][y - 1] == 1) {
					input[x + 1][y - 1] = 2;
					infectedPosition.push(new Pair(x + 1, y - 1));
					uninfectedSet.remove(new Pair<>(x + 1, y - 1));
				}	
			}
		}
		else if (x - 1 >= 0) {
			if (y + 1 < input[y - 1].length) {
				if (input[x - 1][y + 1] == 1) {
					input[x - 1][y + 1] = 2;
					infectedPosition.push(new Pair(x - 1, y + 1));
					uninfectedSet.remove(new Pair<>(x - 1, y + 1));
				}
			}
			else if (y - 1 >= 0) {
				if (input[x - 1][y - 1] == 1) {
					input[x - 1][y - 1] = 2;
					infectedPosition.push(new Pair(x - 1, y - 1));
					uninfectedSet.remove(new Pair<>(x - 1, y - 1));
				}	
			}
		}
	}

	// Not Possible as some islands can't be infected 
	if (uninfectedSet.size() > 0) {
		return -1;
	} 

	return days;
}
