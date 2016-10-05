package projecteulerjava;

import static java.lang.Math.sqrt;

public class q064 {

	public static class Triplet {
		public Integer x, b, c;

		public Triplet(Integer x, Integer b, Integer c) {
			this.x = x;
			this.b = b;
			this.c = c;
		}

		@Override
		public boolean equals(Object o) {
			if (o == null)
				return false;
			else if (!(o instanceof Triplet))
				return false;
			else {
				Triplet trip = (Triplet) o;
				return (trip.x.equals(x) && trip.b.equals(b) && trip.c
						.equals(c));
			}
		}
	}

	public static void main(String a[]) {
		Integer result = 0;
		for (int i = 2; i <= 10000; i++) {

			Integer p = 0;
			Integer a0 = (int) sqrt(i);
			if (a0 * a0 == i) {
				continue;
			}

			Integer b = 1;
			Integer c = 0;
			Integer x = a0;

			do {
				c = x * b - c;
				b = (i - c * c) / b;
				x = (a0 + c) / b;
				p++;
			} while (x != 2 * a0);
			if (p % 2 == 1)
				result++;
		}

		System.out.println("result : " + result);
	}
}
