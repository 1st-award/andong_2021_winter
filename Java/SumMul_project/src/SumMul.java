import java.util.Scanner;

public class SumMul {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("정수값 : ");
		int num = sc.nextInt();
		int sum = calcMul(num);
		
		System.out.println("1부터 " + num + "까지의 곱은 "  + sum + "입니다.");
	}
	
	public static int calcMul(int _num) {
		int sum = 1;
		for(int i = 1; i <= _num; ++i) {
			sum *= i;
		}
		return sum;
	}
}
