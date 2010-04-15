import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		while (in.hasNext()) {
			String temp;
			BigInteger rst = BigInteger.valueOf(0);
			while(true) {
				temp = in.next();
				BigInteger a = new BigInteger(temp);
				if (a.compareTo(BigInteger.ZERO) == 0)
					break;
				rst = rst.add(a);
			}
			System.out.println(rst.toString());
			if(in.hasNext())
				System.out.println();
		}
	}
}