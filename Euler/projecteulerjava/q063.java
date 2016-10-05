package projecteulerjava;

import static java.lang.Math.ceil;
import static java.lang.Math.pow;

public class q063 {

	public static void main(String a[]) {
		Integer result = 0;
		Integer x = 0;
		Integer power = 1;
		while (x<10){
			x = (int)ceil(pow(10,(power-1.0)/power));
			result += 10 - x;
			power++;
		}
		System.out.println("Result : " + result);
	}
}
