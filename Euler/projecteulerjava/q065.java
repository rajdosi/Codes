package projecteulerjava;

import java.math.BigInteger;

public class q065 {

	public static Integer digitSum(BigInteger d) {

		Integer sum = 0;
		char[] str = d.toString().toCharArray();

		for (int i = 0; i < str.length; i++) {
			sum += str[i] - '0';
		}

		return sum;
	}

	public static void main(String a[]) {

		BigInteger a1 = BigInteger.valueOf(2L);
		BigInteger a0 = BigInteger.valueOf(1L);

		for (int i = 2; i <= 100; i++) {

			BigInteger c = a0;
			Integer temp = Integer.valueOf((i % 3 == 0) ? 2 * i / 3 : 1);
			a0 = a1;
			a1 = a1.multiply(BigInteger.valueOf(temp));
			a1 = a1.add(c);
		}

		System.out.println("Result : " + digitSum(a1));
	}
}
