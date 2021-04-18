// https://leetcode.com/problems/network-delay-time/

class Solution {
    
    public int networkDelayTime(int[][] times, int N, int K)
    {
        // handle edge cases
        // for one node there is no network delay
        if (N == 1) {
            return 0;
        }

        // for times routes are less than nodes which means we can't connect all roads
        if (times.length < N - 1) {
            return -1;
        }

        // prepare adjacency matrix
        int[][] matrix = new int[N][N];
        for (int i = 0; i < times.length; i++) {
            matrix[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }

        Set<Integer> visited = new HashSet<>();
        List<Integer> queue = new ArrayList<>();
        int[] timeDelay = new int[N];

        queue.add(new Integer(K));

        while (queue.size() > 0) {
            int index = queue.size() - 1;
            int next = queue.get(index);
            queue.remove(index);
            
            System.out.println(next);
            
            if (!visited.contains(next)) {
                visited.add(next);
            }

            for (int i = 0; i < N; i++) {
                if (matrix[next - i] == 0) {
                    continue;
                }
                
                if (timeDelay[i] > matrix[next - 1][i]) {
                    timeDelay[i] = timeDelay[next - 1] + matrix[next - 1][i];
                }

                if (!visited.contains(i)) {
                    queue.add(i);
                }
            }
        }

        if (visited.size() != N) {
            return -1;
        }

        int max = -1;
        for (int i = 0; i < N; i++) {
            if (timeDelay[i] > max) {
                max = timeDelay[i];
            }
        }

        return max;
    }

    private Map<int, int[2]> prepareAdjacencyMatrix(int[][] times, int N) {
    	Map<int, int[2]> matrix = new HashMap<>();
    	for (int i = 0; i < times.length; i++) {
    		if ()
    		matrix.put();
    	}

    	return matrix;
    }

    private int[] dfs(int N) {
    	int[] distance = new int[N];
    	for () {

    	}
    	return distance;
    }
}